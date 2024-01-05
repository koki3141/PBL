void runWalk();
void step1();
void step2();
void step3();
void step4();


void runStairsClimbing() {
  runWalk();
}

void runWalk() {
  step1();
  delay(1000);
  step2();
  delay(1000);

  step3();
  delay(1000);

  step4();
  delay(1000);

  step5();
  delay(100);
}


void step1() {
  Serial.println("step1");
  const legAngle SUPPORT_FOWRARD_LEG_ANGLE = { 0, 5, 5 };
  const legAngle SUPPORT_BACK_LEG_ANGLE = { 0, 0, 0 };
  const legAngle MOVE_LEG_ANGLE = { 25, -10, -45 };
  setLegAngle(FOWARD_RIGHT_LEG, MOVE_LEG_ANGLE);
  setLegAngle(BACK_LEFT_LEG, MOVE_LEG_ANGLE);
  setLegAngle(FOWARD_LEFT_LEG, SUPPORT_FOWRARD_LEG_ANGLE);
  setLegAngle(BACK_RIGHT_LEG, SUPPORT_BACK_LEG_ANGLE);
}

void step2() {
  Serial.println("step2");
  const legAngle SUPPORT_LEG_ANGLE = { -25, 0, 0 };
  const legAngle MOVE_LEG_ANGLE = { 25, 0, 0 };
  setLegAngle(FOWARD_RIGHT_LEG, MOVE_LEG_ANGLE);
  setLegAngle(BACK_LEFT_LEG, MOVE_LEG_ANGLE);
  setLegAngle(FOWARD_LEFT_LEG, SUPPORT_LEG_ANGLE);
  setLegAngle(BACK_RIGHT_LEG, SUPPORT_LEG_ANGLE);
}

void step3() {
  Serial.println("step3");
  const legAngle SUPPORT_FOWRARD_LEG_ANGLE = { 0, 5, 5 };
  const legAngle SUPPORT_BACK_LEG_ANGLE = { 0, 0, 0 };
  const legAngle MOVE_LEG_ANGLE = { 25, -10, -45 };
  setLegAngle(FOWARD_RIGHT_LEG, SUPPORT_FOWRARD_LEG_ANGLE);
  setLegAngle(BACK_LEFT_LEG, SUPPORT_BACK_LEG_ANGLE);
  setLegAngle(FOWARD_LEFT_LEG, MOVE_LEG_ANGLE);
  setLegAngle(BACK_RIGHT_LEG, MOVE_LEG_ANGLE);
}

void step4() {
  Serial.println("step4");
  const legAngle SUPPORT_LEG_ANGLE = { -25, 0, 0 };
  const legAngle MOVE_LEG_ANGLE = { 25, 0, 0 };
  setLegAngle(FOWARD_RIGHT_LEG, SUPPORT_LEG_ANGLE);
  setLegAngle(BACK_LEFT_LEG, SUPPORT_LEG_ANGLE);
  setLegAngle(FOWARD_LEFT_LEG, MOVE_LEG_ANGLE);
  setLegAngle(BACK_RIGHT_LEG, MOVE_LEG_ANGLE);
}

void step5(){
  setLegAngle(BACK_RIGHT_LEG, {0, 0, 0});
}
