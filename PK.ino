void runPk() {
  const int EXPECT_DISTANCE = 100; //the expect distance
  double sensor_right = SensorRight();
  double sensor_left = SensorLeft();
  if (sensor_left > EXPECT_DISTANCE && sensor_right < EXPECT_DISTANCE) {
    DefendRightSide();
  } else if (sensor_left < EXPECT_DISTANCE && sensor_right > EXPECT_DISTANCE) {
    DefendLeftSide();
  } else {
    // stand
  }
}