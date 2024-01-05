double distanceFromSensor(int echo_pin, int trig_pin);
double durationToCm(double duration);
void displayDistance(double distance_from_sensor);

void runGoalKeeping() {
  setInitialPosition(GOAL_KEEPING_INITAL_POSITION);

  const int EXPECT_DISTANCE = 20; //the expect distance
  const legAngle DEFENT_LEG_ANGLE = {0, 30, 0};

  double distance_from_right_sensor = distanceFromSensor(ECHO_PIN_RIGHT, TRIG_PIN_RIGHT);
  double distance_from_left_sensor = distanceFromSensor(ECHO_PIN_LEFT, TRIG_PIN_LEFT);

  
  if (distance_from_left_sensor > EXPECT_DISTANCE && distance_from_right_sensor < EXPECT_DISTANCE) {
    setLegAngle(FOWARD_RIGHT_LEG, DEFENT_LEG_ANGLE);
    Serial.println("right");
  } else if (distance_from_left_sensor < EXPECT_DISTANCE && distance_from_right_sensor > EXPECT_DISTANCE) {
    setLegAngle(BACK_LEFT_LEG, DEFENT_LEG_ANGLE);
    Serial.println("left");
  } else {
    Serial.println("strike");
  }
}

double distanceFromSensor(int echo_pin, int trig_pin) {
  digitalWrite(trig_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(trig_pin, HIGH);  //超音波を出力
  delayMicroseconds(10); 
  digitalWrite(trig_pin, LOW);
  double duration = pulseIn(echo_pin, HIGH); //タイムアウト時は0を返す．
  
  double distance_from_sensor = durationToCm(duration);
  displayDistance(distance_from_sensor);

  return distance_from_sensor;
}

// TODO 要動作確認
double durationToCm(double duration) {
  double half_duration = duration / 2;                 // 往復距離を半分にする
  const int SOUND_SPEED = 340; // 音速を340m/sに設定
  const int M_TO_CM = 100;
  const int SECONDS_TO_MICROSECONDS = 1000000;

  double distance_in_cm = (half_duration / SECONDS_TO_MICROSECONDS) * double(SOUND_SPEED * M_TO_CM);  
  return distance_in_cm;
}

void displayDistance(double distance_from_sensor){
  Serial.print("distance:");
  Serial.print(distance_from_sensor);
  Serial.println(" cm");
}

