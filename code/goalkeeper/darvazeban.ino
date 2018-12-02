///////////////////////////////srf
void ultrasonics()
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
}
// delay(70);
void ultrasonicr(void) {
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
  srfR = SRFReader[2];
  srfB = SRFReader[4];
  srfL = SRFReader[3];
}

void SRF()
{
    if (nointerrupt == 0)
  {
    interrupt++;
    if (interrupt == 3) {
      ultrasonics();
    }
    else if (interrupt == 6) {
      ultrasonicr();
      interrupt = 0;
    }
    set_s = spin_speed(1, 40, 15);
    set_m = spin_speed(1, 40, 15);
    if(s==1)
    {
    reduction=0.7;  
    }
     if(s==2)
    {
     reduction=0.7; 
    }
     if(s==3)
    {
     reduction=0.4; 
    }
     if(s==4)
    {
    reduction=0.5 ; 
    }
  }
Serial.println(n_cmp);
  //  SHOW_KAF();
//     Serial.println(" ");
//    Serial.print("b=");
//      Serial.print(srfB);
//    Serial.print(" l=");
//      Serial.print(srfL);
//    Serial.print(" r=");
//      Serial.print(srfR);
}
////17/////////////////////////GOAL KEEPER///////////////////////////
//
void BackToGoal(void)
{
s=3;
  //  stop_out = 1;

  if (abs(Compass) > 20) {
    STOP();
  }
  else if (srfL < 40 && srfR < 40 && srfB < 40)
  {
    Move(0);
  }
  else if (srfL < 70 && srfR > 60)
  {
    if ((SORA || SORB) && (SOFA != 1 && SOLA != 1 && SOBA != 0)) Move(6);
    else Move(4) ;
  }
  else if (srfR < 55 && srfL > 80)
  {
    if ((SOLA || SOLB) && (SOFA != 1 && SORA != 1 && SOBA != 0)) Move(10);
    else Move(12);
  }
  else if (srfB > 40)
  {
    Move(8);
  }
  else if (srfB < 30)
  {
    Move(0);
  }
  else
  {
    //        if (big_sensor>noise||big_sensor<distanceM||srfB<85)
    //        {
    //         Move_Width();
    //        }
    //        else
    STOP();

  }
}
// ////////////////////////////////////////////////////////////////////////////////
void Move_Width (void)
{
  digitalWrite(BUZ,HIGH);
  s=4;
  biggestt();
  if (big_sensor_num >= 0 && big_sensor_num <= 4 && srfR > 60)
  {
    Move(4);
  }
  else if (big_sensor_num < 16 && big_sensor_num >= 12 && srfL > 80)
  {
    Move(12);
  }

  else
  {
    BackToGoal();
  }
}
