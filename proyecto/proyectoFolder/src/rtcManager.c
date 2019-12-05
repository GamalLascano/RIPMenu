#include "sapi.h"
int cooldownTimer=0; 
const int cdSetTime=300; 
bool_t activatedCD=0; 
rtc_t tiempoActual; 
rtc_t tiempoPasado; 
void configureRTC(void){ 
	tiempoActual.year= 2019; 
	tiempoActual.month=11; 
	tiempoActual.mday=25; 
	tiempoActual.wday=1; 
	tiempoActual.hour=10; 
	tiempoActual.min=55; 
	tiempoActual.sec=0; 
	rtcWrite(&tiempoActual); 
	tiempoPasado=tiempoActual; 
} 
void manageRTC(void){ 
	rtcRead(&tiempoActual); 
	if((tiempoActual.sec>tiempoPasado.sec)||(tiempoActual.min>tiempoPasado.min)||(tiempoActual.hour>tiempoPasado.hour)||(tiempoActual.month>tiempoPasado.month)||(tiempoActual.year>tiempoPasado.year)){ 
		tiempoPasado=tiempoActual; 
		if(activatedCD==1){ 
			cooldownTimer++; 
			if(cooldownTimer==cdSetTime){ 
				cooldownTimer=0; 
				activatedCD=0; 
			} 
		} 
	} 
}
rtc_t getTiempo(void){
    return tiempoActual;
} 
bool_t getCDState(void){ 
	return activatedCD; 
} 
void activateTimer(int tim){ 
 
} 
void activateCooldownTimer(){ 
	activatedCD=1; 
}