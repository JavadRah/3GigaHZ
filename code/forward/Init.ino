////4//////Calibrate///
void Calibrate (void)
{
  for (int k = 0; k < 4; k++)
  {
    //    if (k == 0) {
    //      STOP();
    //      delay(110);
    //      Wire.beginTransmission(address);
    //      digitalWrite(BUZ, HIGH);
    //      delay(100);
    //      Wire.write(15);
    //      Wire.write(0xff);
    //      Wire.endTransmission();
    //      digitalWrite(BUZ, LOW);
    //      continue;
    //    }
    //    STOP();
    //    delay(100);
    //    MOTOR(1023, 1023, 1023, 1023);
    //    delay(110);
    //    STOP();
    nointerrupt = 100;
    Wire.beginTransmission(address);
    digitalWrite(BUZ, HIGH);
    delay(100);
    Wire.write(15);
    Wire.write(0xff);
    Wire.endTransmission();
    digitalWrite(BUZ, LOW);
    delay(3000);
  }
  nointerrupt = 0;
}
////5//////COMPASS////
void Read_Compass()
{
  Wire.beginTransmission(address);  ////starts communication with cmp03
  Wire.write(2);                    /////sends the register we wish to read
  Wire.endTransmission();
  Wire.requestFrom(address, 2);     /////requests high byte
  n_cmp = ((Wire.read() << 8) | Wire.read());
  Wire.endTransmission();
  n_cmp = map(n_cmp, 0, 3600, 0, 1023);
}
////6/////////////CMP////////////////////////////////////
signed int CMPS(void)
{
  int b, a;
  Read_Compass();
  a =  n_cmp - nSETUP;
  if (a > 0)
  {
    b = a;
  }
  else
  {
    b = a + 1023;
  }
  if (b > 512)
  {
    b = b - 1023;
  }
  else
  {
    b = b;
  }

  Compass = -b;
  return Compass;
}
////7/////////////////SPIN SPEED////////////////////////////////
signed int spin_speed(int divided_value, int added_value, int zero_degree)
{
  int compass_input = 0, compass_output = 0;
  CMPS();
  compass_input = Compass;
  if ( compass_input >= zero_degree )
    compass_output = (compass_input / divided_value) + (added_value * 1.5);
  else if (compass_input <= (-zero_degree) )
    compass_output = (compass_input) / divided_value - added_value;
  else
    compass_output = 0;
  return compass_output;
}
/////////////////////////////////////////////////////////////////
void boogh(void)
{
  digitalWrite(BUZ, HIGH);
  delay(100);
  digitalWrite(BUZ, LOW);
  delay(100);
  digitalWrite(BUZ, HIGH);
  delay(100);
  digitalWrite(BUZ, LOW);
  delay(100);
}

///////////////////////////////////////////////////////////////////

void Counter()
{
  if (nointerrupt == 0)
  {
    set_s = spin_speed(1, 40, 15);
    set_m = spin_speed(1, 40, 15);
    Serial.println(Compass);
    reduction =  0.7;
  }
}
