## Car Control System Project README

# Car Control System Project

This project focuses on controlling a car using an Arduino Nano ESP32. It integrates steering, velocity, obstacle detection, and communication using the ESP-NOW protocol.

## Table of Contents
- [Features](#features)
- [Components](#components)
- [Setup and Installation](#setup-and-installation)
  - [Setup](#setup)
  - [Hardware Requirements](#hardware-requirements)
  - [Software Requirements](#software-requirements)
- [Usage](#usage)
- [Contributing](#contributing)
- [Acknowledgements](#acknowledgements)

## Features
- **Steering Control**: Uses `SteeringServo` objects assigned to specific pins.
- **Velocity and Direction Control**: Uses `Engine` objects assigned to specific pins.
- **Obstacle Detection**: Uses `USsensor` objects to ensure there are no obstacles blocking the car's path.
- **Sensor Data Handling**: Includes tasks for reading and handling sensor data.
- **ESP-NOW Communication**: Receives data from the controller Arduino Nano ESP32 using the ESP-NOW protocol.

## Setup and Installation

### Setup

1. **Clone the Repository**

   git clone [ https://github.com/Johanna1066/WiFiControlledCar_Car/](https://github.com/Johanna1066/WiFiControlledCar_Car)
   
2. **Open the Project in Arduino IDE**
Open the .ino file from the cloned repository in the Arduino IDE.

3. **Install Required Libraries**
Required libraries: esp_now.h, WiFi.h, ESP32Servo.h, and semphr.

4. **Upload the Code**
Connect your Arduino Nano ESP32 to your computer and upload the code.

5. **Download the Controller Repository**
Make sure to download the repository for the controller as well.
[ https://github.com/Johanna1066/WiFiControlledCar_Controller/](https://github.com/Johanna1066/WiFiControlledCar_Controller)


### Hardware Requirements
- Arduino Nano ESP32
- Micro servo x2
- DC motors x2
- Motor dirver
- Ultrasonic Sensor
- Arduino PSU
- Breadboards
- Cables

  
### Software Requirements
- Arduino IDE
- ESP32 board support installed in the Arduino IDE
- Required libraries: `esp_now.h`, `WiFi.h`, `ESP32Servo.h`, and `semphr`


## Usage
Once the setup is complete and the code is uploaded:

1. Power on your Arduino Nano ESP32.
2. The system will initialize the components and start the task for sensor checking.
3. The car's steering and engine will be controlled based on the sensor data and commands received via ESP-NOW from the controller.
## Contributing
Contributions are welcome! Please follow these steps to contribute:

1. Fork the repository.
2. Create your feature branch (git checkout -b feature/AmazingFeature).
3. Commit your changes (git commit -m 'Add some AmazingFeature').
4. Push to the branch (git push origin feature/AmazingFeature).
5. Open a pull request.
## Acknowledgements
Special thanks to John.

For more information, visit the project repository.
