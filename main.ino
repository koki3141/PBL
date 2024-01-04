#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40);


const int ECHO_PIN_RIGHT = 2;
const int TRIG_PIN_RIGHT = 3;
const int ECHO_PIN_LEFT = 4;
const int TRIG_PIN_LEFT = 5;

const int MOTOR1 = 1;
const int MOTOR2 = 2;
const int MOTOR3 = 3;

typedef struct {
  int pin;
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
  // pin番号, 誤差
  { 12, 0, MOTOR1},
  { 13, -5, MOTOR2},
  { 14, 0, MOTOR3}
};

const legSetting FOWARD_LEFT_LEG = {
  { 8, 4, MOTOR1},
  { 9, 0, MOTOR2},
  { 10, 0, MOTOR3}
};
const legSetting BACK_RIGHT_LEG = {
  { 4, -5, MOTOR1},
  { 5, -5, MOTOR2},
  { 6, 0, MOTOR3}
};
const legSetting BACK_LEFT_LEG = {
  { 0, -4, MOTOR1},
  { 1, 0, MOTOR2},
  { 2, 0, MOTOR3}
};

int STANDARD_ANGLE = 0;
legAngle STANDARD_LEG_ANGLE = {90, 150, 90};

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
  // runStandard();
  runtest();
}

void runStandard(){
  legMove(FOWARD_RIGHT_LEG, {0, 0, 0});
  legMove(BACK_LEFT_LEG, {0, 0, 0});
  legMove(FOWARD_LEFT_LEG, {0, 0, 0});
  legMove(BACK_RIGHT_LEG, {0, 0, 0});
}

void runtest() {
  // legMove(FOWARD_RIGHT_LEG, {0, 0, 0});
  specificMotorNumberMove(MOTOR2, 0);
  delay(1000);
  specificMotorNumberMove(MOTOR2, 20);
  delay(1000);
}

void legMove(const legSetting& one_leg, const legAngle& leg_angle) {
  motorMove(one_leg.motor1, leg_angle.motor1);
  motorMove(one_leg.motor2, leg_angle.motor2);
  motorMove(one_leg.motor3, leg_angle.motor3);
}

int adjustMotor1StandardAngle(const motorSetting& one_motor, int set_angle){
  // foward_legは前に，back_legは後ろに動く．
  int adjust_angle;
  if (FOWARD_RIGHT_LEG.motor1.pin == one_motor.pin){
    adjust_angle = set_angle - STANDARD_ANGLE;
  } else if(FOWARD_LEFT_LEG.motor1.pin == one_motor.pin){
    adjust_angle = -set_angle + STANDARD_ANGLE;
  } else if(BACK_RIGHT_LEG.motor1.pin == one_motor.pin){
    adjust_angle = set_angle + STANDARD_ANGLE;
  } else if(BACK_LEFT_LEG.motor1.pin == one_motor.pin){
    adjust_angle = -set_angle - STANDARD_ANGLE;
  }
  return adjust_angle;
}

void motorMove(const motorSetting& one_motor, int set_angle) {
  const int SERVO_MIN = 500;
  const int SERVO_MAX = 2400;
  
  set_angle = set_angle + one_motor.error;
  
  if (one_motor.number == MOTOR1){
    set_angle = adjustMotor1StandardAngle(one_motor, set_angle);
    set_angle = STANDARD_LEG_ANGLE.motor1 + set_angle;
  } else if (one_motor.number == MOTOR2){
    set_angle = STANDARD_LEG_ANGLE.motor2 - set_angle;
  } else if (one_motor.number == MOTOR3){
    set_angle = STANDARD_LEG_ANGLE.motor3 + set_angle;
  } else {
    Serial.print("Not define motor number");
    delay(100);
    exit(1);
  }

  if (set_angle < 10 || 170 < set_angle){
    Serial.print("pin number : ");
    Serial.println(one_motor.pin);
    Serial.print("motor number : ");
    Serial.println(one_motor.number);
    Serial.print("set angle is out of range : ");
    Serial.println(set_angle);
    delay(100);
    exit(1);
  }

  int wirte_angle = map(set_angle, 0, 180, SERVO_MIN, SERVO_MAX);
  pwm.writeMicroseconds(one_motor.pin, wirte_angle);
}

void specificMotorNumberMove(const int motor_number, const int set_angle){
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