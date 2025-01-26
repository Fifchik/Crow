void Open() {
  playerCrow.play(7);
  for (int l = 0; l < 5; l++) {
    Opening.write(50);
    delay(1000);
    Opening.write(0);
    delay(1000);
  }
}
