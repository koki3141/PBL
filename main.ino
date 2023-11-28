#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <Servo.h>
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40);

const int SERVOMIN = 500;
const int SERVOMAX = 2400;
const int ECHO_PIN_RIGHT = 2;
const int TRIG_PIN_RIGHT = 3;
const int ECHO_PIN_LEFT = 4;
const int TRIG_PIN_LEFT = 5;

// We may not use it.”
const int forward_right_1 = 0;
const int forward_right_2 = 1;
const int forward_right_3 = 2;

const int forward_left_1 = 3;
const int forward_left_2 = 4;
const int forward_left_3 = 5;

const int back_right_1 = 6;
const int back_right_2 = 7;
const int back_right_3 = 8;

const int back_left_1 = 9;
const int back_left_2 = 10;
const int back_left_3 = 11;

enum status {
  pk,
  clime,
  perfomance,
  test
};

typedef struct {
  Servo servo;
  bool reverse;
} oneServo;

typedef struct {
  oneServo join1;
  oneServo join2;
  oneServo join3;
} oneLeg;

const oneLeg FOWARD_RIGHT_LEG = {
  {Servo(), false},
  {Servo(), false},
  {Servo(), false}
};

const oneLeg FOWARD_LEFT_LEG = {
  {Servo(), true},
  {Servo(), false},
  {Servo(), false}
};
const oneLeg BACK_RIGHT_LEG = {
  {Servo(), false},
  {Servo(), false},
  {Servo(), false}
};
const oneLeg BACK_LEFT_LEG = {
  {Servo(), true},
  {Servo(), false},
  {Servo(), false}
};

typedef struct {
  int join1;
  int join2;
  int join3;
} legAngle;

const legAngle STANDARD = {90,90,90};


void setup() {
  pinMode(ECHO_PIN_RIGHT, INPUT);
  pinMode(TRIG_PIN_RIGHT, OUTPUT);
  pinMode(ECHO_PIN_LEFT, INPUT);
  pinMode(TRIG_PIN_LEFT, OUTPUT);

  FOWARD_RIGHT_LEG.join1.servo.attach(0);
  FOWARD_RIGHT_LEG.join2.servo.attach(1);
  FOWARD_RIGHT_LEG.join3.servo.attach(2);
  
  FOWARD_LEFT_LEG.join1.servo.attach(3);
  FOWARD_LEFT_LEG.join2.servo.attach(4);
  FOWARD_LEFT_LEG.join3.servo.attach(5);

  BACK_RIGHT_LEG.join1.servo.attach(6) ;
  BACK_RIGHT_LEG.join2.servo.attach(7);
  BACK_RIGHT_LEG.join3.servo.attach(8);

  BACK_LEFT_LEG.join1.servo.attach(9);
  BACK_LEFT_LEG.join2.servo.attach(10);
  BACK_LEFT_LEG.join3.servo.attach(11);

  pwm.begin();
  pwm.setPWMFreq(50);
  Serial.begin(9600);
  delay(1000);
}

void exe(status type) {
  switch (type) {
    case pk:
      runPk();
      break;
    case clime:
      runClime();
      break;
    case perfomance:
      runPerformance();
      break;
    case test:
      runtest();
    default:
      break;
  }
}

void loop() {
  //Specifying actions
  exe(pk);
}

void runtest(){

}

void moveAllLeg(legAngle& leg_angle){
  moveOneLeg(FOWARD_RIGHT_LEG, leg_angle);
  moveOneLeg(FOWARD_LEFT_LEG, leg_angle);
  moveOneLeg(BACK_RIGHT_LEG, leg_angle);
  moveOneLeg(BACK_LEFT_LEG, leg_angle);
}

void moveOneLeg(const oneLeg& one_leg, const legAngle& leg_angle){
    servoMove(one_leg.join1, leg_angle.join1);
    servoMove(one_leg.join2, leg_angle.join2);
    servoMove(one_leg.join3, leg_angle.join3);
}

void servoMove(const oneServo &join, int set_angle){
  if (join.reverse){
    set_angle = abs(set_angle - STANDARD.join1);
  }
  join.servo.write(set_angle);
}