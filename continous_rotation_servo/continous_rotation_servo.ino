#include <Servo.h>
#define SERVO 6

Servo myservo;
char rxChar = 0;

void setup() {
  Serial.begin(9600);
  Serial.flush();
}

void loop() {
  if (Serial.available() > 0) {
    rxChar = Serial.read();
    Serial.flush();

    switch (rxChar) {
      case 'w':
      case 'W':
        myservo.attach(SERVO);
        myservo.write(78);
        delay(500);
        myservo.detach();
        break;

      case 's':
      case 'S':
        myservo.attach(SERVO);
        myservo.write(102);
        delay(500);
        myservo.detach();
        break;

      default:
        Serial.print("'");
        Serial.print((char)rxChar);
        Serial.println("' is not a command!");
    }
  }
}
