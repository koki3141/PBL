double distanceFromSensor(int echo_pin, int trig_pin);
double durationToCm(double duration);

void runPk() {
  const int EXPECT_DISTANCE = 100; //the expect distance
  double distance_from_right_sensor = distanceFromSensor(ECHO_PIN_RIGHT, TRIG_PIN_RIGHT);
  double distance_from_left_sensor = distanceFromSensor(ECHO_PIN_LEFT, TRIG_PIN_LEFT);
  const legAngle DEFENT_LEG_ANGLE = {0, 80, 70};
  
  if (distance_from_left_sensor > EXPECT_DISTANCE && distance_from_right_sensor < EXPECT_DISTANCE) {
    legMove(FOWARD_RIGHT_LEG, DEFENT_LEG_ANGLE);
  } else if (distance_from_left_sensor < EXPECT_DISTANCE && distance_from_right_sensor > EXPECT_DISTANCE) {
    legMove(BACK_LEFT_LEG, DEFENT_LEG_ANGLE);
  } else {
    legMove(FOWARD_RIGHT_LEG, {0, 0, 0});
    legMove(FOWARD_LEFT_LEG, {0, 0, 0});
    legMove(BACK_RIGHT_LEG, {0, 0, 0});
    legMove(BACK_LEFT_LEG, {0, 0, 0});
  }
}

double distanceFromSensor(int echo_pin, int trig_pin) {
  digitalWrite(trig_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(trig_pin, HIGH);  //超音波を出力
  delayMicroseconds(10); 
  digitalWrite(trig_pin, LOW);
  double duration = pulseIn(echo_pin, HIGH);
  double distance_from_sensor = durationToCm(duration);
  return distance_from_sensor;
}

double durationToCm(double duration) {
  if (duration > 0) {
    int half_duration = duration / 2;                 //往復距離を半分にする
    double distance_in_cm = half_duration * 340 * 100 / 1000000;  // 音速を340m/sに設定
    Serial.print("left:");
    Serial.print(distance_in_cm);
    Serial.println(" cm");
    return distance_in_cm;
  } else {
    return 0;
  }
}

