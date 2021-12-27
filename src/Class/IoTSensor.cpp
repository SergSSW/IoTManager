#include "Utils/JsonUtils.h"
#include "Utils/SerialPrint.h"
#include "Class/ScenarioClass3.h"
#include "Class/IoTSensor.h"

void IoTSensor::init(String key, String id, unsigned long interval) {
    _interval = interval * 1000;
    _key = key;
    _id = id;
}

IoTSensor::IoTSensor() {}
IoTSensor::~IoTSensor() {}

String IoTSensor::getKey() {
    return _key;
}

String IoTSensor::getID() {
    return _id;
};

void IoTSensor::loop() {
    currentMillis = millis();
    difference = currentMillis - prevMillis;
    if (difference >= _interval) {
        prevMillis = millis();
        SerialPrint("I", "Sensor", "Вызывается loop");
        this->doByInterval();
    }
}

void IoTSensor::regEvent(String value, String consoleInfo = "") {
    eventGen2(_id, String(value));
    jsonWriteStr(configLiveJson, _id, String(value));
    publishStatus(_id, String(value));
    SerialPrint("I", "Sensor", "'" + _id + "' data: " + String(value) + "' " + consoleInfo);
}

void IoTSensor::doByInterval() {}