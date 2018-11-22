////17/////////////////////////GOAL KEEPER///////////////////////////
//
//void BackToGoal(void)
//{
//  reduction = 0.7;
//  stop_out = 1;
//  Out = 'A';
//  if (abs(Compass) > 20) {
//    STOP();
//  }
//  else if (srfL < 40 && srfR < 40 &&  srfB < 40)
//  {
//    Move(0);
//  }
//  else if (srfL < 50 && srfR > 60)
//  {
//    if ((SORA || SORB) && (SOFA != 1 && SOLA != 1 && SOBA != 0)) Move(6);
//    else Move(4) ;
//  }
//  else if (srfR < 50 && srfL > 60)
//  {
//    if ((SOLA || SOLB) && (SOFA != 1 && SORA != 1 && SOBA != 0)) Move(10);
//    else Move(11);
//  }
//  else if (srfB > 60)
//  {
//    Move(8);
//  }
//  else if (srfB < 30)
//  {
//    Move(0);
//  }
//  else
//  {
//    if (big_sensor > noise)
//    {
//      EN();
//    }
//    else STOP();
//  }
//
//}
//
//19/////////////////////////srf///////////////////////////////////
void ultrasonic()
{
  Wire.beginTransmission(112);
  Wire.write(byte(0x00));
  Wire.write(byte(0x51));
  Wire.endTransmission();
  Wire.beginTransmission(113);
  Wire.write(byte(0x00));
  Wire.write(byte(0x51));
  Wire.endTransmission();
  Wire.beginTransmission(114);
  Wire.write(byte(0x00));
  Wire.write(byte(0x51));
  Wire.endTransmission();

  // ////////////////////////////////////////////////////////////////////////////////
  Wire.beginTransmission(112);
  Wire.write(byte(0x02));
  Wire.endTransmission();
  Wire.requestFrom(112, 2);
  if (2 <= Wire.available())
  {
    reader[3] = Wire.read();
    reader[3] = reader[3] << 8;
    reader[3] |= Wire.read();
  }
  Wire.beginTransmission(113);
  Wire.write(byte(0x02));
  Wire.endTransmission();
  Wire.requestFrom(113, 2);
  if (2 <= Wire.available())
  {
    reader[1] = Wire.read();
    reader[1] = reader[1] << 8;
    reader[1] |= Wire.read();
  }
  Wire.beginTransmission(114);
  Wire.write(byte(0x02));
  Wire.endTransmission();
  Wire.requestFrom(114, 2);
  if (2 <= Wire.available())
  {
    reader[2] = Wire.read();
    reader[2] = reader [2] << 8;
    reader[2] |= Wire.read();
  }

}

////12//////////////////////MOVE WIDTH//////////////////////////////
//void MoveWidth (void)
//{
//  if (big_sensor_num != 0 && big_sensor_num < 4 && big_sensor > noise && srfR > 145)
//  {
//    reduction = 0.5;
//    Move(4);
//  }
//
//  else if (big_sensor_num > 12 && big_sensor > noise && srfL > 145)
//  {
//    reduction = 0.5;
//    Move(12);
//  }
//  else
//  {
//    STOP();
//  }
//}
////////////////////
//void Move_Width (void)
//{
//  if (big_sensor_num > 0 && big_sensor_num < 4 && srfR > 80)
//  {
//    reduction = 0.5;
//    Move(4);
//  }
//  else if (big_sensor_num < 16 && big_sensor_num > 12 && srfL > 80)
//  {
//    reduction = 0.5;
//    Move(12);
//  }
//  else
//  {
//    STOP();
//  }
//}
