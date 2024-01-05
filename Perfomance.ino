void roll(const legSetting& one_leg);

void runPerformance() {

  standardPosition();
  delay(1000);

  roll(FOWARD_RIGHT_LEG);
  delay(1000);

  roll(BACK_LEFT_LEG);
  delay(1000);

  roll(FOWARD_LEFT_LEG);
  delay(1000);

  roll(BACK_RIGHT_LEG);
  delay(1000);
}

void roll(const legSetting& one_leg){
  const legAngle ROLL_LEG_ANGLE = {10, 15, -15};
  setLegAngle(one_leg, ROLL_LEG_ANGLE);
  delay(1000);
  setLegAngle(one_leg, {0,0,0});
}