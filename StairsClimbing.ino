void runWalk();
void step1();
void step2();
void step3();
void step4();


void runStairsClimbing() {
  setInitialPosition(STAIRS_ClIMBING_INITAL_POSITION);
  runWalk();
}

void runWalk() {
  standardPosition();
  delay(1000);

  step1();
  delay(500);

  step2();
  delay(1000);

  standardPosition();
  delay(1000);

  step3();
  delay(500);
  
  step4();
  delay(1000);
}


void step1() {
  Serial.println("step1");
  const legAngle SUPPORT_LEG_ANGLE = {-10, 0, 0};
  const legAngle SET_LEG_ANGLE = {30, 0, -30};
  setLegAngle(FOWARD_RIGHT_LEG, SET_LEG_ANGLE);
  setLegAngle(BACK_LEFT_LEG, SET_LEG_ANGLE);
  setLegAngle(FOWARD_LEFT_LEG, SUPPORT_LEG_ANGLE);
  setLegAngle(BACK_RIGHT_LEG, SUPPORT_LEG_ANGLE);
}

void step2() {
  Serial.println("step2");
  const legAngle SET_LEG_ANGLE = {30, 0, 0};
  setLegAngle(FOWARD_RIGHT_LEG, SET_LEG_ANGLE);
  setLegAngle(BACK_LEFT_LEG, SET_LEG_ANGLE);
}

void step3() {
  Serial.println("step3");
  const legAngle SUPPORT_LEG_ANGLE = {-10, 0, 0};
  const legAngle SET_LEG_ANGLE = {30, 0, -30};
  setLegAngle(FOWARD_RIGHT_LEG, SUPPORT_LEG_ANGLE);
  setLegAngle(BACK_LEFT_LEG, SUPPORT_LEG_ANGLE);
  setLegAngle(FOWARD_LEFT_LEG, SET_LEG_ANGLE);
  setLegAngle(BACK_RIGHT_LEG, SET_LEG_ANGLE);
}

void step4() {
  Serial.print("step4");
  const legAngle SET_LEG_ANGLE = {30, 0, 0};
  setLegAngle(FOWARD_LEFT_LEG, SET_LEG_ANGLE);
  setLegAngle(BACK_RIGHT_LEG, SET_LEG_ANGLE);
}
