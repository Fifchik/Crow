void Tails() {
  playerCrow.play(4);
  tailOpen();
  enc1 = 0;
  while (enc1 < 200) {
    motor(30);
  }
  while (enc1 > -200) {
    motor(-30);
  }
  while (enc1 < 0) {
    motor(30);
  }
  motor(0);

  //  delay(2900);
  //  tailClosed();
}
