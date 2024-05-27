#pragma once
//------Joystick---------

class Joystick
{
private:
    int joyStickVerticalPIN{};
    int joyStickHorizontalPIN{};
    int joyStickButtonPIN{};

    int verticalValue{};
    int horizontalValue{};
    int buttonValue{};

    int centerHorizontalValue{};
    int centerVerticalValue{};

public:
    Joystick(int verticalPIN, int horizontalPIN, int buttonPIN);

    ~Joystick();

    void initiateJoystick();

    void vertialRead();

    void horizontalRead();

    int getHorizontalValue();

    int getVerticalValue();

    //void buttonRead();   If we are going to use button on joystick

};

Joystick::Joystick(int verticalPIN, int horizontalPIN, int buttonPIN)
{
    joyStickVerticalPIN = verticalPIN;
    joyStickHorizontalPIN = horizontalPIN;
    joyStickButtonPIN = buttonPIN;
    this->initiateJoystick();
}

Joystick::~Joystick()
{
    /*
    delete joyStickButtonPIN;
    delete joyStickHorizontalPIN;
    delete joyStickButtonPIN;

    delete verticalValue;
    delete horizontalValue;
    delete buttonValue;
    */
}

void Joystick::initiateJoystick()
{
    pinMode(joyStickVerticalPIN, INPUT);
    pinMode(joyStickHorizontalPIN, INPUT);
    pinMode(joyStickButtonPIN, INPUT);

    centerHorizontalValue = analogRead(joyStickHorizontalPIN);
    centerVerticalValue = analogRead(joyStickVerticalPIN);


}

void Joystick::vertialRead()
{
    verticalValue = analogRead(joyStickVerticalPIN);
}

void Joystick::horizontalRead()
{
    horizontalValue = analogRead(joyStickHorizontalPIN);
    
    /*
    if((centerHorizontalValue - 100) <= horizontalValue && horizontalValue <= (centerHorizontalValue + 100))
    {
        Serial.println("joystick:horizontalRead X axis center.");
    }
    else if(centerHorizontalValue > horizontalValue)
    {
        Serial.printf("joystick:horizontalRead X axis < centerHorizontalValue. \nX = %d \n", horizontalValue);
    }
    else if(centerHorizontalValue < horizontalValue)
    {
        Serial.printf("joystick:horizontalRead X axis > centerHorizontalValue. \nX = %d \n", horizontalValue);
    }
    delay(500);
    */
}

int Joystick::getHorizontalValue()
{
    //Serial.println(horizontalValue);
    return horizontalValue;
}

int Joystick::getVerticalValue()
{
    return verticalValue;
}

/*Joystick::buttonRead()
    {
        //TODO: if we use the button on Joystick
    }*/