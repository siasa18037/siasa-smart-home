struct DEV_ContactSensor : Service::ContactSensor {                       // Motion sensor

  SpanCharacteristic *movement;                                         // reference to the MotionDetected Characteristic
  int sensorPin;                                                        // pin number of the sensor

  DEV_ContactSensor(int sensorPin) : Service::ContactSensor() {
    
    this->sensorPin = sensorPin;
    pinMode(sensorPin,INPUT);
    int motion = digitalRead(sensorPin);
    boolean state;
    if (motion == 0) state=true; else state=false;
        
    movement=new Characteristic::ContactSensorState(state);                // instantiate the MotionDetected Characteristic

  } // end constructor

  void loop() {
    int motion = digitalRead(sensorPin);
   // Serial.print(motion);
    
    if (motion == 0) movement->setVal(1); else movement->setVal(0);
 //   movement->setVal(motion);
 /*   if (motion != movement->getVal()) {
      movement->setVal(motion);
      if (motion == true) {
        char c[64];
        sprintf(c,"Motion was detected\n");
        LOG1(c);          
      }
    }*/
  }
};
