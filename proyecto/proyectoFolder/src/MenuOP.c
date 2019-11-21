#include "sapi.h" 
void showMenu(int menuInt){
	lcdGoToXY( 0, 0 );
	switch(menuInt){
		case 0:
			lcdSendStringRaw( "  MODO DIRECTO" );
		break;
		case 1:
			lcdSendStringRaw( "   MODO TIMER" );
		break;
		case 2:
			lcdSendStringRaw( "MODO HUMEDAD  " );
		break;
	}
}