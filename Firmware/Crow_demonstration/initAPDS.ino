void APDSinit() {
  pinMode(APDS9960_INT, INPUT);
  attachInterrupt(5, interruptRoutine, FALLING);
}

void initAPDS() {
  if (apds.init() ) {
    Serial.println(F("APDS-9960 initialization complete"));
  }
  else {
    Serial.println(F("Something went wrong during APDS-9960 init!"));
  }

  if ( apds.enableGestureSensor(true) ) {
    Serial.println(F("Gesture sensor is now running"));
  }
  else {
    Serial.println(F("Something went wrong during gesture sensor init!"));
  }
}
