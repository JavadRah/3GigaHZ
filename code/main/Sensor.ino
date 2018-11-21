////1////////////////////////////////////////////////
//unsigned int read_adc(int c) 
//{
//  int o = analogRead(c);
////  float p = (1023 * o) / 5;
//  return o;
//}
unsigned int  convert_adc(int Sensor) {
  int a=0;
  AD3 = (((Sensor) / 1) % 2);
  AD2 = (((Sensor) / 2) % 2);
  AD1 = (((Sensor) / 4) % 2);
  AD0 = (((Sensor) / 8));
  a= 1023 - analogRead(39);
    return a;
}
void refreshs(void)
{
  int k;
  for (k = 0; k < 16; k++)
  {
    SENSOR[k] = 1023- analogRead(39);

    if (SENSOR[k] > 1000) SENSOR[k] = 0;
  }
//  for(int i=0;i<16;i++){
//    Serial.print(" Sensor ");
//    Serial.println(i);
//    Serial.println(SENSOR[i]);
//    delay(100);
    
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
 F_noise[0]= kaf_F[0] -25;
 F_noise [1]= kaf_F[1] - 45;
//    L_noise [0]= kaf_L[0] - 20;
//    L_noise [1]= kaf_L[1] - 25;
//    R_noise [0]= kaf_R[0] - 20;
//    R_noise [1]= kaf_R[1] - 25;
//    B_noise [0]= kaf_B[0] - 25;
//    B_noise [1]= kaf_B[1] - 25;   
  if (R_noise[0]>=0)  ra = 1;
  else   ra = 0;

  if ( F_noise[0]>=0)  fa = 1;
  else   fa = 0;
  if ( L_noise[0]>=0)  la = 1;
  else   la = 0;

  if ( B_noise[0]>=0)  ba = 1;
  else   ba = 0;

  //////////////////out of bound 2
  if ( R_noise[1]>=0)  rb = 1;
  else   rb = 0;

  if (F_noise[1]>=0)  fb = 1;
  else   fb = 0;
  Serial.println(fb);

  if ( L_noise[1]>=0)  lb = 1;
  else  lb = 0;

  if ( B_noise[1]>=0)  bb = 1;
  else   bb = 0;
}
////14//////////////////////////VOLTAGE BATTERY/////////////////////////////
//void get_battery_voltage()
//{
//  battery_voltage = (FEEDBACK * 12.7) / 524;
//}
////20////////////////////BIG SENSOR/////////////////////////////////
     void biggestt(void)
    {
      int b=17,c=0;
      for(int i=0;i<16;i++) 
     {
      a[i]=convert_adc(i);
      if(c<a[i])
      {
      c=a[i];
      b=i;}
     }
      big_sensor = c;
      big_sensor_num = b;
      delay(500);
    }
/*
void biggest(void)
{
  int i, c;
  int MAX = 0;
  for (i = 0; i < 16; i++)
  {
    if (MAX < SENSOR[i])
    {
      c = i;
      MAX = SENSOR[i];
    }
  }
  big_sensor = MAX;
  big_sensor_num = c;
}
*/
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

 void SHOWSENSOR(void)
 {
    sprintf (bigsensornum,"%03d", big_sensor_num);
    Serial.print("big sensor number=");
    Serial.println(bigsensornum);
    delay(500);
    sprintf (bigsensor,"%03d",big_sensor);
    Serial.print("big sensor=");
    Serial.println(bigsensor);
    delay(500);
 }
 
