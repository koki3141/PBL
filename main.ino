#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40);

const int SERVO_MIN = 500;
const int SERVO_MAX = 2400;
const int ECHO_PIN_RIGHT = 2;
const int TRIG_PIN_RIGHT = 3;
const int ECHO_PIN_LEFT = 4;
const int TRIG_PIN_LEFT = 5;

const int MOTOR1 = 1;
const int MOTOR2 = 2;
const int MOTOR3 = 3;

typedef struct {
  int pin;
  bool reverse;
  int error;
  int number;
} motorSetting;

typedef struct {
  motorSetting motor1;
  motorSetting motor2;
  motorSetting motor3;
} legSetting;

typedef struct {
  int motor1;
  int motor2;
  int motor3;
} legAngle;

const legSetting FOWARD_RIGHT_LEG = {
  // pin番号, 逆, 誤差
  { 0, false, 0, MOTOR1},
  { 1, false, 0, MOTOR2},
  { 2, false, 0, MOTOR3}
};

const legSetting FOWARD_LEFT_LEG = {
  { 3, true, 0, MOTOR1},
  { 4, false, 0, MOTOR2},
  { 5, false, 0, MOTOR3}
};
const legSetting BACK_RIGHT_LEG = {
  { 6, false, 0, MOTOR1},
  { 7, false, 0, MOTOR2},
  { 8, false, 0, MOTOR3}
};
const legSetting BACK_LEFT_LEG = {
  { 9, true, 0, MOTOR1},
  { 10, false, 0, MOTOR2},
  { 11, false, 0, MOTOR3}
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
  // runtest();
}

void runtest() {
  legMove(FOWARD_RIGHT_LEG, {150,150,150});
  delay(1000);
}

void legMove(const legSetting& one_leg, const legAngle& leg_angle) {
  motorMove(one_leg.motor1, leg_angle.motor1);
  motorMove(one_leg.motor2, leg_angle.motor2);
  motorMove(one_leg.motor3, leg_angle.motor3);
}

void motorMove(const motorSetting& one_motor, int set_angle) {
  const legAngle STANDARD_ANGLE = {90, 150, 20};
  
  set_angle = set_angle + one_motor.error;
  
  if (one_motor.number == MOTOR1){
    if (one_motor.reverse){
      set_angle = STANDARD_ANGLE.motor1 - set_angle;
    } else {
      set_angle = set_angle - STANDARD_ANGLE.motor1;
    }
  } else if (one_motor.number == MOTOR2){
    set_angle = STANDARD_ANGLE.motor2 - set_angle;
  } else if (one_motor.number == MOTOR3){
    set_angle = set_angle - STANDARD_ANGLE.motor3;
  } else {
    Serial.print("Not define motor number");
    exit(1);
  }

  if (set_angle < 10 || 170 < set_angle){
    Serial.print("set angle is out of range");
    Serial.print(set_angle);
    exit(1);
  }

  pwm.writeMicroseconds(one_motor.pin, set_angle);
}

void specificMotorMove(const int motor_number, const int set_angle){
  if (motor_number == MOTOR1){
    motorMove(FOWARD_RIGHT_LEG.motor1, set_angle);
    motorMove(FOWARD_LEFT_LEG.motor1, set_angle);
    motorMove(BACK_RIGHT_LEG.motor1, set_angle);
    motorMove(BACK_LEFT_LEG.motor1, set_angle);
  } else if (motor_number == MOTOR2){
    motorMove(FOWARD_RIGHT_LEG.motor2, set_angle);
    motorMove(FOWARD_LEFT_LEG.motor2, set_angle);
    motorMove(BACK_RIGHT_LEG.motor2, set_angle);
    motorMove(BACK_LEFT_LEG.motor2, set_angle);
  } else if (motor_number == MOTOR3){
    motorMove(FOWARD_RIGHT_LEG.motor3, set_angle);
    motorMove(FOWARD_LEFT_LEG.motor3, set_angle);
    motorMove(BACK_RIGHT_LEG.motor3, set_angle);
    motorMove(BACK_LEFT_LEG.motor3, set_angle);
  }
}