#ifndef AUTOMANAGER_H_ 
#define AUTOMANAGER_H_ 
void menuAuto(uint16_t refresh); 
uint16_t getHourOrMin(void); 
bool_t refreshCounter(void);
uint16_t getHour(void); 
uint16_t getMin(void); 
void incrementAutoMin(void); 
void decrementAutoMin(void); 
uint16_t getAutoMinPercentage(void); 
void incrementAutoHour(void); 
void decrementAutoHour(void); 
uint16_t getAutoHourPercentage(void); 
void setAutoHourPercentage(void); 
void setAutoMinPercentage(void); 
#endif