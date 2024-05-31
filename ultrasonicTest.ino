#include <Servo.h>
#include "ParkingLot.hpp"

ParkingLot parkingLot;

int pos = 0;

void setup() {
  ParkingArgs parkingArgs;
  parkingLot = ParkingLot(parkingArgs);
}

void loop() {
  parkingLot.intialize();
}