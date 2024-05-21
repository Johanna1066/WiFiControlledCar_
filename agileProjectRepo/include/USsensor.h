#pragma once
//------USSensor---------

class USsensor
{
private:
    int sensorTriggerPIN;
    int sensorRecieverPIN;

    long distance{};
    long messurement{};

public:
    USsensor(int triggerPIN, int recieverPIN)
    {
        sensorTriggerPIN = triggerPIN;
        sensorRecieverPIN = recieverPIN;
        this->initiateUSsensor();
    }

    void initiateUSsensor()
    {
        pinMode(sensorTriggerPIN, OUTPUT);
        pinMode(sensorRecieverPIN, INPUT);
    }

    ~USsensor()
    {
        /*
        delete sensorTriggerPIN;
        delete sensorRecieverPIN;

        delete distance;
        */
    }

    long getDistance()
    {
        return distance;
    }

    void readDistance()
    {
        // TODO: Can we remove or change theese delays in some way?
        // We don't want to hard code in delays
        digitalWrite(sensorTriggerPIN, LOW);
        delay(5);
        digitalWrite(sensorTriggerPIN, HIGH);
        delay(10);
        digitalWrite(sensorTriggerPIN, LOW);

        pinMode(sensorRecieverPIN, INPUT);

        messurement = pulseIn(sensorRecieverPIN, HIGH);

        distance = (messurement / 2) / 29.1; // Convert distance to cm
    }

    // IDEA: Setup subscription function
};
