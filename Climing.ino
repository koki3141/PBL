void runWalk();
void step1();
void step2();
void step3();
void step4();


void runClime() {
  legAngle STANDARD_LEG_ANGLE = {90, 100, 120};
  STANDARD_ANGLE = 40;
  runWalk();
}

void runWalk() {
  runStandard();
  delay(1000);

  step1();
  delay(500);

  step2();
  delay(1000);

  runStandard();
  delay(1000);

  step3();
  delay(500);
  
  step4();
  delay(1000);
}


void step1() {
  const legAngle SUPPORT_LEG_ANGLE = {-10, 0, 0};
  const legAngle MOVE_LEG_ANGLE = {30, 0, -30};
  legMove(FOWARD_RIGHT_LEG, MOVE_LEG_ANGLE);
  legMove(BACK_LEFT_LEG, MOVE_LEG_ANGLE);
  legMove(FOWARD_LEFT_LEG, SUPPORT_LEG_ANGLE);
  legMove(BACK_RIGHT_LEG, SUPPORT_LEG_ANGLE);
}

void step2() {
  const legAngle MOVE_LEG_ANGLE = {30, 0, 0};
  legMove(FOWARD_RIGHT_LEG, MOVE_LEG_ANGLE);
  legMove(BACK_LEFT_LEG, MOVE_LEG_ANGLE);
}

void step3() {
  const legAngle SUPPORT_LEG_ANGLE = {-10, 0, 0};
  const legAngle MOVE_LEG_ANGLE = {30, 0, -30};
  legMove(FOWARD_RIGHT_LEG, SUPPORT_LEG_ANGLE);
  legMove(BACK_LEFT_LEG, SUPPORT_LEG_ANGLE);
  legMove(FOWARD_LEFT_LEG, MOVE_LEG_ANGLE);
  legMove(BACK_RIGHT_LEG, MOVE_LEG_ANGLE);
}

void step4() {
  const legAngle MOVE_LEG_ANGLE = {30, 0, 0};
  legMove(FOWARD_LEFT_LEG, MOVE_LEG_ANGLE);
  legMove(BACK_RIGHT_LEG, MOVE_LEG_ANGLE);
}
