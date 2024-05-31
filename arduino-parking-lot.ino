#include <Servo.h>
#include "ParkingLot.hpp"

ParkingArgs parkingArgs;
ParkingLot parkingLot = ParkingLot(parkingArgs);

void setup() {
  parkingLot.setup();
}

void loop() {
  parkingLot.listen();
}