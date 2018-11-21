
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
