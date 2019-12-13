#include "sapi.h" 
#include "headers/humeManager.h"
#include "headers/rtcManager.h"
#include "headers/autoManager.h"
float moistMax = 0;
char stringHume[10];
void mostrarOSD(char * strMoisture){
	lcdGoToXY( 0, 0 ); 
	lcdData(0);
	lcdSendStringRaw( "HUM: " );
	lcdSendStringRaw( strMoisture );
	lcdSendStringRaw( "%       " );
}
void checkOneSpace(void){
	int i;
    for (i = 0; stringHume[i] != '\0'; ++i);
	if (i<2){
		lcdSendStringRaw( "0" );
	}
}
void showAuto(float moist){
	lcdGoToXY( 0, 1 );
	uint64ToString((uint64_t) getHumPercentage(),stringHume,10);
	lcdSendStringRaw( "%HU: " );
	lcdSendStringRaw( stringHume );
	lcdSendStringRaw( " " );
	if (moist>moistMax) moistMax=moist;
	floatToString(moistMax,stringHume,2);
	lcdSendStringRaw( stringHume );
	//lcdData(1);
	//uint64ToString((uint64_t) getTiempo().hour,stringHume,10);
	//checkOneSpace();
	//lcdSendStringRaw( stringHume );
	//lcdSendStringRaw( ":" );
	//uint64ToString((uint64_t) getTiempo().min,stringHume,10);
	//checkOneSpace();
	//lcdSendStringRaw( stringHume );
	//lcdSendStringRaw( "    " );
}
void showTimer(void){
	lcdGoToXY( 0, 1 );
	lcdSendStringRaw( "TMR: " );
	uint64ToString((uint64_t) getHour(),stringHume,10);
	checkOneSpace();
	lcdSendStringRaw( stringHume ); 
	lcdSendStringRaw( ":" ); 
	uint64ToString((uint64_t) getMin(),stringHume,10); 
	checkOneSpace();
	lcdSendStringRaw( stringHume );
	lcdSendStringRaw( ":" );  
	uint64ToString((uint64_t) getSec(),stringHume,10);
	checkOneSpace(); 
	lcdSendStringRaw( stringHume );
	lcdSendStringRaw( "        " ); 
}