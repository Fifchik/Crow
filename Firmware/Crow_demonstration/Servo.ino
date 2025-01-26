#define pinServoEyeLeft 35
#define pinServoEyeRight 13
#define pinServoWingPlaneLeft 9
#define pinServoWingPlaneRight 46
#define pinServoWingTurnLeft 5
#define pinServoWingTurnRight 6
#define pinServoStrela 48
#define pinServoHand 8
#define pinServoOpening 7

void initServo() {
  Strela.attach(pinServoStrela);
  Hand.attach(pinServoHand);
  Opening.attach(pinServoOpening);
  EyeRight.attach(pinServoEyeRight);
  EyeLeft.attach(pinServoEyeLeft);
  PlaneLeft.attach(pinServoWingPlaneLeft);
  PlaneRight.attach(pinServoWingPlaneRight);
  TurnLeft.attach(pinServoWingTurnLeft);
  TurnRight.attach(pinServoWingTurnRight);
}

void ServoStartPosition() {
  Hand.write(100);
  Strela.write(90);
  PlaneLeft.write(0);
  PlaneRight.write(180);
  TurnLeft.write(0);
  TurnRight.write(180);
  EyeLeft.write(120);
  EyeRight.write(20);
  Opening.write(30);
}
