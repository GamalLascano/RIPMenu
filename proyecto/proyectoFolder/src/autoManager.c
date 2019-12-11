#include "sapi.h" 
#include "headers/menuMEF.h" 
#include "headers/rtcManager.h" 
uint16_t actualHour = 0;
uint16_t actualMin = 0;
uint16_t actualSeg = 0;
uint16_t autoPercentage = 0; 
uint16_t autosetPercentage = 0; 
uint16_t hourOrMin = 0; 
uint16_t autoMinPercentage = 0; 
uint16_t autoMinSetPercentage = 0; 
uint8_t timerActivated = 0;
char stringMenu[10]; 
void menuAuto(uint16_t refresh){ 
	if(refresh==1){ 
		lcdGoToXY( 0, 1 ); 
		lcdSendStringRaw( "       " ); 
		if (hourOrMin==0){ 
			uint64ToString((uint64_t) autosetPercentage,stringMenu,10); 
			lcdSendStringRaw(stringMenu); 
		}else{ 
			if (hourOrMin==1){ 
				uint64ToString((uint64_t) autoMinSetPercentage,stringMenu,10); 
				lcdSendStringRaw(stringMenu);	 
			} 
		} 
	    lcdSendStringRaw( " " ); 
	} 
} 
bool_t refreshCounter(void){
    if(timerActivated == 1){
        if (actualSeg == 0) {
            if (actualMin == 0){
                if (actualHour == 0){
                    servoWrite( SERVO4, 180 ); 
	            	lcdClear(); 
	            	lcdGoToXY(0,0); 
	            	lcdSendStringRaw( "    REGANDO     " ); 
	            	delay(5000); 
                    actualHour = autoPercentage;
                    actualMin = autoMinPercentage;
                    actualSeg = 0;
                    servoWrite(SERVO4, 0);
                    changeStateMenu(3); 
                    return 1;
                }else {
                    actualHour--;
                    actualMin = 59;
                    actualSeg = 59;
                }
            }else{
                actualMin--;
                actualSeg = 59;
            }
        }else{
            actualSeg--;
        }
        return 1;
    }
    return 0;
}
uint16_t getHourOrMin(void){ 
	return hourOrMin; 
} 
uint16_t getHour(){ 
	return actualHour; 
} 
uint16_t getMin(){ 
	return actualMin; 
} 
uint16_t getSec(){ 
	return actualSeg; 
} 
void incrementAutoMin(void){ 
	if(autoMinSetPercentage<60){ 
		autoMinSetPercentage=autoMinSetPercentage+1; 
	} 
} 
void decrementAutoMin(void){ 
	if(autoMinSetPercentage>0){ 
		autoMinSetPercentage=autoMinSetPercentage-1; 
	} 
} 
uint16_t getAutoMinPercentage(void){ 
	return autoMinPercentage; 
} 
void incrementAutoHour(void){ 
	if(autosetPercentage<99){ 
		autosetPercentage=autosetPercentage+1; 
	} 
} 
void decrementAutoHour(void){ 
	if(autosetPercentage>0){ 
		autosetPercentage=autosetPercentage-1; 
	} 
} 
uint16_t getAutoHourPercentage(void){ 
	return autoPercentage; 
} 
void setAutoHourPercentage(void){ 
	lcdClear(); 
	autoPercentage=autosetPercentage; 
	autosetPercentage=0; 
	hourOrMin=1; 
} 
void setAutoMinPercentage(void){ 
	lcdClear(); 
	hourOrMin=0; 
	autoMinPercentage=autoMinSetPercentage; 
	autoMinSetPercentage=0; 
    if (autoMinPercentage == 0 && autoPercentage == 0){
		timerActivated = 0;
		actualHour = 0;
		actualMin = 0;
		actualSeg = 0;
	} 
    else {
        timerActivated = 1;
        actualHour = autoPercentage;
        actualMin = autoMinPercentage;
        actualSeg = 0;
    }
	lcdGoToXY(0,0); 
	lcdSendStringRaw( "     SUCESO     " ); 
	delay(2000); 
	changeStateMenu(3); 
}