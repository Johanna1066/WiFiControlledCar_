/*
 * steeringFunctions.cpp
 */
#include <Arduino.h>
#include <esp_now.h>
#include <WiFi.h>

#include "steeringFunctions.h"

void setEnginesVelocity(int velocity, bool obsticle)
{
    for (auto &engine : engines)
    {
        engine.setVelocity(velocity, obsticle);
    }
}

void onDataRecv(const uint8_t *mac, const uint8_t *incomingData, int len)
{
    memcpy(&dataRecieved, incomingData, sizeof(dataRecieved));

    if (dataRecieved >= 10000)
    {
        if (xSemaphoreTake(servoHandle, portMAX_DELAY) == pdTRUE)
        {
            dataRecieved -= 10000;

            myServo.setDirection(dataRecieved);
            delay(1);
            xSemaphoreGive(servoHandle);
        }
    }
    else if ((dataRecieved >= 0) && (dataRecieved <= 4096))
    {
        if (xSemaphoreTake(engineHandle, portMAX_DELAY) == pdTRUE)
        {

            setEnginesVelocity(dataRecieved, hinderForwardMovement);
            delay(1);
            xSemaphoreGive(engineHandle);
        }
    }
}

void initiate()
{
    myServo.initiateServo();

    engines.push_back(left);
    engines.push_back(right);

    for (auto &engine : engines)
    {
        engine.intitateEngine();
    }

    mySensor.initiateUSsensor();

    engineHandle = xSemaphoreCreateMutex();
    servoHandle = xSemaphoreCreateMutex();

    if (engineHandle == NULL)
    {
        Serial.println("Error creating engine semaphore");
        return;
    }
    if (servoHandle == NULL)
    {
        Serial.println("Error creating servo semaphore");
        return;
    }

    WiFi.mode(WIFI_STA);

    if (esp_now_init() != ESP_OK)
    {
        Serial.println("Error initializing ESP-NOW");
        return;
    }
    esp_now_register_recv_cb(onDataRecv);
}

void sensorCheck(void *parameters)
{
    for (;;)
    {
        mySensor.USsensor::readDistance();
        reading = mySensor.USsensor::getDistance();

        if (reading < safeServoDistance)
        {
            if (xSemaphoreTake(engineHandle, portMAX_DELAY) == pdTRUE)
            {
                if (!hinderForwardMovement)
                {
                    hinderForwardMovement = true;
                }
                xSemaphoreGive(engineHandle);
            }
        }
        else
        {
            if (xSemaphoreTake(engineHandle, portMAX_DELAY) == pdTRUE)
            {
                if (hinderForwardMovement)
                {
                    hinderForwardMovement = false;
                }
                xSemaphoreGive(engineHandle);
            }
        }
        vTaskDelay(10);
    }
}
