#define INB 43
#define INA 49
#define PWM 11
void motorInit() {
  pinMode(PWM, OUTPUT);
  pinMode(INB, OUTPUT);
  pinMode(INA, OUTPUT);
}

void motor (int v1)
{
  analogWrite(PWM, abs(v1));

  if (v1 > 0)
  {
    digitalWrite(INB, 1);
    digitalWrite(INA, 0);
  }
  if (v1 < 0)
  {
    digitalWrite(INB, 0);
    digitalWrite(INA, 1);
  }
  if (v1 == 0)
  {
    digitalWrite(INB, 1);
    digitalWrite(INA, 1);
  }

}
