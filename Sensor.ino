
double SensorLeft() {
  digitalWrite(TRIG_PIN_LEFT, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN_LEFT, HIGH);  //超音波を出力
  delayMicroseconds(10);              //
  digitalWrite(TRIG_PIN_LEFT, LOW);
  double duration = pulseIn(ECHO_PIN_LEFT, HIGH);  //センサからの入力
  return duration_to_cm(duration);
}


double SensorRight() {
  digitalWrite(TRIG_PIN_RIGHT, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN_RIGHT, HIGH);  //超音波を出力
  delayMicroseconds(10);               //
  digitalWrite(TRIG_PIN_RIGHT, LOW);
  double duration = pulseIn(ECHO_PIN_RIGHT, HIGH);  //センサからの入力
  return duration_to_cm(duration);
}

double duration_to_cm(double duration) {
  if (duration > 0) {
    int half_duration = duration / 2;                                 //往復距離を半分にする
    double distance_in_cm = half_duration * 340 * 100 / 1000000;  // 音速を340m/sに設定
    Serial.print("left:");
    Serial.print(distance_in_cm);
    Serial.println(" cm");
    return distance_in_cm;
  } else {
    return 0;
  }
}