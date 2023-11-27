#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

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
const int forward_left_1 = 2;
const int forward_left_2 = 3;
const int middle_right_1 = 4;
const int middle_right_2 = 5;
const int middle_left_1 = 6;
const int middle_left_2 = 7;
const int back_right_1 = 8;
const int back_right_2 = 9;
const int back_left_1 = 10;
const int back_left_2 = 11;

enum status {
  pk,
  clime,
  perfomance,
  stand
};

typedef struct {
  int pin;
  int stand; //stand angle
} servo;

const servo SERVOs[12] = {
  { 0 , 0},
  { 1 , 0},
  { 2 , 0},
  { 4 , 0},//servopin 3 is broken in Japan
  { 5 , 0},
  { 6 , 0},
  { 7 , 0},
  { 8 , 0},
  { 9 , 0},
  { 10 , 0},
  { 11 , 0},
  { 12 , 0}
};


void setup() {
  pinMode(ECHO_PIN_RIGHT, INPUT);
  pinMode(TRIG_PIN_RIGHT, OUTPUT);
  pinMode(ECHO_PIN_LEFT, INPUT);
  pinMode(TRIG_PIN_LEFT, OUTPUT);
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
    case stand:
      runStand();
    default:
      break;
  }
}

void loop() {
  //Specifying actions
  exe(pk);
}


void runStand(){
  for (int i = 0; i < 12; i++) {
    servoMove(SERVOs[i].pin,SERVOs[i].stand);
  }
}

void servoMove(int pin, int set_angle){
  int angle = map(set_angle, 0, 180, SERVOMIN, SERVOMAX);
  pwm.setPWM(pin, 0, angle);
}