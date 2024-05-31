// #include <Servo.h>


// int ledPin = 13;
// int triggerPin = 4;
// int echoPin = 2;

// const int servoPin = 9;

// const int ROADDISTANCE = 30;
// const int MAX_CARS = 4;
// int currentCars = 0;

// void setup() {
//   // put your setup code here, to run once:
//   Serial.begin(9600);
//   pinMode(ledPin, OUTPUT);
//   pinMode(triggerPin, OUTPUT);
//   pinMode(echoPin, INPUT);
// }

// void loop() {
//   // put your main code here, to run repeatedly:
//   digitalWrite(triggerPin, LOW);
//   delayMicroseconds(2);

//   digitalWrite(triggerPin, HIGH);
//   delayMicroseconds(2);

//   digitalWrite(triggerPin, LOW);
//   delayMicroseconds(10);

//   long duration = pulseIn(echoPin, HIGH);
//   int distance = (duration * 0.0343) / 2;

//   // detect if something is passing
//   if (distance + 5 < ROADDISTANCE && currentCars < MAX_CARS) {
//     Serial.print("object passing at distance: ");
//     Serial.print(distance );
//     Serial.print(" cm");
//     Serial.print("\n number of cars parked: ");
//     Serial.println(currentCars);
//     digitalWrite(ledPin, HIGH);
//     currentCars += 1;
//   }
//   else if (currentCars == MAX_CARS) {
//     digitalWrite(ledPin, HIGH);
//   }
//   else{
//       digitalWrite(ledPin, LOW);
//   }
//   delay(500);
// }
