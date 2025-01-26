void Cam() {
  if (Serial3.available()) {
    static int tg;
    while (Serial3.available()) {
      tg = Serial3.read();

      if (tg > 0 && tg != 2) {
        flag = 1;
        Serial.println("flag - 1");
      }
      else if (tg == 2) {
        flag = 2;
        Serial.println("flag - 2");
      }
      else if (tg == 0) {
        flag = 0;
      }
      switch (flag) {
        case 1:
          Serial.println("Case - 1");
          while (flag == 1) {
            tag();
          }
          motor(0);
          break;
        case 2:
          EyeLeft.write(120);
          EyeRight.write(20);
          while (f) {
            handleGesture();
            if (isr_flag == 1 ) {
              detachInterrupt(5);
              handleGesture();
              isr_flag = 0;
              attachInterrupt(5, interruptRoutine, FALLING);
            }
          }
          break;
        default:
          Serial.println("NONE");
      }
    }
  }
}
