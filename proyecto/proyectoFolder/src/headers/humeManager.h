#ifndef HUMEMANAGER_H_
#define HUMEMANAGER_H_
	void menuHum(uint16_t refresh);
	void incrementHum(void);
	void decrementHum(void);
	uint16_t getHumPercentage(void);
	void setPercentage(void);
	void checkHumedad(uint16_t Sensor);
#endif