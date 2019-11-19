#include "sapi.h" 
#include "ClockOSD.h" 
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
#define BUTTON_LOGIC BUTTON_ONE_IS_UP
#if BOARD==edu_ciaa_nxp
	#define BUTTON0 TEC1
	#define BUTTON1 TEC2
	#define BUTTON2 TEC3
	#define BUTTON3 TEC4
#else
	#error You must select a valid board!
#endif
uint16_t SoilSensor;
float moist;
char * medida;
uint32_t osdint = 0;
uint32_t menuInt = 0;
uint32_t menuRefreshInt = 1;
int main (void){
	boardConfig();
	estado=OSD;
	lcdInit( 16, 2, 5, 8 );
	lcdCursorSet( LCD_CURSOR_OFF );
	lcdCreateChar( 0, humChar );
	adcConfig( ADC_ENABLE );
	delay_t refreshButton;
    delay_t refreshButtonEvents;
    delayInit( &refreshButton, 20 );
    delayInit( &refreshButtonEvents, 10 );
    button_t boton0;
    button_t boton1;
    button_t boton2;
    button_t boton3;
	buttonInit( &boton0,                  // Button structure (object)
               BUTTON0, BUTTON_LOGIC,       // Pin and electrical connection
               50,                          // Button scan time [ms]
               TRUE,                        // checkPressedEvent
               FALSE,                       // checkReleasedEvent
               TRUE,                        // checkHoldPressedEvent
               5000,                        // holdPressedTime [ms]
               0,                           // pressedCallback
               0,                           // releasedCallback
               0                            // holdPressedCallback
    );
	buttonInit( &boton1,                  // Button structure (object)
               BUTTON1, BUTTON_LOGIC,       // Pin and electrical connection
               50,                          // Button scan time [ms]
               TRUE,                        // checkPressedEvent
               FALSE,                       // checkReleasedEvent
               TRUE,                        // checkHoldPressedEvent
               5000,                        // holdPressedTime [ms]
               0,                           // pressedCallback
               0,                           // releasedCallback
               0                            // holdPressedCallback
    );
	buttonInit( &boton2,                  // Button structure (object)
               BUTTON2 BUTTON_LOGIC,       // Pin and electrical connection
               50,                          // Button scan time [ms]
               TRUE,                        // checkPressedEvent
               FALSE,                       // checkReleasedEvent
               TRUE,                        // checkHoldPressedEvent
               5000,                        // holdPressedTime [ms]
               0,                           // pressedCallback
               0,                           // releasedCallback
               0                            // holdPressedCallback
    );
	buttonInit( &boton3,                  // Button structure (object)
               BUTTON3, BUTTON_LOGIC,       // Pin and electrical connection
               50,                          // Button scan time [ms]
               TRUE,                        // checkPressedEvent
               FALSE,                       // checkReleasedEvent
               TRUE,                        // checkHoldPressedEvent
               5000,                        // holdPressedTime [ms]
               0,                           // pressedCallback
               0,                           // releasedCallback
               0                            // holdPressedCallback
    );  
	while(TRUE){
		SoilSensor = adcRead( CH1 );
		moist = SoilSensor / 10.23;
		moist = 100 - moist;
		myftoa(moist,medida,0);
		if( delayRead(&refreshButton) ) {
         buttonFsmUpdate( &boton0 );
         buttonFsmUpdate( &boton1 );
         buttonFsmUpdate( &boton2 );
         buttonFsmUpdate( &boton3 );
        }
		switch(estado){
			case OSD:
				lcdClear(); 
				mostrarOSD(medida);
				if( delayRead(&refreshButtonEvents) ) {
					if((buttonEventGet( &boton1 ) == BUTTON_PRESSED)||(buttonEventGet( &boton2 ) == BUTTON_PRESSED)){
						if (buttonEventGet( &boton1 ) == BUTTON_PRESSED){
							buttonEventHandled( &boton1 );
						} else{
							buttonEventHandled( &boton2 );
						}
						if (osdint == 0){
							osdint = 1;
						}else osdint = 0;
					}
					if (osdint==0){
						showAuto();
					}else{
						showTimer();
					}
					if (buttonEventGet( &boton3 ) == BUTTON_PRESSED){
						buttonEventHandled( &boton3 );
						estado = MENU;
					}
				}
				delay(40);
			break;
			case MENU:
				if(menuRefreshInt==1){
					lcdClear();
					showMenu(menuInt);
					menuRefreshInt=0;
				}
				if (delayRead(&refreshButtonEvents)){
					if (buttonEventGet( &boton0 ) == BUTTON_PRESSED){
						buttonEventHandled( &boton0 );
						estado = OSD;
						menuRefreshInt=1;
					}
					if (buttonEventGet( &boton1 ) == BUTTON_PRESSED){
						buttonEventHandled( &boton1 );
						menuInt = menuInt - 1;
						if (menuInt == -1) menuInt = 2;
						menuRefreshInt=1;
					}
					if (buttonEventGet( &boton2 ) == BUTTON_PRESSED){
						buttonEventHandled( &boton2 );
						menuInt = (menuInt + 1) % 3;
						menuRefreshInt=1;
					}
					if (buttonEventGet( &boton3 ) == BUTTON_PRESSED){
						buttonEventHandled( &boton3 );
						changeStateMenu(menuInt);
						menuRefreshInt=1;
					}
				}
			break;
			case DIRECT:
				if(menuRefreshInt==1){
					lcdClear();
					lcdGoToXY( 0, 0 );
					lcdSendStringRaw( "Entraste aca" );
					lcdGoToXY( 0, 1 );
					lcdSendStringRaw( "de vuelta" );
					menuRefreshInt=0;
				}
				if (delayRead(&refreshButtonEvents)){
					if (buttonEventGet( &boton0 ) == BUTTON_PRESSED){
						buttonEventHandled( &boton0 );
						estado = OSD;
						menuRefreshInt=1;
					}
				}
			break;
			case TIMER:
			break;
			case AUTO:
			break;
		}
	}
}
void changeStateMenu(int mInt){
	switch(mInt){
		case 0:
			estado = DIRECT;
		break;
		case 1:
			//estado = TIMER;
			estado = OSD;
		break;
		case 2:
			//estado = AUTO;
			estado = OSD;
		break;
		default:
			estado = OSD;
	}
}
