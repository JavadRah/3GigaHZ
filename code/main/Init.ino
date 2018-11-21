//4/////////////MOTOR///////////////////////////////
void MOTOR(int pwmlf, int pwmlb, int pwmrf, int pwmrb)
{

  pwmlf = pwmlf * 1 * reduction;
  pwmlb = pwmlb * 1 * reduction;
  pwmrf = pwmrf * 1 * reduction;
  pwmrb = pwmrb * 1 * reduction;


  if (pwmlf > 1023)   pwmlf = 1023;
  if (pwmlb > 1023)   pwmlb = 1023;
  if (pwmrb > 1023)   pwmrb = 1023;
  if (pwmrf > 1023)   pwmrf = 1023;
  if (pwmlf < -1023)   pwmlf = -1023;
  if (pwmlb < -1023)   pwmlb = -1023;
  if (pwmrb < -1023)   pwmrb = -1023;
  if (pwmrf < -1023)   pwmrf = -1023;

  //*********************Left's MOTOR MAIN
  if (pwmlf > 0)
  {
   digitalWrite(GPIO_MLF,LOW);
    analogWrite(PWM_MLF,pwmlf);
  }
  else if (pwmlf < 0)
  {
   digitalWrite(GPIO_MLF,HIGH);
    analogWrite(PWM_MLF,1023+pwmlf);
  }
  else if (pwmlf == 0)
  {
   //digitalWrite(mlf,HIGH);
    analogWrite(PWM_MLF,0);
  }

  //*********************Left's MOTOR MAIN
  if (pwmlb > 0)
  {
    digitalWrite(GPIO_MLB,LOW);
    analogWrite(PWM_MLB,pwmlb);
  }
  else if (pwmlb < 0)
  {
   digitalWrite(GPIO_MLB,HIGH);
    analogWrite(PWM_MLB,pwmlb+1023);
  }
  else if (pwmlb == 0)
  {
    //digitalWrite(mlb,HIGH);
    analogWrite(PWM_MLB,0);
  }
  //*********************Right's MOTOR MAIN
  if (pwmrf > 0)
  {
   digitalWrite(GPIO_MRF,LOW);
    analogWrite(PWM_MRF,pwmrf);
  }
  else if (pwmrf < 0)
  {
   digitalWrite(GPIO_MRF,HIGH);
    analogWrite(PWM_MRF,pwmrf+1023);
  }
  else if (pwmrf == 0)
  {
   //digitalWrite(mrf,HIGH);
    analogWrite(PWM_MRF,0);
  }
  //*********************Right's MOTOR MAIN
  if (pwmrb > 0)
  {digitalWrite(GPIO_MRB,LOW);
    analogWrite(PWM_MRB,pwmrb);
  }
  else if (pwmrb < 0)
  {
    digitalWrite(GPIO_MRB,HIGH);
    analogWrite(PWM_MRB,pwmrb+1023);

  }
  else if (pwmrb == 0)
  {
    //digitalWrite(mrb,HIGH);
    analogWrite(PWM_MRB,0);
  }
}
//
//
////5//////COMPASS////
//void Read_Compass()
//{
//  Wire.beginTransmission(address);  ////starts communication with cmp03
//  Wire.write(1);                    /////sends the register we wish to read
//  Wire.endTransmission();
//  Wire.requestFrom(address, 1);     /////requests high byte
//  Compass = Wire.read();
//  Wire.endTransmission();
//}
////6/////////////CMP////////////////////////////////////
//signed int CMP(void)
//{
//  int b, a;
//  Read_Compass();
//  a = n_cmp - SETUP;
//  if (a > 0)
//  {
//    b = a;
//  }
//  else
//  {
//    b = a + 256;
//  }
//  if (b > 128)
//  {
//    b = b - 256;
//  }
//  else
//  {
//    b = b;
//  }
//  Compass = -b;
//  return -b;
//}
////7/////////////////SPIN SPEED////////////////////////////////
//signed int spin_speed(int divided_value, int added_value, int zero_degree)
//{
//  int compass_input = 0, compass_output = 0;
//  CMP();
//  compass_input = Compass;
//  if ( compass_input >= zero_degree )
//    compass_output = (compass_input / divided_value) + (added_value * 1.5);
//  else if (compass_input <= (-zero_degree) )
//    compass_output = (compass_input) / divided_value - added_value;
//  else
//    compass_output = 0;
//  return compass_output;
//}
///////////////////////////////////////////////////////////////////
