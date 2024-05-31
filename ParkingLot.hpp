#if !defined(PARKING_LOT)
#define PARKING_LOT

#include <Arduino.h>
#include <Servo.h>

struct ParkingArgs {
    int maxCars = 10;
    int servoPin = 9;
    int ledPin = 13;
    int triggerPin = 2;
    int echoPin = 4;
};

class ParkingLot {
    const int ROAD_DISTANCE = 30;

private:
    int barPos;
    int maxCars;
    int currentCars;
    int ledPin;
    int triggerPin;
    int echoPin;
    int servoPin;
    int collisions;


    Servo servo;

    // private methods
    bool isFull();
    void raiseBar();
    void closeBar();

    void turnLightOn() {
        digitalWrite(this->ledPin, HIGH);
    }
    void turnLightOff() {
        digitalWrite(this->ledPin, LOW);
    }

public:
    ParkingLot() {};
    ParkingLot(ParkingArgs&);
    ~ParkingLot();

    void setup();
    void listen();
    void operator=(const ParkingLot&);

};

#endif // PARKING_LOT
