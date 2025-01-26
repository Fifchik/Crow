void Actor() {
  enc1 = 0;
  playerCrow.play(2);
  for (int i = 0; i < 4; i++) {
    while (enc1 < 50) {
      motor(25);
      Opening.write(20);
      delay(350);
      Opening.write(0);
      delay(350);
    }
    timer1 = millis();
    while (millis() - timer1 < 703) {
      motor(0);
      Opening.write(20);
      delay(350);
      Opening.write(0);
      delay(350);
    }
    timer1 = millis();
    while (enc1 > -80) {
      motor(-25);
      Opening.write(20);
      delay(350);
      Opening.write(0);
      delay(350);
    }
    timer1 = millis();
    while (millis() - timer1 < 703) {
      motor(0);
      Opening.write(20);
      delay(350);
      Opening.write(0);
      delay(350);
    }
    timer1 = millis();
  }

  while (enc1 < 0) {
    motor(35);
  }
  motor(0);
  delay(1000);
}
