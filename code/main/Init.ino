//4/////////////MOTOR///////////////////////////////
void MOTOR(int pwmlf, int pwmlb, int pwmrf, int pwmrb)
{

  pwmlf = pwmlf * 1 * reduction;
  pwmlb = pwmlb * 1 * reduction;
  pwmrf = pwmrf * 1 * reduction;
  pwmrb = pwmrb * 1 * reduction;


  if (pwmlf > 255)   pwmlf = 255;
  if (pwmlb > 255)   pwmlb = 255;
  if (pwmrb > 255)   pwmrb = 255;
  if (pwmrf > 255)   pwmrf = 255;
  if (pwmlf < -255)   pwmlf = -255;
  if (pwmlb < -255)   pwmlb = -255;
  if (pwmrb < -255)   pwmrb = -255;
  if (pwmrf < -255)   pwmrf = -255;

  //*********************Left's MOTOR MAIN
  if (pwmlf > 0)
  {
    mlf = 0;
    PWM_MLF = pwmlf;
  }
  else if (pwmlf < 0)
  {
    mlf = 1;
    PWM_MLF = 255 + pwmlf;
  }
  else if (pwmlf == 0)
  {
    mlf = 1;
    PWM_MLF = 255;
  }

  //*********************Left's MOTOR MAIN
  if (pwmlb > 0)
  {
    mlb = 0;
    PWM_MLB = pwmlb;
  }
  else if (pwmlb < 0)
  {
    mlb = 1;
    PWM_MLB = 255 + pwmlb;
  }
  else if (pwmlb == 0)
  {
    mlb = 1;
    PWM_MLB = 255;
  }
  //*********************Right's MOTOR MAIN
  if (pwmrf > 0)
  {
    mrf = 0;
    PWM_MRF = pwmrf;
  }
  else if (pwmrf < 0)
  {
    mrf = 1;
    PWM_MRF = 255 + pwmrf;
  }
  else if (pwmrf == 0)
  {
    mrf = 1;
    PWM_MRF = 255;
  }
  //*********************Right's MOTOR MAIN
  if (pwmrb > 0)
  {
    mrb = 0;
    PWM_MRB = pwmrb;
  }
  else if (pwmrb < 0)
  {
    mrb = 1;
    PWM_MRB = 255 + pwmrb;

  }
  else if (pwmrb == 0)
  {
    mrb = 1;
    PWM_MRB = 255;
  }
}


//5//////COMPASS////
void Read_Compass()
{
  Wire.beginTransmission(address);  ////starts communication with cmp03
  Wire.write(1);                    /////sends the register we wish to read
  Wire.endTransmission();
  Wire.requestFrom(address, 1);     /////requests high byte
  Compass = Wire.read();
  Wire.endTransmission();
}
//6/////////////CMP////////////////////////////////////
signed int CMP(void)
{
  int b, a;
  Read_Compass();
  a = n_cmp - SETUP;
  if (a > 0)
  {
    b = a;
  }
  else
  {
    b = a + 256;
  }
  if (b > 128)
  {
    b = b - 256;
  }
  else
  {
    b = b;
  }
  Compass = -b;
  return -b;
}
//7/////////////////SPIN SPEED////////////////////////////////
signed int spin_speed(int divided_value, int added_value, int zero_degree)
{
  int compass_input = 0, compass_output = 0;
  CMP();
  compass_input = Compass;
  if ( compass_input >= zero_degree )
    compass_output = (compass_input / divided_value) + (added_value * 1.5);
  else if (compass_input <= (-zero_degree) )
    compass_output = (compass_input) / divided_value - added_value;
  else
    compass_output = 0;
  return compass_output;
}

