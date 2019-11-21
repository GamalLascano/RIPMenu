#include "sapi.h" 
void mostrarOSD(char * strMoisture){
	lcdGoToXY( 0, 0 ); 
	lcdData(0);
	lcdSendStringRaw( "HUM: " );
	lcdSendStringRaw( strMoisture );
	lcdSendStringRaw( "%       " );
}
void showAuto(void){
	lcdGoToXY( 0, 1 );
	lcdSendStringRaw( "%HU: " );
	lcdSendStringRaw( "00:00" );
}
void showTimer(void){
	lcdGoToXY( 0, 1 );
	lcdSendStringRaw( "TMR: " );
	lcdSendStringRaw( "00:00" );
}