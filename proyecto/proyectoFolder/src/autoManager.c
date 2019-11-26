#include "sapi.h"
#include "menuMEF.h"
#include "rtcManager.h"
uint16_t autoPercentage = 0;
uint16_t autosetPercentage = 0;
uint16_t hourOrMin = 0;
uint16_t autoMinPercentage = 0;
uint16_t autoMinSetPercentage = 0;
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
uint16_t getHourOrMin(void){
	return hourOrMin;
}
uint16_t getHour(){
	return autoPercentage;
}
uint16_t getMin(){
	return autoMinPercentage;
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
	lcdGoToXY(0,0);
	lcdSendStringRaw( "SUCESO" );
	delay(2000);
	changeStateMenu(3);
}