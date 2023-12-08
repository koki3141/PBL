#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40);

const int SERVOMIN = 500;
const int SERVOMAX = 2400;
const int ECHO_PIN_RIGHT = 2;
const int TRIG_PIN_RIGHT = 3;
const int ECHO_PIN_LEFT = 4;
const int TRIG_PIN_LEFT = 5;

typedef struct {
  int pin;
  bool reverse;
  int error;
} oneServo;

typedef struct {
  oneServo motor1;
  oneServo motor2;
  oneServo motor3;
} oneLeg;

typedef struct {
  int motor1;
  int motor2;
  int motor3;
} legAngle;

const oneLeg FOWARD_RIGHT_LEG = {
  // pin番号, 逆, 誤差
  { 0, false, 0},
  { 1, false, 0},
  { 2, false, 0}
};

const oneLeg FOWARD_LEFT_LEG = {
  { 3, false, 0 },
  { 4, false, 0 },
  { 5, false, 0 }
};
const oneLeg BACK_RIGHT_LEG = {
  { 6, false, 0 },
  { 7, false, 0 },
  { 8, false, 0 }
};
const oneLeg BACK_LEFT_LEG = {
  { 9, false, 0 },
  { 10, false, 0 },
  { 11, false, 0 }
};

void setup() {
  pinMode(ECHO_PIN_RIGHT, INPUT);
  pinMode(TRIG_PIN_RIGHT, OUTPUT);
  pinMode(ECHO_PIN_LEFT, INPUT);
  pinMode(TRIG_PIN_LEFT, OUTPUT);
  pwm.begin();
  pwm.setPWMFreq(50);
  Serial.begin(9600);
}

void loop() {
  //Specifying actions
  // runPk();
  // runClime();
  // runPerformance();
  runtest();
}

void runtest() {
  servoMove(FOWARD_RIGHT_LEG.motor1, 90);
  delay(1000);
}

void moveOneLeg(const oneLeg& one_leg, const legAngle& leg_angle) {
  servoMove(one_leg.motor1, leg_angle.motor1);
  servoMove(one_leg.motor2, leg_angle.motor2);
  servoMove(one_leg.motor3, leg_angle.motor3);
}

void servoMove(const oneServo& one_servo, int set_angle) {
  if (one_servo.reverse) {
    set_angle = map(abs(set_angle - 90), 0, 180, SERVOMIN, SERVOMAX);
  } else {
    set_angle = map(set_angle, 0, 180, SERVOMIN, SERVOMAX);
  }
  pwm.writeMicroseconds(one_servo.pin, set_angle);
}