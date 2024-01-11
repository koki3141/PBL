#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40);


const int ECHO_PIN_RIGHT = 2;
const int TRIG_PIN_RIGHT = 3;
const int ECHO_PIN_LEFT = 4;
const int TRIG_PIN_LEFT = 5;

const int SERVO_1 = 1;
const int SERVO_2 = 2;
const int SERVO_3 = 3;

typedef struct {
  int pin;
  int error;
  int number;
} servoSetting;

typedef struct {
  servoSetting servo1;
  servoSetting servo2;
  servoSetting servo3;
} legSetting;

typedef struct {
  int servo1;
  int servo2;
  int servo3;
} legAngle;

const legSetting FRONT_LEG = {
  // pin番号, 誤差
  { 12, 0, SERVO_1},
  { 13, 5, SERVO_2},
  { 14, 0, SERVO_3}
};

const legSetting LEFT_LEG = {
  { 8, -5, SERVO_1},
  { 9, 0, SERVO_2},
  { 10, -5, SERVO_3}
};
const legSetting RIGHT_LEG = {
  { 4, 5, SERVO_1},
  { 5, 10, SERVO_2},
  { 6, 0, SERVO_3}
};
const legSetting BACK_LEG = {
  { 0, -4, SERVO_1},
  { 1, 0, SERVO_2},
  { 2, -5, SERVO_3}
};

typedef struct {
  legSetting front;
  legSetting back;
} pairLegs;

int ADJUSTMENT_SERVO_1_ANGLE;
legAngle STANDARD_LEG_ANGLE;

enum ActionType {
 GOAL_KEEPING,
 STAIRS_CLIMBING,
 PERFORMANCE,
 TEST
};

const ActionType SELECT_ACTION = STAIRS_CLIMBING;

void setup() {
  pinMode(ECHO_PIN_RIGHT, INPUT);
  pinMode(TRIG_PIN_RIGHT, OUTPUT);
  pinMode(ECHO_PIN_LEFT, INPUT);
  pinMode(TRIG_PIN_LEFT, OUTPUT);
  pwm.begin();
  pwm.setPWMFreq(50);
  Serial.begin(9600);

  setInitialPosition(SELECT_ACTION);
  standardPosition();
  delay(500);
}

void loop() {
 switch(SELECT_ACTION) {
  case STAIRS_CLIMBING:
    runStairsClimbing();
    break;
  case GOAL_KEEPING:
    runGoalKeeping();
    break;
  case PERFORMANCE:
    runPerformance();
    break;
  case TEST:
    runtest();
  default:
    break;
 }
}


void standardPosition(){
  Serial.println("standardPosition");
  setLegAngle(FRONT_LEG, {0, 0, 0});
  setLegAngle(RIGHT_LEG, {0, 0, 0});
  setLegAngle(LEFT_LEG, {0, 0, 0});
  setLegAngle(RIGHT_LEG, {0, 0, 0});
}

void runtest() {  
  setInitialPosition(SELECT_ACTION);
  // testOneLegAngle();

  testAllServoAngle();
}


void testOneLegAngle(){
  setLegAngle(FRONT_LEG, {0, 0, 0});
  delay(1000);

  setLegAngle(FRONT_LEG, {30, -20, -20});
  delay(1000);
}
void testOneServoAngle(){
  setServoAngle(BACK_LEG.servo1, -10);
  delay(1000);

  setServoAngle(BACK_LEG.servo1, 30);
  delay(1000);
}
void testAllServoAngle(){
  setServo1Angle(0);
  setServo2Angle(0);
  setServo3Angle(0);
  delay(1000);

  setServo1Angle(30);
  delay(500);
  setServo2Angle(30);
  delay(500);
  setServo3Angle(-30);
  delay(1000);
}

void setInitialPosition(ActionType initial_position) {
  switch(initial_position) {
  case STAIRS_CLIMBING:
    STANDARD_LEG_ANGLE = {90, 130, 160};
    ADJUSTMENT_SERVO_1_ANGLE = 0;
    break;
  case GOAL_KEEPING:
    STANDARD_LEG_ANGLE = {90, 70, 90};
    ADJUSTMENT_SERVO_1_ANGLE = 0;
    break;
  case PERFORMANCE:
    STANDARD_LEG_ANGLE = {90, 150, 170};
    ADJUSTMENT_SERVO_1_ANGLE = 0;
    break;
  case TEST:
    STANDARD_LEG_ANGLE = {90, 150, 90};
    // STANDARD_LEG_ANGLE = {90, 120, 150};
    ADJUSTMENT_SERVO_1_ANGLE = 0;
    break;
  default:
    break;
  }
}


void setLegAngle(const legSetting& one_leg, const legAngle& leg_angle) {
  setServoAngle(one_leg.servo1, leg_angle.servo1);
  setServoAngle(one_leg.servo2, leg_angle.servo2);
  setServoAngle(one_leg.servo3, leg_angle.servo3);
}

void setServo1Angle(const int set_angle){
  setServoAngle(FRONT_LEG.servo1, set_angle);
  setServoAngle(LEFT_LEG.servo1, set_angle);
  setServoAngle(BACK_LEG.servo1, set_angle);
  setServoAngle(RIGHT_LEG.servo1, set_angle);
}

void setServo2Angle(const int set_angle){
  setServoAngle(FRONT_LEG.servo2, set_angle);
  setServoAngle(LEFT_LEG.servo2, set_angle);
  setServoAngle(BACK_LEG.servo2, set_angle);
  setServoAngle(RIGHT_LEG.servo2, set_angle);
}

void setServo3Angle(const int set_angle){
  setServoAngle(FRONT_LEG.servo3, set_angle);
  setServoAngle(LEFT_LEG.servo3, set_angle);
  setServoAngle(BACK_LEG.servo3, set_angle);
  setServoAngle(RIGHT_LEG.servo3, set_angle);
}

void setServoAngle(const servoSetting& one_servo, int set_angle) {  
  int adjusted_angle;
  if (one_servo.number == SERVO_1){
    int adjust_servo_1_angle = getAdjustServo_1Angle(one_servo, set_angle);
    adjusted_angle =  adjust_servo_1_angle + one_servo.error;
  } else if (one_servo.number == SERVO_2){
    adjusted_angle = STANDARD_LEG_ANGLE.servo2 - set_angle + one_servo.error;
  } else if (one_servo.number == SERVO_3){
    adjusted_angle = STANDARD_LEG_ANGLE.servo3 + set_angle + one_servo.error;
  } else {
    Serial.print("Not define servo number");
    delay(100);
    exit(1);
  }
  checkAngleRange(one_servo, adjusted_angle);

  writeServo(one_servo, adjusted_angle);
}

int getAdjustServo_1Angle(const servoSetting& one_servo, int set_angle){
  int adjust_angle = STANDARD_LEG_ANGLE.servo1;

  if (FRONT_LEG.servo1.pin == one_servo.pin){
    adjust_angle += set_angle - ADJUSTMENT_SERVO_1_ANGLE;
  } else if(LEFT_LEG.servo1.pin == one_servo.pin){
    adjust_angle += -set_angle + ADJUSTMENT_SERVO_1_ANGLE;
  } else if(RIGHT_LEG.servo1.pin == one_servo.pin){
    adjust_angle += set_angle + ADJUSTMENT_SERVO_1_ANGLE;
  } else if(BACK_LEG.servo1.pin == one_servo.pin){
    adjust_angle += -set_angle - ADJUSTMENT_SERVO_1_ANGLE;
  }

  return adjust_angle;
}

void checkAngleRange(const servoSetting& one_servo, const int adjusted_angle) {
  const int MIN_ANGLE = 10;
  const int MAX_ANGLE = 170;

  if (adjusted_angle < MIN_ANGLE || MAX_ANGLE < adjusted_angle){
    Serial.print("pin number : ");
    Serial.println(one_servo.pin);
    Serial.print("servo number : ");
    Serial.println(one_servo.number);
    Serial.print("adjusted angle is out of range : ");
    Serial.println(adjusted_angle);
    delay(100);
    exit(1);
  }
}

void writeServo(const servoSetting& one_servo, const int angle){
  const int SERVO_MIN = 500;
  const int SERVO_MAX = 2400;

  int wirte_angle = map(angle, 0, 180, SERVO_MIN, SERVO_MAX);
  pwm.writeMicroseconds(one_servo.pin, wirte_angle);
}






