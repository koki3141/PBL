void walking(const pairLegs pair_legs1, const pairLegs pair_legs2);
void step1(const pairLegs pair_legs1, const pairLegs pair_legs2);
void step2(const pairLegs pair_legs1, const pairLegs pair_legs2);
void step3(const pairLegs pair_legs1, const pairLegs pair_legs2);
void step4(const pairLegs pair_legs1, const pairLegs pair_legs2);
void walkingToLeft();
void walkingToRight();

void runStairsClimbing() {
  walkingToRight();
}

void walkingToLeft() {
  const pairLegs FRONT_BACK_LEGS = {FRONT_LEG, BACK_LEG};
  const pairLegs RIGHT_LEFT_LEGS = {RIGHT_LEG, LEFT_LEG};
  walking(FRONT_BACK_LEGS, RIGHT_LEFT_LEGS);

}

void walkingToRight() {
  const pairLegs FRONT_BACK_LEGS = {FRONT_LEG, BACK_LEG};
  const pairLegs LEFT_RIGHT_LEGS = {LEFT_LEG, RIGHT_LEG};
  walking(FRONT_BACK_LEGS, LEFT_RIGHT_LEGS);
}

void walking(const pairLegs pair_legs1, const pairLegs pair_legs2) {
  step1(pair_legs1, pair_legs2);
  delay(1000);
  step2(pair_legs1, pair_legs2);
  delay(1000);

  step3(pair_legs1, pair_legs2);
  delay(1000);

  step4(pair_legs1, pair_legs2);
  delay(1000);
}

void step1(const pairLegs pair_legs1, const pairLegs pair_legs2) {
  Serial.println("step1");
  const legAngle SUPPORT_FRONT_LEG_ANGLE = { 0, 0, 0 };
  const legAngle SUPPORT_BACK_LEG_ANGLE = { 0, 0, 0 };
  const legAngle MOVE_FRONT_LEG_ANGLE = { 30, -10, -45 };
  const legAngle MOVE_BACK_LEG_ANGLE = { 60, -10, -45 };
  setLegAngle(pair_legs1.front, MOVE_FRONT_LEG_ANGLE);
  setLegAngle(pair_legs1.back, MOVE_BACK_LEG_ANGLE);
  setLegAngle(pair_legs2.front, SUPPORT_FRONT_LEG_ANGLE);
  setLegAngle(pair_legs2.back, SUPPORT_BACK_LEG_ANGLE);
}

void step2(const pairLegs pair_legs1, const pairLegs pair_legs2) {
  Serial.println("step2");
  const legAngle SUPPORT_LEG_ANGLE = { -40, -10, -10 };
  const legAngle MOVE_LEG_ANGLE = { 40, 0, 0 };
  setLegAngle(pair_legs1.front, MOVE_LEG_ANGLE);
  setLegAngle(pair_legs1.back, MOVE_LEG_ANGLE);
  setLegAngle(pair_legs2.front, SUPPORT_LEG_ANGLE);
  setLegAngle(pair_legs2.back, SUPPORT_LEG_ANGLE);
}

void step3(const pairLegs pair_legs1, const pairLegs pair_legs2) {
  Serial.println("step3");
  const legAngle SUPPORT_FRONT_LEG_ANGLE = { 0, 0, 0 };
  const legAngle SUPPORT_BACK_LEG_ANGLE = { 0, 0, 0 };
  const legAngle MOVE_FRONT_LEG_ANGLE = { 30, -10, -45 };
  const legAngle MOVE_BACK_LEG_ANGLE = { 60, -10, -45 };
  setLegAngle(pair_legs1.front, SUPPORT_FRONT_LEG_ANGLE);
  setLegAngle(pair_legs1.back, SUPPORT_BACK_LEG_ANGLE);
  setLegAngle(pair_legs2.front, MOVE_FRONT_LEG_ANGLE);
  setLegAngle(pair_legs2.back, MOVE_BACK_LEG_ANGLE);
}

void step4(const pairLegs pair_legs1, const pairLegs pair_legs2) {
  Serial.println("step4");
  const legAngle SUPPORT_LEG_ANGLE = { -40, -10, -10 };
  const legAngle MOVE_LEG_ANGLE = { 40, 0, 0 };
  setLegAngle(pair_legs1.front, SUPPORT_LEG_ANGLE);
  setLegAngle(pair_legs1.back, SUPPORT_LEG_ANGLE);
  setLegAngle(pair_legs2.front, MOVE_LEG_ANGLE);
  setLegAngle(pair_legs2.back, MOVE_LEG_ANGLE);
}

