#include "sapi.h" 
#include "ClockOSD.h" 
#include "MenuOP.h"
#include "myutils.h"
#include "humeManager.h"
#define BUTTON_LOGIC BUTTON_ONE_IS_UP
#if BOARD==edu_ciaa_nxp
	#define BUTTON0 TEC1
	#define BUTTON1 TEC2
	#define BUTTON2 TEC3
	#define BUTTON3 TEC4
#else
	#error You must select a valid board!
#endif  
typedef enum {OSD,MENU,DIRECT,TIMER,HUME} menuState;
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
uint16_t SoilSensor;
float moist;
char medida[10];
uint32_t osdint = 0;
uint32_t menuInt = 0;
uint32_t menuRefreshInt = 1;
button_t boton0;
button_t boton1;
button_t boton2;
button_t boton3;
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
			estado = HUME;
		break;
		case 3:
			estado = OSD;
		break;
		default:
			estado = OSD;
	}
}


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
               BUTTON2, BUTTON_LOGIC,       // Pin and electrical connection
               50,                          // Button scan time [ms]
               TRUE,                        // checkPressedEvent
               TRUE,                        // checkReleasedEvent
               TRUE,                        // checkHoldPressedEvent
               2000,                        // holdPressedTime [ms]
               0,                           // pressedCallback
               0,                           // releasedCallback
               0                            // holdPressedCallback
             );

   buttonInit( &boton3,                  // Button structure (object)
               BUTTON3, BUTTON_LOGIC,       // Pin and electrical connection
               50,                          // Button scan time [ms]
               TRUE,                        // checkPressedEvent
               TRUE,                        // checkReleasedEvent
               TRUE,                        // checkHoldPressedEvent
               2000,                        // holdPressedTime [ms]
               0,                           // pressedCallback
               0,                           // releasedCallback
               0                            // holdPressedCallback
             ); 
	bool_t valor = 0;
	valor = servoConfig( 0, SERVO_ENABLE );
	valor = servoConfig( SERVO4, SERVO_ENABLE_OUTPUT );
	valor = servoWrite( SERVO4, 180 );
	while(TRUE){
		SoilSensor = adcRead( ADC_CH0 );
		moist = SoilSensor / 10.23;
		moist = 100 - moist;
		floatToString(moist,medida,2);
		if( delayRead(&refreshButton) ) {
         buttonFsmUpdate( &boton0 );
         buttonFsmUpdate( &boton1 );
         buttonFsmUpdate( &boton2 );
         buttonFsmUpdate( &boton3 );
        }
		switch(estado){
			case OSD:
				//lcdClear(); 
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
					if (buttonEventGet( &boton3 ) == BUTTON_PRESSED){
						buttonEventHandled( &boton3 );
						estado = MENU;
					}
				}
				if (osdint==0){
					showAuto();
				}else{
					showTimer();
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
					lcdSendStringRaw( "Presiona aca" );
					lcdGoToXY( 0, 1 );
					lcdSendStringRaw( "para regar" );
					menuRefreshInt=0;
				}
				if (delayRead(&refreshButtonEvents)){
					if (buttonEventGet( &boton0 ) == BUTTON_PRESSED){
						buttonEventHandled( &boton0 );
						buttonEventHandled( &boton3 ); 
						estado = OSD;
						menuRefreshInt=1;
					}
				}
				if (buttonEventGet( &boton3 ) == BUTTON_PRESSED){ 
						buttonEventHandled( &boton3 ); 
						servoWrite( SERVO4, 180 ); 
					} 
				if (buttonEventGet( &boton2 ) == BUTTON_RELEASED){ 
						buttonEventHandled( &boton2 ); 
						servoWrite( SERVO4, 0 ); 
					} 
			break;
			case TIMER:
			break;
			case HUME:
				if(menuRefreshInt==1){
					lcdClear();
					lcdGoToXY( 0, 0 );
					lcdSendStringRaw( "Insertar %HUM" );
					menuHum(menuRefreshInt);
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
						decrementHum();
						menuRefreshInt=1;
					}
					if (buttonEventGet( &boton2 ) == BUTTON_PRESSED){
						buttonEventHandled( &boton2 );
						incrementHum();
						menuRefreshInt=1;
					}
				    if (buttonEventGet( &boton3 ) == BUTTON_PRESSED){
						buttonEventHandled( &boton3 );
						setPercentage();
						menuRefreshInt=1;
					}
				}
			break;
		}
	}
	return 0;
}