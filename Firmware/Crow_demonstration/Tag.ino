void camera() {
  if (Serial3.available()) {
    int CamOut = Serial3.read();
    if (CamOut == 1) {
      flag = 1;
      Serial.println("flag - 1");
    }
    else if (CamOut == 2) {
      flag = 2;
      Serial.println("flag - 2");
    }
  }
}
void tag() {
  // enc1 = 0;
  float errOld, err;
  while (Serial3.available() && flag == 1) {
    static float kP = 1.75;
    static float k = 0.6;
    static float kd = 0.5;
    int CamOut = Serial3.read();
    errOld = err;
    err = (CamOut - 80) - ((enc1 * -1) / kP);
    float u = (err * k) + ((err - errOld) * kd);
    if (CamOut == 1) {
      flag = 1;
      Serial.println("flag - 1");
    }
    else if (CamOut == 2) {
      flag = 2;
      Serial.println("flag - 2");
    }
    else if (CamOut == 0) {
        flag = 0;
      }
    Serial.println(u);
    motor(-u);

  }
}
