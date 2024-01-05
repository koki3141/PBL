void roll(const legSetting& one_leg);
void step1(const legSetting& one_leg);
void step2(const legSetting& one_leg);
void step3(const legSetting& one_leg);
void step4(const legSetting& one_leg);

void runPerformance() {

  roll(FOWARD_RIGHT_LEG);

  roll(BACK_LEFT_LEG);

  roll(FOWARD_LEFT_LEG);

  roll(BACK_RIGHT_LEG);

}

void roll(const legSetting& one_leg){
  step1(one_leg);
  delay(1000);
  step2(one_leg);
  delay(1000);
  step3(one_leg);
  delay(1000);
  step4(one_leg);
  delay(1000);
}

void step1(const legSetting& one_leg) {
  const legAngle ROLL_LEG_ANGLE = {0, 15, -15};
  setLegAngle(one_leg, ROLL_LEG_ANGLE);
}

void step2(const legSetting& one_leg) {
  const legAngle ROLL_LEG_ANGLE = {10, 0, 0};
  setLegAngle(one_leg, ROLL_LEG_ANGLE);
}

void step3(const legSetting& one_leg) {
  setLegAngle(one_leg, {0, 15, -15});
}

void step4(const legSetting& one_leg) {
  setLegAngle(one_leg, {0,0,0});
}