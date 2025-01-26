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
   float ambientTemp = sensor.getAmbientTempCelsius();
   float objectTemp = sensor.getObjectTempCelsius();
  if ((ambientTemp > 600 && objectTemp > -60) || (ambientTemp > 24 && objectTemp > 29)) {
    enc1 = 0;
    motor(30);
    while (enc1 < 150);
    motor(0);
    Hand.write(0);
    Opening.write(150);
    playerCrow.play(1);
  }
}
