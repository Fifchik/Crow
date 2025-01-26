#include <Wire.h>
#include <DFRobot_MLX90614.h>
DFRobot_MLX90614_I2C sensor(0x00, &Wire);
#include <DFRobotDFPlayerMini.h>
#include "Adafruit_NeoPixel.h"
DFRobotDFPlayerMini playerCrow;
#include<Servo.h>
#include "APDS9960.h"
#define APDS9960_INT    18
#define PIN  29          // указываем пин для подключения ленты
#define NUMPIXELS 8  // указываем количество светодиодов в ленте
#define PIN1  27
#define NUMPIXELS1 8
Adafruit_NeoPixel strip (NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip1 (NUMPIXELS1, PIN1, NEO_GRB + NEO_KHZ800);
unsigned long timer1 = 0;
volatile int32_t enc1 = 0;
int flag = 0;
bool f = 1;
Servo Strela;      // 130-shot
Servo Hand;       //100-up,0-down
Servo Opening;   //0-close,50-open
Servo EyeRight; //20-open,100-close
Servo EyeLeft;  //30-close,100-open
Servo PlaneLeft; //от 0 до 90
Servo PlaneRight; //от 180 до 90
Servo TurnLeft;   //от 0 до 150
Servo TurnRight; //от 180 до 85

void handleGesture() {
  if (apds.isGestureAvailable() ) {
    switch ( apds.readGesture() ) {
      case DIR_UP:
        ServoStartPosition();
        tailClosed();
        YellowEyes();
        f = 0;
        break;
      case DIR_LEFT:
        //  tailClosed();
        enc1 = 0;
        motor(30);
        while (enc1 < 200);
        motor(0);
        break;
      case DIR_RIGHT:
        enc1 = 0;
        motor(-30);
        while (enc1 > -200);
        motor(0);
        break;
      case DIR_DOWN:
        Actor();
        Planes();
        Tails();
        hand();
        Open();
        Eyes();
        f = 0;
        //playerCrow.play(1);

        //Serial.println(f);
        break;
      default:
        f = 0;
        //Serial.println("NONE");
    }
  }
}

void setup() {
  motorInit();
  TailInit();
  EncoderInit();
  SerialInit();
  EyesInit();
  PlayerInit();
  YellowEyes();
  initServo();
  ServoStartPosition();
  APDSinit();
  initAPDS();
  TempInit();
  colibrate();
}
void loop() {
   f = 1;
  EyesMovement();
  Kar();
  Cam();
}
