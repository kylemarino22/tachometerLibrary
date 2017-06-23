#include "tachometer.h"
#include <Arduino.h>

int storage[100];
int ambientLight;
int sensorDelay = 50;

void calibrateTachometer(int pin){
        int val = 0;
        for (int i = 0; i < 50; i++) {
                val += analogRead(pin);
        }
        ambientLight = val / 50;
}

float calculateSpeed(int pin){
        int val;
        for (int i = 0; i < 100; i++) {
                val = analogRead(pin);
                storage[i] = val;
                delayMicroseconds(sensorDelay);
        }
        int counter = 0;
        int switchLocation = 0;
        int finalLocation = 0;
        while (counter < 99) {
                if (storage[counter] <= (ambientLight + 16) / 2 && storage[counter + 1] > (ambientLight + 16) / 2) {
                        if (switchLocation == 0) {
                                switchLocation = counter;
                        }
                        else {
                                finalLocation = counter - switchLocation;
                                break;
                        }

                }
                counter++;
        }

        Serial.println(finalLocation);
        Serial.println(sensorDelay);
        return (1.0f/((float)finalLocation * ((float)sensorDelay)/ 1000000.0)); //1 / measurement * seconds
}
