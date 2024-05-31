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
    const int ROADDISTANCE = 30;

private:
    int barPos;
     int maxCars;
    int currentCars;
    int ledPin;
    int triggerPin;
    int echoPin;
    Servo servo;


    // private methods
    bool isFull();
    void raiseBar();
    void closeBar();

public:
    ParkingLot() {};
    ParkingLot(ParkingArgs);


    ~ParkingLot();
    void intialize();
    void operator=(const ParkingLot&);

};


#endif // PARKING_LOT
