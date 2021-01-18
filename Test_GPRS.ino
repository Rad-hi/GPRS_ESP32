#include "GPRS.h"

#define GPRS_SETUP_STEPS       4

unsigned long GPRS_last_sent = 0;
const unsigned long GPRS_setup_delays [] = {0, 1000, 3000, 0, 1000}; // milliseconds
int GPRS_setup_step = 0;
bool GPRS_ready = false;

void setup() {
  Serial.begin(115200);
  do{
    //each step of the GPRS setup requires a different delay period,
    //so I made a table that contains the delay period, where its index
    //in the table corresponds to the right step 
    if(GPRS_setup_step < GPRS_SETUP_STEPS
      && (millis() - GPRS_last_sent >= GPRS_setup_delays[GPRS_setup_step])){
        
        ///////////////////////////////////////////////////////////////
        /////         Info for setup steps confirmation           /////  
        ///////////////////////////////////////////////////////////////
        switch(GPRS_setup_step){
          case 1:{
            Serial.println("Step 0: done, serial connection activated!");
            break;
          }
          case 2:{
            Serial.println("Step 1: done, initializing modem...");
            break;
          }
          case 3:{
            Serial.println("Step 2: done, modem: " + modem.getModemInfo());
            Serial.println("Waiting for network...");
            break;
          }
          case 4:{
            Serial.println("Step 3: done, Connecting...");
            break;
          }
        }
        ///////////////////////////////////////////////////////////////
        
        GPRS_init(GPRS_setup_step++);
        GPRS_last_sent = millis();
    }
    
    //if we finished all our steps, but the modem still couldn't connect
    //we reboot, otherwise, we declare the GPRS ready
    if(!GPRS_ready && GPRS_setup_step == GPRS_SETUP_STEPS
      && (millis() - GPRS_last_sent >= GPRS_setup_delays[GPRS_setup_step])){
        if(!modem.isGprsConnected()){
          Serial.println("Rebooting");
          ESP.restart(); //Reboot
        }
        else{
          GPRS_ready = true;
        }
    }
  }while(!GPRS_ready);
}

unsigned long last_check = 0;

void loop() {
  if(modem.isGprsConnected()){
    if(millis() - last_check >= 10000L){ //we check each 10 seconds if we're still connected or nah !
      Serial.println("Connected!");
      last_check = millis();
    }
  }
  else{
    Serial.println("Fail.\nRebooting!"); //if we lost connection, we reboot !
    ESP.restart();
  }
}
