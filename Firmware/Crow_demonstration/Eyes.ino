void EyesInit() {
  strip.begin();                     // инициализируем ленту
  strip.setBrightness(255);  // указываем яркость светодиодов (максимум 255)
  strip1.begin();
  strip1.setBrightness(255);
}

void EyesMovement() {
  for (int i = 120; i > 30; i -= 5) {
    EyeLeft.write(i);
    int p = map(i, 120, 30, 20, 100);
    EyeRight.write(p);
    timer1 = millis();
    while (millis() - timer1 < 100);
  }
  timer1 = millis();
  while (millis() - timer1 < 700);
  for (int i = 30; i < 120; i += 5) {
    EyeLeft.write(i);
    int p = map(i, 30, 120, 100, 20);
    EyeRight.write(p);
    timer1 = millis();
    while (millis() - timer1 < 100);
  }
  timer1 = millis();
  while (millis() - timer1 < 700);
}

void Eyes() {
  playerCrow.play(5);
  for (int i = 0; i <= NUMPIXELS; i++) {
    strip1.setPixelColor(i, 255, 150, 0);
    strip1.show();
    strip.setPixelColor(i, 255, 150, 0);
    strip.show();
  }
  delay(6000);
  for (int i = 0; i <= NUMPIXELS; i++) {
    strip1.setPixelColor(i, 51, 51, 255);
    strip1.show();
    strip.setPixelColor(i, 51, 51, 255);
    strip.show();
  }
  delay(5000);
  TurnLeft.write(150);
  TurnRight.write(85);
  Hand.write(0);
  delay(100);
  for (int i = 0; i <= NUMPIXELS; i++) {
    strip1.setPixelColor(i, 204, 0, 204);
    strip1.show();
    strip.setPixelColor(i, 204, 0, 204);
    strip.show();
  }

  for (int k = 0; k < 2; k++) {
    PlaneLeft.write(90);
    PlaneRight.write(90);
    delay(500);
    PlaneLeft.write(0);
    PlaneRight.write(180);
    delay(500);
  }
  for (int e = 0; e < 4; e++) {
    EyeRight.write(100);
    EyeLeft.write(30);
    delay(500);
    EyeRight.write(20);
    EyeLeft.write(120);
    delay(500);
  }
}

void YellowEyes() {
  for (int i = 0; i <= NUMPIXELS; i++) {
    strip1.setPixelColor(i, 255, 150, 0);
    strip1.show();
    strip.setPixelColor(i, 255, 150, 0);
    strip.show();
  }
}
