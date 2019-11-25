#include "sapi.h"
#include "menuMEF.h"
#include "rtcManager.h"
uint16_t humPercentage = 0;
uint16_t humsetPercentage = 0;
char stringMenu[10];
void menuHum(uint16_t refresh){
	if(refresh==1){
		lcdGoToXY( 0, 1 );
		lcdSendStringRaw( "       " );
		uint64ToString((uint64_t) humsetPercentage,stringMenu,10);
		lcdSendStringRaw(stringMenu);
	    lcdSendStringRaw( " " );
	}
}
void incrementHum(void){
	if(humsetPercentage<100){
		humsetPercentage=humsetPercentage+1;
	}
}
void decrementHum(void){
	if(humsetPercentage>0){
		humsetPercentage=humsetPercentage-1;
	}
}
uint16_t getHumPercentage(void){
	return humPercentage;
}
void setPercentage(void){
	lcdClear();
	humPercentage=humsetPercentage;
	humsetPercentage=0;
	lcdGoToXY(0,0);
	lcdSendStringRaw( "SUCESO" );
	delay(2000);
	changeStateMenu(3);
}
void checkHumedad(uint16_t Sensor){
	if(Sensor<humPercentage)&&(getCDState()==0){
		servoWrite( SERVO_N, 180 );
		lcdClear();
		lcdGoToXY(0,0);
		lcdSendStringRaw( "REGANDO" );
		delay(500);
		activateCooldownTimer();
	}
}