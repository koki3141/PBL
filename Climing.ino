void runWalk();
void STEP1();
void STEP2();
void STEP3();
void STEP4();


void runClime() {
  runWalk();
}

void runWalk() {
  runStandard();
  delay(1000);
  STEP1();
  delay(500);
  STEP2();
  delay(1000);
  runStandard();
  delay(1000);
  STEP3();
  delay(500);
  STEP4();
  delay(1000);
}


void STEP1() {
  const legAngle SUPPORT_LEG_ANGLE = {-10, 0, 0};
  const legAngle MOVE_LEG_ANGLE = {30, 0, -30};
  legMove(FOWARD_RIGHT_LEG, MOVE_LEG_ANGLE);
  legMove(BACK_LEFT_LEG, MOVE_LEG_ANGLE);
  legMove(FOWARD_LEFT_LEG, SUPPORT_LEG_ANGLE);
  legMove(BACK_RIGHT_LEG, SUPPORT_LEG_ANGLE);
}

void STEP2() {
  const legAngle MOVE_LEG_ANGLE = {30, 0, 0};
  legMove(FOWARD_RIGHT_LEG, MOVE_LEG_ANGLE);
  legMove(BACK_LEFT_LEG, MOVE_LEG_ANGLE);
}

void STEP3() {
  const legAngle SUPPORT_LEG_ANGLE = {-10, 0, 0};
  const legAngle MOVE_LEG_ANGLE = {30, 0, -30};
  legMove(FOWARD_RIGHT_LEG, SUPPORT_LEG_ANGLE);
  legMove(BACK_LEFT_LEG, SUPPORT_LEG_ANGLE);
  legMove(FOWARD_LEFT_LEG, MOVE_LEG_ANGLE);
  legMove(BACK_RIGHT_LEG, MOVE_LEG_ANGLE);
}

void STEP4() {
  const legAngle MOVE_LEG_ANGLE = {30, 0, 0};
  legMove(FOWARD_LEFT_LEG, MOVE_LEG_ANGLE);
  legMove(BACK_RIGHT_LEG, MOVE_LEG_ANGLE);
}
