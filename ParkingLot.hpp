#if !defined(PARKING_LOT)
#define PARKING_LOT

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

    bool isFull() {}


public:
    ParkingLot(ParkingArgs) {};

    ~ParkingLot();
    void raiseBar();
    void closeBar();
    void intialize();
    void operator=(const ParkingLot&);

};


#endif // PARKING_LOT
