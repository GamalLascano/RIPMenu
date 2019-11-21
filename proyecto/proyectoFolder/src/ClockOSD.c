#include "sapi.h" 
#include "humeManager.h"
char stringHume[10];
void mostrarOSD(char * strMoisture){
	lcdGoToXY( 0, 0 ); 
	lcdData(0);
	lcdSendStringRaw( "HUM: " );
	lcdSendStringRaw( strMoisture );
	lcdSendStringRaw( "%       " );
}
void showAuto(void){
	lcdGoToXY( 0, 1 );
	uint64ToString((uint64_t) getHumPercentage(),stringHume,10);
	lcdSendStringRaw( "%HU: " );
	lcdSendStringRaw( stringHume );
	lcdSendStringRaw( "   " );
}
void showTimer(void){
	lcdGoToXY( 0, 1 );
	lcdSendStringRaw( "TMR: " );
	lcdSendStringRaw( "00:00" );
}