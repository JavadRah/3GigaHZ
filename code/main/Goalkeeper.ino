////17/////////////////////////GOAL KEEPER///////////////////////////
//
void BackToGoal(void)
{
  ultrasonic();
  reduction = 0.3;
//  stop_out = 1;
  if (abs(Compass) > 20) {
    STOP();

  }
  else if (srfL < 40 && srfR < 40 && srfB < 40)
  {
    Move(0);

  }
  else if (srfL < 55 && srfR > 60)
  {
    //if ((SORA || SORB) && (SOFA != 1 && SOLA != 1 && SOBA != 0)) Move(6);
   // else
    Move(4) ;
  }
  else if (srfR < 55 && srfL > 80)
  {
    //if ((SOLA || SOLB) && (SOFA != 1 && SORA != 1 && SOBA != 0)) Move(10);
    //else
    Move(12);
  }
  else if (srfB > 45)
  {
    Move(8);

  }
  else if (srfB < 40)
  {
    Move(0);
  }
  else
  {
//    if (big_sensor > noise)
//    {
//      EN();
//    }
//    else 
// digitalWrite(BUZ,HIGH);
// delay(50);
//  digitalWrite(BUZ,LOW);
      STOP();
  }

}
//
//19/////////////////////////srf///////////////////////////////////
void ultrasonic()
{
  Wire.beginTransmission(112);
  Wire.write(byte(0x00));
  Wire.write(byte(0x51));
  Wire.endTransmission();
  Wire.beginTransmission(115);
  Wire.write(byte(0x00));
  Wire.write(byte(0x51));
  Wire.endTransmission();
  Wire.beginTransmission(114);
  Wire.write(byte(0x00));
  Wire.write(byte(0x51));
  Wire.endTransmission();
 delay(70);
  // ////////////////////////////////////////////////////////////////////////////////
  Wire.beginTransmission(112);
  Wire.write(byte(0x02));
  Wire.endTransmission();
  Wire.requestFrom(112, 2);
  if (2 <= Wire.available())
  {
    SRFReader[3] = Wire.read();
    SRFReader[3] = SRFReader[3] << 8;
    SRFReader[3] |= Wire.read();
  }
  Wire.beginTransmission(115);
  Wire.write(byte(0x02));
  Wire.endTransmission();
  Wire.requestFrom(115, 2);
  if (2 <= Wire.available())
  {
    SRFReader[4] = Wire.read();
    SRFReader[4] = SRFReader[4] << 8;
    SRFReader[4] |= Wire.read();
  }
  Wire.beginTransmission(114);
  Wire.write(byte(0x02));
  Wire.endTransmission();
  Wire.requestFrom(114, 2);
  if (2 <= Wire.available())
  {
    SRFReader[2] = Wire.read();
    SRFReader[2] = SRFReader [2] << 8;
    SRFReader[2] |= Wire.read();
  }
 srfR= SRFReader[2];
 srfB= SRFReader[4];
 srfL=SRFReader[3];

}
void SHOWSRF()
{
  sprintf (srfr, "%03d", SRFReader[2]);
  Serial.print("srfr=");
  Serial.println(srfr);
  sprintf (srfb, "%03d", SRFReader[4]);
  Serial.print("srfb=");
  Serial.println(srfb);
  sprintf (srfl, "%03d", SRFReader[3]);
  Serial.print("srfl=");
  Serial.println(srfl);

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
void Move_Width (void)
{
  ultrasonic();
  biggestt();
  if (big_sensor_num >= 0 && big_sensor_num <= 4 && srfR>55)
  {
    reduction = 0.5;
    Move(4);

    
  }
  else if (big_sensor_num < 16 && big_sensor_num >= 12 && srfL > 60)
  {
    reduction = 0.5;
    Move(12);

  }
  else
  {
    BackToGoal();
  }
}
