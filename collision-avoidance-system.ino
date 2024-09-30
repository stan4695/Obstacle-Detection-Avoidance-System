// Initializing Pins
// Sensor Pins
#define triggerPinLeft 2
#define echoPinLeft 3
#define triggerPinCentral 4 // This is the pin that will output a high frequency signal for the central sensor
#define echoPinCentral 5 // This is the pin that will read the reflected signal for the central sensor
#define triggerPinRight 11
#define echoPinRight 12

// Motors Pins
// These pins are connected to the base terminals of BJT's to control the flow of current that reaches the motors
#define leftMotor 10 // We are using pin number 10 to control the left motor
#define rightMotor 9 // ... and pin number 9 to control the right motor

// Motor Speed
#define motorSpeed 150

void setup() {
  Serial.begin (9600); // Setting the BaudRate for the serial monitor
  // Specifying how each pin will be used
  pinMode(triggerPinLeft, OUTPUT);
  pinMode(echoPinLeft, INPUT);
  pinMode(triggerPinCentral, OUTPUT);
  pinMode(echoPinCentral, INPUT);
  pinMode(triggerPinRight, OUTPUT);
  pinMode(echoPinRight, INPUT);
  pinMode(leftMotor, OUTPUT);
  pinMode(rightMotor, OUTPUT);
}

void loop() {
  float frontalDistance = getDistance(triggerPinCentral, echoPinCentral); // check the distance in front
  if (frontalDistance < 20) { // If the frontal distance to an obstacle is under 20 cm, than the car will stop and check the surroundings
    stop();
    delay(2000);
    float leftDistance = getDistance(triggerPinLeft, echoPinLeft); // check the distance to the left
    float rightDistance = getDistance(triggerPinRight, echoPinRight); // check the distance to the right
    if (leftDistance >= 20 || rightDistance >= 20) { // If there are enough space in the left or right side, the car will turn in that direction
      if (leftDistance > rightDistance) { // Compare the distances and make a decision
        turnLeft();
      } else {
        turnRight();
      }
    } else {
      turnAround(); // Make a 180 degrees turn, when it's not enough space to the right or left side
    }
  } else {
    moveForward(); // When there are no obstacles, the car will go forward
  }
}

float getDistance(int triggerPin, int echoPin) {
  float duration, distance;
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);

  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) * 0.0344; //distance = (variable time/2) x speed of sound
  return distance;
}

void printDistance() {
  // A function used in the debugging stage to check the accuracy of the sensors, and the correctness of the decisions made
  Serial.print("LEFT: ");
  Serial.println(getDistance(triggerPinLeft, echoPinLeft));
  Serial.print("CENTER: ");
  Serial.println(getDistance(triggerPinCentral, echoPinCentral));
  Serial.print("RIGHT: ");
  Serial.println(getDistance(triggerPinRight, echoPinRight));
  Serial.println("");
}

void moveForward() {
  analogWrite(leftMotor, motorSpeed);
  analogWrite(rightMotor, motorSpeed);
}

void turnLeft() {
  analogWrite(leftMotor, 0);
  analogWrite(rightMotor, motorSpeed);
  delay(300);
}

void turnRight() {
  analogWrite(rightMotor, 0);
  analogWrite(leftMotor, motorSpeed);
  delay(300);
}

void turnAround() {
  analogWrite(leftMotor, motorSpeed);
  analogWrite(rightMotor, 0);
  delay(1000);
}

void stop() {
  analogWrite(leftMotor, 0);
  analogWrite(rightMotor, 0);
}
