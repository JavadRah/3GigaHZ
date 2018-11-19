//1////////////////////////////////////////////////
unsigned int read_adc(int c) {
  int o = analogRead(c);
  float p = (1023 * o) / 5;
  return p;
}
unsigned int  convert_adc(int Sensor) {

  AD3 = (((Sensor) / 1) % 2);
  AD2 = (((Sensor) / 2) % 2);
  AD1 = (((Sensor) / 4) % 2);
  AD0 = (((Sensor) / 8));
  return read_adc(14);


}
//3///////////////////////////////////////////////
void set_bits(void)
{
  ////////////////////Kaf
  kaf_F[0] = 1023 - convert_adc(16);
  kaf_F[1] = 1023 - convert_adc(17);

  kaf_R[0] = 1023 - convert_adc(18);
  kaf_R[1] = 1023 - convert_adc(19);

  kaf_B[0] = 1023 - convert_adc(22);
  kaf_B[1] = 1023 - convert_adc(23);

  kaf_L[0] = 1023 - convert_adc(20);
  kaf_L[1] = 1023 - convert_adc(21);

  //////////////////out of bound 1

  if (kaf_R[0] <= R_noise[0])  SORA = 1;
  else   SORA = 0;

  if (kaf_F[0] <= F_noise[0])  SOFA = 1;
  else   SOFA = 0;

  if (kaf_L[0] <= L_noise[0])  SOLA = 1;
  else   SOLA = 0;

  if (kaf_B[0] <= B_noise[0])  SOBA = 1;
  else   SOBA = 0;

  //////////////////out of bound 2
  if (kaf_R[1] <= R_noise[1])  SORB = 1;
  else   SORB = 0;

  if (kaf_F[1] <= F_noise[1])  SOFB = 1;
  else   SOFB = 0;

  if (kaf_L[1] <= L_noise[1])  SOLB = 1;
  else   SOLB = 0;

  if (kaf_B[1] <= B_noise[1])  SOBB = 1;
  else   SOBB = 0;
}

void refreshs(void)
{
  int k;
  for (k = 0; k < 16; k++)
  {
    SENSOR[k] = 1023 - convert_adc(k);
    if (SENSOR[k] > 1000) SENSOR[k] = 0;
  }


}
//14//////////////////////////VOLTAGE BATTERY/////////////////////////////
void get_battery_voltage()
{
  battery_voltage = (FEEDBACK * 12.7) / 524;
}
//20////////////////////BIG SENSOR/////////////////////////////////
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
///////////////////////SHOW Kaf/////////////////////////////////////
void SHOWKAF(void){
     Serial.println(" SHOW KAF:");
     Serial.print("KAF F:");
     Serial.println(kaf_F[0]);
     Serial.print("KAF R:");
     Serial.println(kaf_R[0]);
     Serial.print("KAF B:");
     Serial.println(kaf_B[0]);
     Serial.print("KAF L:");
     Serial.println(kaf_L[0]);

     Serial.print("KAF F:");
     Serial.println(kaf_F[1]);
     Serial.print("KAF R:");
     Serial.println(kaf_R[1]);
     Serial.print("KAF B:");
     Serial.println(kaf_B[1]);
     Serial.print("KAF L:");
     Serial.println(kaf_L[1]);

}
void Kaf_setup (void)
 {
    refreshs ();
    kaf_F [0] = 1023 - SOFA ;
    kaf_F [1] = 1023 - SOFB ;

    kaf_R [0] = 1023 - SORA ;
    kaf_R [1] = 1023 - SOBA ;

    kaf_B [0] = 1023 - SOBA ;
    kaf_B [1] = 1023 - SOBB ;

    kaf_L [0] = 1023 - SOLA ;
    kaf_L [1] = 1023 - SOLB ;

    L_noise [0]= kaf_L[0] - 20;
    L_noise [1]= kaf_L[1] - 25;

    R_noise [0]= kaf_R[0] - 20;
    R_noise [1]= kaf_R[1] - 25;


    F_noise [0]= kaf_F[0] - 20;
    F_noise [1]= kaf_F[1] - 20;

    B_noise [0]= kaf_B[0] - 25;
    B_noise [1]= kaf_B[1] - 25;
 }
 void SHOWSENSOR(void)
 {
    sprintf (bigsensornum,"%03d", Compass);
    Serial.print("big sensor number=");
    Serial.println(bigsensornum);
    delay(50);
    sprintf (bigsensor,"%03d", Compass);
    Serial.print("big sensor=");
    Serial.println(bigsensor);
    delay(50);
 }
 

