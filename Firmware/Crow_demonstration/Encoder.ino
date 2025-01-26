#define CLK 3
#define DT 41
void EncoderInit(){
  pinMode(DT, INPUT);
  pinMode(CLK, INPUT);
  attachInterrupt(digitalPinToInterrupt(CLK), isr, RISING);
}
void isr() {
  if (digitalRead(DT))
  {
    enc1++;
  }
  else
  {
    enc1--;
  }
}
