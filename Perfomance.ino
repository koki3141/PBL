void roll(const legSetting& one_leg);

void runPerformance() {
  STANDARD_ANGLE = 0;
  legAngle STANDARD_LEG_ANGLE = {90, 150, 90};

  runStandard();

  roll(FOWARD_RIGHT_LEG);
  roll(BACK_LEFT_LEG);
  roll(FOWARD_LEFT_LEG);
  roll(BACK_RIGHT_LEG);
}

void roll(const legSetting& one_leg){
  const legAngle ROLL_LEG_ANGLE = {10, 15, -15};
  legMove(one_leg, ROLL_LEG_ANGLE);
  delay(1000);
  legMove(one_leg, {0,0,0});
}