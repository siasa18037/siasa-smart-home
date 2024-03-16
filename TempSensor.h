#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 25

// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature.
DallasTemperature sensors(&oneWire);

struct DEV_TempSensor : Service::TemperatureSensor {
    SpanCharacteristic *temp;
    DeviceAddress sensor_address;
    uint32_t timer = 0;

    DEV_TempSensor() : Service::TemperatureSensor() {
        sensors.begin();

        if (!sensors.getAddress(sensor_address, 0)) Serial.println("Unable to find address for Device 0");
        sensors.requestTemperatures();
        float tempC = sensors.getTempC(sensor_address);

        temp = new Characteristic::CurrentTemperature(tempC);
        temp->setRange(-50, 100);

        Serial.println("Configuring Temperature Sensor");
    }

    void loop() {
        if (temp->timeVal() > 5000) {
            sensors.requestTemperatures();
            float tempC = sensors.getTempC(sensor_address);
            // Serial.print(tempC);
            if (abs(temp->getVal<float>() - tempC) > 0.1) {
                temp->setVal(tempC);
            }
        }
    }
};
