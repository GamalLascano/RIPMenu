#include "sapi.h" 

enum menuState {OSD,MENU,DIRECT,TIMER,AUTO};
menuState estado;
const char humChar[8] = { 
   0b00100,
   0b00100,
   0b01110,
   0b10111,
   0b10111,
   0b10011,
   0b01110,
   0b00000
};
int main (void){
	boardConfig();
	estado=OSD;
	lcdInit( 16, 2, 5, 8 );
	lcdCreateChar( 0, humChar );
	while(TRUE){
		switch(estado){
			case OSD:
			break;
			case MENU:
			break;
			case DIRECT:
			break;
			case TIMER:
			break;
			case AUTO:
			break;
		}
	}
}
