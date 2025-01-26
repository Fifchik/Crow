#define tCLK 2
#define tDT 40
#define tINB 31
#define tINA 39
#define tPWM 10

int tail_lim = 4300;
int tail_Clos = 10;
volatile int32_t enc = 0;

int TailCurrentLimit = 0;

void isrT() {
  if (digitalRead(tDT))
    enc++;
  else
    enc--;
}
void TailInit(){
  pinMode(A2, INPUT);
  pinMode(tDT, INPUT);
  pinMode(tCLK, INPUT);
  pinMode(tPWM, OUTPUT);
  pinMode(tINB, OUTPUT);
  pinMode(tINA, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(tCLK), isrT, RISING);
}

void motorTail (int v1) {
  analogWrite(tPWM, abs(v1));

  if (v1 > 0) {
    digitalWrite(tINB, 1);
    digitalWrite(tINA, 0);
  }
  if (v1 < 0) {
    digitalWrite(tINB, 0);
    digitalWrite(tINA, 1);
  }
  if (v1 == 0) {
    digitalWrite(tINB, 1);
    digitalWrite(tINA, 1);
  }

}

void tailOpen() {
  while (abs(enc) < tail_lim) {
    motorTail(-30);
  }
  while (abs(enc) > tail_lim) {
    motorTail(130);
  }
  motorTail(0);
}

void tailClosed() {
  while (abs(enc) > tail_Clos) {
    motorTail(130);
  }
  while (abs(enc) < tail_Clos) {
    motorTail(-30);
  }
  motorTail(0);
}


void colibrate() {
  while (TailCurrentLimit <= 50) {
    TailCurrentLimit = analogRead(A2);
    motorTail(100);
    delay(130);
  }
  enc = 0;
  motorTail(0);
}
