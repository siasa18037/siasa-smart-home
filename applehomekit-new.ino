
#include "HomeSpan.h" 
#include "DEV_RELAY.h"
#include "TempSensor.h"
#include "DEV_Sensors_contact.h" 
#include "MQUnifiedsensor.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);


  homeSpan.begin(Category::Other, "E3 Smart home");

  new SpanAccessory();  
    new Service::AccessoryInformation();
      new Characteristic::Identify(); 

  // TempSensor

  new SpanAccessory();
  new Service::AccessoryInformation();
  new Characteristic::Identify(); 
  new Characteristic::Name("Temp Sensor");
  new DEV_TempSensor();

  // // MQ-2 Sensor
  // new SpanAccessory();
  //   new Service::AccessoryInformation();
  //     new Characteristic::Identify(); 
  //     new Characteristic::Name("Gas Sensor");
  //   new DEV_MQ2Sensor(4);


  //ContactSensor

  
  // new SpanAccessory();
  //   new Service::AccessoryInformation();
  //     new Characteristic::Identify(); 
  //     new Characteristic::Name("ContactSensor1");
  //   new DEV_ContactSensor(5);

  //   new SpanAccessory();
  //   new Service::AccessoryInformation();
  //     new Characteristic::Identify(); 
  //     new Characteristic::Name("ContactSensor2");
  //   new DEV_ContactSensor(18);
  

  // RELAY

  new SpanAccessory();
  new Service::AccessoryInformation();    
  new Characteristic::Identify();
  new Characteristic::Name("Switch1");                   
  new DEV_RELAY(13);  

  new SpanAccessory();
  new Service::AccessoryInformation();    
  new Characteristic::Identify();
  new Characteristic::Name("Switch2");                       
  new DEV_RELAY(12);  

  new SpanAccessory();
  new Service::AccessoryInformation();    
  new Characteristic::Identify();
  new Characteristic::Name("Switch3");                       
  new DEV_RELAY(14);  

  new SpanAccessory();
  new Service::AccessoryInformation();    
  new Characteristic::Identify();
  new Characteristic::Name("Switch4");                       
  new DEV_RELAY(27);  

  new SpanAccessory();
  new Service::AccessoryInformation();    
  new Characteristic::Identify();
  new Characteristic::Name("Switch5");                       
  new DEV_RELAY(26);  



  //switch smoke senser
  // new SpanAccessory();
  // new Service::AccessoryInformation();    
  // new Characteristic::Identify();
  // new Characteristic::Name("Switch on/off Smoke Senser");                       
  // new DEV_RELAY();


  pinMode(5, OUTPUT);
  digitalWrite(5, HIGH);
}


void loop() {
  // put your main code here, to run repeatedly:
  homeSpan.poll();
  


}

