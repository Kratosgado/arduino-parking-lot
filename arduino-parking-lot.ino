#include <Servo.h>
#include "ParkingLot.hpp"

ParkingLot parkingLot;

void setup() {
  ParkingArgs parkingArgs;
  parkingLot = ParkingLot(parkingArgs);
}

void loop() {
  parkingLot.intialize();
}