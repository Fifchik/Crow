void hand() {
  playerCrow.play(6);
  for (int l = 0; l < 6; l++) {
    Hand.write(100);
    delay(1000);
    Hand.write(0);
    delay(1000);
  }
}
