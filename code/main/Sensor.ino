////////////////////////////////////////////////////////////////////////////////

////1////////////////////////////////////////////////
unsigned int read_adc(int c) 
{
  int o = analogRead(c);
//  float p = (1023 * o) / 5;
  return o;
}
unsigned int  convert_adc(int Sensor) {

  AD3 = (((Sensor) / 1) % 2);
  AD2 = (((Sensor) / 2) % 2);
  AD1 = (((Sensor) / 4) % 2);
  AD0 = (((Sensor) / 8));
  return read_adc(14);
}
void Kaf_setup (void)
 {
//    refreshs ();
    Sofa=analogRead(34);
    Sofb=analogRead(33);
    Sola=analogRead(35);
    Solb=analogRead(36);
    Sora=analogRead(37);
    Sorb=analogRead(38);
    Soba=analogRead(32);
    Sobb=analogRead(31);
  
    kaf_F [0] =  Sofa ;
    kaf_F [1] =  Sofb ;

    kaf_R [0] =  Sora ;
    kaf_R [1] =  Sorb ;

    kaf_B [0] =  Soba ;
    kaf_B [1] =  Sobb ;

    kaf_L [0] =  Sola ;
    kaf_L [1] =  Solb ;}
////3///////////////////////////////////////////////
void set_bits(void)
{
//  int SOFA=34,SOFB=33,SORA=37,SORB=38,SOLA=35,SOLB=36,SOBA=32,SOBB=31
  ////////////////////Kaf
  kaf_F[0] =  analogRead(34);
  kaf_F[1] =  analogRead(33);

  kaf_R[0] = analogRead(18);
  kaf_R[1] = analogRead(19);

  kaf_B[0] = analogRead(22);
  kaf_B[1] = analogRead(23);

  kaf_L[0] =  analogRead(20);
  kaf_L[1] =  analogRead(21);
int fa,fb;
  //////////////////out of bound 1
 F_noise[0]= kaf_F[0] -20;
 F_noise [1]= kaf_F[1] - 45;
    
  if (R_noise[0]>=0)  {Sora = 1;}
  else  { Sora = 0;}

  if ( F_noise[0]>=0)  fa = 1;
  else   fa = 0;
  Serial.println(fa);
  if ( L_noise[0]>=0)  Sola = 1;
  else   Sola = 0;

  if ( B_noise[0]>=0)  Soba = 1;
  else   Soba = 0;

  //////////////////out of bound 2
  if ( R_noise[1]>=0)  Sorb = 1;
  else   Sorb = 0;

  if (F_noise[1]>=0)  fb = 1;
  else   fb = 0;

  if ( L_noise[1]>=0)  Solb = 1;
  else   Solb = 0;

  if ( B_noise[1]>=0)  Sobb = 1;
  else   Sobb = 0;
}

//void refreshs(void)
//{
//  int k;
//  for (k = 0; k < 16; k++)
//  {
//    SENSOR[k] = 1023 - analogRead(k);
//    if (SENSOR[k] > 1000) SENSOR[k] = 0;
//  }
//
//
//}
////14//////////////////////////VOLTAGE BATTERY/////////////////////////////
//void get_battery_voltage()
//{
//  battery_voltage = (FEEDBACK * 12.7) / 524;
//}
////20////////////////////BIG SENSOR/////////////////////////////////
//void biggest(void)
//{
//  int i, c;
//  int MAX = 0;
//  for (i = 0; i < 16; i++)
//  {
//    if (MAX < SENSOR[i])
//    {
//      c = i;
//      MAX = SENSOR[i];
//    }
//  }
//  big_sensor = MAX;
//  big_sensor_num = c;
//
//}

//
//    L_noise [0]= kaf_L[0] - 20;
//    L_noise [1]= kaf_L[1] - 25;
//
//    R_noise [0]= kaf_R[0] - 20;
//    R_noise [1]= kaf_R[1] - 25;
//
//
   
//
//    B_noise [0]= kaf_B[0] - 25;
//    B_noise [1]= kaf_B[1] - 25;

///////////////////////SHOW Kaf/////////////////////////////////////
void SHOWKAF(void)
{
     Kaf_setup();
     Serial.print("KAF FA:");
     Serial.println(kaf_F[0]);
     delay(50);

//     Serial.print("KAF R:");
//     Serial.println(kaf_R[0]);
//     delay(50);
//
//     Serial.print("KAF B:");
//     Serial.println(kaf_B[0]);
//     delay(50);
//
//     Serial.print("KAF L:");
//     Serial.println(kaf_L[0]);
//delay(50);

     Serial.print("KAF FB:");
     Serial.println(kaf_F[1]);
     delay(50);
//
//     Serial.print("KAF R:");
//     Serial.println(kaf_R[1]);
//     delay(50);
//
//     Serial.print("KAF B:");
//     Serial.println(kaf_B[1]);
//     delay(50);
//
//     Serial.print("KAF L:");
//     Serial.println(kaf_L[1]);
//delay(50);

}

// void SHOWSENSOR(void)
// {
//    sprintf (bigsensornum,"%03d", Compass);
//    Serial.print("big sensor number=");
//    Serial.println(bigsensornum);
//    delay(50);
//    sprintf (bigsensor,"%03d", Compass);
//    Serial.print("big sensor=");
//    Serial.println(bigsensor);
//    delay(50);
// }
// 
