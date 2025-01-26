bool KAR = 1;
void TempInit() {
  while ( NO_ERR != sensor.begin() ) {
    Serial.println("Communication with device failed, please check connection");
    delay(3000);
  }
  Serial.println("Begin ok!");
  sensor.setEmissivityCorrectionCoefficient(1.0);
  sensor.setI2CAddress(0x00);
  sensor.setMeasuredParameters(sensor.eIIR100, sensor.eFIR1024);
  sensor.enterSleepMode();
  delay(50);
  sensor.enterSleepMode(false);
  delay(200);
}

void Kar() {
 // if (KAR == 1) {
    float ambientTemp = sensor.getAmbientTempCelsius();
    float objectTemp = sensor.getObjectTempCelsius();
  //  Serial.println(objectTemp);
    if ((ambientTemp > 600 && objectTemp > -30 ) || (ambientTemp > 22 && objectTemp > 31)) {
      enc1 = 0;
      while (enc1 > -150) {
        motor(-30);
      }
      motor(0);
      Hand.write(0);
      Opening.write(150);
      playerCrow.play(1);
      timer1 = millis();
      while (millis() - timer1 < 500);
      Opening.write(20);
      motor(30);
      while (enc1 < 0);
      motor(0);
      KAR = 0;
    }
  }
//}
