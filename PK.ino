double distanceFromSensor(int echo_pin, int trig_pin);
double durationToCm(double duration);

void runPk() {
  legAngle STANDARD_LEG_ANGLE = {90, 150, 90};
  const int EXPECT_DISTANCE = 10; //the expect distance
  const legAngle PK_STANBY = {0,90,60};
  const legAngle DEFENT_LEG_ANGLE = {0, 30, 0};

  double distance_from_right_sensor = distanceFromSensor(ECHO_PIN_RIGHT, TRIG_PIN_RIGHT);
  double distance_from_left_sensor = distanceFromSensor(ECHO_PIN_LEFT, TRIG_PIN_LEFT);

  
  if (distance_from_left_sensor > EXPECT_DISTANCE && distance_from_right_sensor < EXPECT_DISTANCE) {
    legMove(FOWARD_RIGHT_LEG, DEFENT_LEG_ANGLE);
    Serial.println("right");
  } else if (distance_from_left_sensor < EXPECT_DISTANCE && distance_from_right_sensor > EXPECT_DISTANCE) {
    legMove(BACK_LEFT_LEG, DEFENT_LEG_ANGLE);
    Serial.println("left");
  } else {
    // legMove(FOWARD_RIGHT_LEG, {0, 0, 0});
    // legMove(FOWARD_LEFT_LEG, {0, 0, 0});
    // legMove(BACK_RIGHT_LEG, {0, 0, 0});
    // legMove(BACK_LEFT_LEG, {0, 0, 0});
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

double durationToCm(double duration) {
  double half_duration = duration / 2;                 //往復距離を半分にする
  double distance_in_cm = half_duration * 340 * 100 / 1000000;  // 音速を340m/sに設定
  return distance_in_cm;
  }
}

void displayDistance(double distance_from_sensor){
  Serial.print("distance:");
  Serial.print(distance_in_cm);
  Serial.println(" cm");
}

