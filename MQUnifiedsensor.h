
struct DEV_MQ2Sensor : Service::SmokeSensor {
    SpanCharacteristic *Smoke;
    int sensorPin;    
    int Smoke_N;

    DEV_MQ2Sensor(int sensorPin) : Service::SmokeSensor() {
      this->sensorPin = sensorPin;
      pinMode(sensorPin,INPUT);
      //int Smoke_N = digitalRead(sensorPin);
      int smoke_analog = analogRead(sensorPin);
      if(smoke_analog > 1000){
        Smoke_N = 0;
      }else{
        Smoke_N = 1;
      }

      boolean Smoke_B ;
      if (Smoke_N == 0) Smoke_B = true; else Smoke_B = false;

      Smoke = new Characteristic::SmokeDetected(Smoke_B);

    }

    void loop() {

      //int Smoke_N = digitalRead(sensorPin);
      int smoke_analog = analogRead(sensorPin);
      Serial.println(smoke_analog);

      if(smoke_analog > 1000){
        Smoke_N = 0;
      }else{
        Smoke_N = 1;
      }
      
      if(Smoke_N == 0){
        Smoke->setVal(1);
      }else {
        Smoke->setVal(0);
      }

       
    }
};
