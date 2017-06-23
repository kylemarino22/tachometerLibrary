#ifndef _tachometer_h_
#define _tachometer_h_

extern int storage[100];
extern int ambientLight;
extern int sensorDelay;

void calibrateTachometer();
float calculateSpeed();
#endif
