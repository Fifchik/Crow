void Planes() {
  playerCrow.play(3);
  for (int p = 0; p < 2; p++) {
    TurnLeft.write(150);
    TurnRight.write(85);
    delay(1000);
    TurnLeft.write(0);
    TurnRight.write(180);
    delay(1000);
  }
  TurnLeft.write(150);
  TurnRight.write(85);
  delay(100);
  for (int k = 0; k < 2; k++) {
    PlaneLeft.write(90);
    PlaneRight.write(90);
    delay(1000);
    PlaneLeft.write(0);
    PlaneRight.write(180);
    delay(1000);
  }
}
