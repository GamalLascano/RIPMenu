#include "sapi.h"
#include "headers/autoManager.h"
int cooldownTimer=0; 
const int cdSetTime=300; 
bool_t activatedCD=0; 
rtc_t tiempoActual; 
delay_t timeDelay;
void configureRTC(void){ 
	tiempoActual.year= 2019; 
	tiempoActual.month=11; 
	tiempoActual.mday=25; 
	tiempoActual.wday=1; 
	tiempoActual.hour=10; 
	tiempoActual.min=55; 
	tiempoActual.sec=0; 
    delayConfig( &timeDelay, 1000 );
} 
void incrementTime(void){
	tiempoActual.sec++;
	if (tiempoActual.sec>=60){
		tiempoActual.sec=0;
		tiempoActual.min++;
		if (tiempoActual.min>=60){
			tiempoActual.min=0;
			tiempoActual.hour++;
			if(tiempoActual.hour>=24){
				tiempoActual.hour=0;
			}
		}
	}
}
bool_t manageRTC(void){ 
	if( delayRead(&timeDelay) ){
        incrementTime();
		if(activatedCD==1){ 
			cooldownTimer++; 
			if(cooldownTimer==cdSetTime){ 
				cooldownTimer=0; 
				activatedCD=0; 
			} 
		} 
		if (refreshCounter()==1){
			return 1;
		}else return 0;
    } return 0;
}
rtc_t getTiempo(void){
    return tiempoActual;
} 
bool_t getCDState(void){ 
	return activatedCD; 
}  
void activateCooldownTimer(){ 
	activatedCD=1; 
}