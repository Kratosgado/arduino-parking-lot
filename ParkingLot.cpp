#include "ParkingLot.hpp"

ParkingLot::ParkingLot(ParkingArgs& args) {
    this->maxCars = args.maxCars;
    this->ledPin = args.ledPin;
    this->triggerPin = args.triggerPin;
    this->echoPin = args.echoPin;
    this->servoPin = args.servoPin;

    this->barPos = 0;
};

void ParkingLot::setup() {
    Serial.begin(9600);
    pinMode(this->ledPin, OUTPUT);
    pinMode(this->triggerPin, OUTPUT);
    pinMode(this->echoPin, INPUT);
    this->servo.attach(this->servoPin);
}

void ParkingLot::operator=(const ParkingLot& right) {
    this->barPos = right.barPos;
    this->currentCars = right.currentCars;
    this->echoPin = right.echoPin;
    this->servo = right.servo;
    this->maxCars = right.maxCars;
}

void ParkingLot::listen() {
    digitalWrite(this->triggerPin, LOW);
    delayMicroseconds(2);

    digitalWrite(this->triggerPin, HIGH);
    delayMicroseconds(2);

    digitalWrite(this->triggerPin, LOW);
    delayMicroseconds(10);

    long duration = pulseIn(echoPin, HIGH);
    int distance = (duration * 0.0343) / 2;

    // detect if something is passing
    if (distance + 5 < ROAD_DISTANCE && this->currentCars < this->maxCars) {
        Serial.print("object passing at distance: ");
        Serial.print(distance);
        Serial.print(" cm");
        Serial.print("\n number of cars parked: ");
        Serial.println(currentCars);
        digitalWrite(ledPin, HIGH);
        currentCars += 1;
    }
    else if (this->currentCars == this->maxCars) {
        digitalWrite(ledPin, HIGH);
    }
    else {
        digitalWrite(ledPin, LOW);
    }
    delay(500);
}

void ParkingLot::closeBar() {
    for (this->barPos; this->barPos >= 0; this->barPos++) {
        servo.write(this->barPos);
        delay(15);
    }
}

void ParkingLot::raiseBar() {
    for (this->barPos; this->barPos <= 90; this->barPos++) {
        servo.write(this->barPos);
        delay(15);
    }
}

bool ParkingLot::isFull() {
    return this->currentCars == this->maxCars;
}

ParkingLot::~ParkingLot() {
    //
}