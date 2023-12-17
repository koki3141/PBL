void runClime() {
  runWalk();
}

void runWalk(){
  standState();
  delay(1000);
  STEP1();
  delay(100);
  STEP2();
  delay(100);
  standState();
  delay(100);
  STEP3();
  delay(100);
  STEP4();
  delay(100);

}

void standState(){
  const legAngle STAND_LEG_ANGLE = {-20, 20, 30};
  legMove(FOWARD_RIGHT_LEG, STAND_LEG_ANGLE);
  legMove(FOWARD_LEFT_LEG, STAND_LEG_ANGLE);
  legMove(BACK_RIGHT_LEG, STAND_LEG_ANGLE);
  legMove(BACK_LEFT_LEG, {STAND_LEG_ANGLE);
}

void STEP1(){
  const legAngle SUPPORT_LEG_ANGLE = {-30, 20, 20};
  const legAngle MOVE_LEG_ANGLE = {-10, 40, 50};
  legMove(FOWARD_RIGHT_LEG, SUPPORT_LEG_ANGLE);
  legMove(FOWARD_LEFT_LEG, MOVE_LEG_ANGLE);
  legMove(BACK_RIGHT_LEG, SUPPORT_LEG_ANGLE);
  legMove(BACK_LEFT_LEG, MOVE_LEG_ANGLE);
}

void STEP2(){
  const legAngle MOVE_LEG_ANGLE = {-10, 40, 30};
  legMove(FOWARD_LEFT_LEG, MOVE_LEG_ANGLE);
  legMove(BACK_LEFT_LEG, MOVE_LEG_ANGLE);
}

void STEP3(){
  const legAngle SUPPORT_LEG_ANGLE = {-30, 20, 20};
  const legAngle MOVE_LEG_ANGLE = {-10, 40, 50};
  legMove(FOWARD_RIGHT_LEG, MOVE_LEG_ANGLE);
  legMove(FOWARD_LEFT_LEG, SUPPORT_LEG_ANGLE);
  legMove(BACK_RIGHT_LEG, MOVE_LEG_ANGLE);
  legMove(BACK_LEFT_LEG, SUPPORT_LEG_ANGLE);

}

void STEP4(){
  const legAngle MOVE_LEG_ANGLE = {-10, 40, 30};
  legMove(FOWARD_RIGHT_LEG, MOVE_LEG_ANGLE);
  legMove(BACK_RIGHT_LEG, MOVE_LEG_ANGLE);
}
