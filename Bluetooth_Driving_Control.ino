//MECH 4850 Senior Design
//Hybride Drone Project
//Instructor: Angran Xiao
//Sketched by JIN-WOO KIM
//This code made the hybrid drone to be able to control the DC motor with the bluetooth module.

#include <SoftwareSerial.h>  //call SoftwareSerial from Library
#include <Servo.h> //call Servo from Library

Servo Servo1; //Micro Servo SG90
int pos = 0; // variable to store the servo position
SoftwareSerial Bluetooth(3, 4); // Arduino(RX, TX) - HC-05 Bluetooth (TX, RX)
int Servo1ip;
String myString = "";
int input1 = 8; //initialize the port (OUT1)
int input2 = 5; //initialize the port (OUT2)


void setup() {
  pinMode(input1, OUTPUT);
  pinMode(input2, OUTPUT);
  Servo1.attach(5, 544, 2400); // (pin, Min, Max) 70degree: 722, 90degree: 928, 110degree: 1134
  Serial.begin(9600); // Serial Monitor
  Bluetooth.begin(9600); // Default baud rate of the Bluetooth module
  Bluetooth.setTimeout(1);
  delay(20);
  //initial position of the servo
  Servo1ip = 90;
  Servo1.write(Servo1ip);
}

void loop() {
  //Bluetooth Control
  while (Bluetooth.available()) {
    char Blu = (char)Bluetooth.read();
    myString += Blu;
    delay(5);
  }
  if (!myString.equals("")) {
    Serial.println("input value: " + myString); //print on Serial Monitor
    if (myString == "Front") {
      car_front();
    }
    if (myString == "Back") {
      car_back();
    }
    if (myString == "LF") {
      car_LFront();
    }
    if (myString == "RF") {
      car_RFront();
    }
    if (myString == "LB") {
      car_LBack();
    }
    if (myString == "RB") {
      car_RBack();
    }
    if (myString == "Right") {
      car_right();
    }
    if (myString == "Left") {
      car_left();
    }
    if (myString == "M") {
      car_M();
    }
    myString = "";
  }
}

void car_front() {
  Serial.println("Front");
  Servo1.write(90);
  digitalWrite(8, HIGH);
  digitalWrite(9, LOW);
  delay(1000); //run it for 1000ms
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
}
void car_back() {
  Serial.println("Back");
  Servo1.write(90);
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
  delay(1000); //run it for 1000ms
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
}
void car_LF() {
  Serial.println("Left");
  Servo1.write(70);
  digitalWrite(8, HIGH);
  digitalWrite(9, LOW);
  delay(1000); //run it for 1000ms
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
}
void car_RFront() {
  Serial.println("RightFront");
  Servo1.write(110);
  digitalWrite(8, HIGH);
  digitalWrite(9, LOW);
  delay(1000); //run it for 1000ms
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
}
void car_LFront() {
  Serial.println("LeftFront");
  Servo1.write(70);
  digitalWrite(8, HIGH);
  digitalWrite(9, LOW);
  delay(1000); //run it for 1000ms
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
}
void car_LBack() {
  Serial.println("LeftBack");
  Servo1.write(110);
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
  delay(1000); //run it for 1000ms
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
}
void car_RBack() {
  Serial.println("RightBack");
  Servo1.write(70);
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
  delay(1000); //run it for 1000ms
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
}
void car_right() {
  Serial.println("Right");
  Servo1.write(110);
  delay(1000); //run it for 1000ms
}
void car_left() {
  Serial.println("Left");
  Servo1.write(70);
  delay(1000); //run it for 1000ms
}
void car_M() {
  Serial.println("Middle");
  Servo1.write(90);
  delay(1000); //run it for 1000ms
}
