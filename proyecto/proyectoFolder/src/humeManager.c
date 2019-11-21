#include "sapi.h"
uint16_t humPercentage = 100;
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