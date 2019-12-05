#ifndef RTCMANAGER_H_ 
#define RTCMANAGER_H_ 
	void configureRTC(void); 
	void manageRTC(void); 
	void activateTimer(int tim); 
	void activateCooldownTimer(void); 
	bool_t getCDState(void);
    rtc_t getTiempo(void); 
#endif