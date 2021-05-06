/*
 * I provided a put to sleep function, in case you want to put your ESP32 TTGO TCall Sim800L to sleep
 * And need minimal power consumption. Unfortunately, having the Sim800L module soldered to the board,
 * I couldn't wake up the module correctly since it requires a pin that's not accessible to be toggled
 * BUT I'm successfully putting it to sleep, and restarting the whole module each time i'm waking it up
 * So if you're not connecting to the internet that frequently, this might actually be benefecial, but
 * if you're sleeping and waking up each couple of seconds, this might not be the best option since 
 * the Sim800L needs around 6 seconds to wake up, which is alot!
 */

// Configure your APN in GPRS.h
#include "GPRS.h"

void setup() {
  Serial.begin(115200);

  // This function call sets up the module but in a blocking matter!
  GPRS_wake_up();
  
  if(GPRS_connectivity_status())Serial.println("Connected to cellular network!");
  
  // If you have other modules to set up, you can call GPRS_init()
  // in a conditional loop and put other modules to setup with it 
  // since it actually uses millis() to time its steps, not delays!
  /*
   * Non blocking Setup example:
   * do{
   *    GPRS_init();
   *    
   *    Other_module_init();
   *    
   * }while(gprs_setup_state != GPRS_READY_ 
   *        && not(Other_module_ready_condition) 
   *        && ...)
   */
}

void loop() {
  
  // Do whatever you want with GPRS here
  
}
