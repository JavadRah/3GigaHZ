////1////////////////////////////////////////////////
//unsigned int read_adc(int c)
//{
//  int o = analogRead(c);
////  float p = (1023 * o) / 5;
//  return o;
//}
unsigned int  convert_adc(int Sensor) {
  int a = 0;
  digitalWrite(AD0, (((Sensor) / 1) % 2));
  digitalWrite(AD1, (((Sensor) / 2) % 2));
  digitalWrite(AD2, (((Sensor) / 4) % 2));
  digitalWrite(AD3, (((Sensor) / 8)));
  a = 1023 - analogRead(39);
  return a;
}
void refreshs(void)
{
  int k;
  for (k = 0; k < 16; k++)
  {
    SENSOR[k] = convert_adc(k);

    if (SENSOR[k] > 1000) SENSOR[k] = 0;
  }
   //SENSOR[15]=SENSOR[15]-50; //code meshki
}


void Kaf_setup (void)
{
  //    refreshs ();
  Sofa = analogRead(34);
  Sofb = analogRead(33);
  Sola = analogRead(35);
  Solb = analogRead(36);
  Sora = analogRead(37);
  Sorb = analogRead(38);
  Soba = analogRead(32);
  Sobb = analogRead(31);

  kaf_F [0] =  Sofa ;
  kaf_F [1] =  Sofb ;

  kaf_R [0] =  Sora ;
  kaf_R [1] =  Sorb ;

  kaf_B [0] =  Soba ;
  kaf_B [1] =  Sobb ;

  kaf_L [0] =  Sola ;
  kaf_L [1] =  Solb ;
}
////3///////////////////////////////////////////////
void set_bits(void)
{
  ////////////////////Kaf
  kaf_F[0] =  analogRead(34);
  kaf_F[1] =  analogRead(33);

  kaf_R[0] = analogRead(37);
  kaf_R[1] = analogRead(38);

  kaf_B[0] = analogRead(32);
  kaf_B[1] = analogRead(31);

  kaf_L[0] =  analogRead(35);
  kaf_L[1] =  analogRead(36);

  //////////////////out of bound 1
  F_noise [0] = kaf_F[0] - 480;
  F_noise [1] = kaf_F[1] - 465;
  L_noise [0] = kaf_L[0] - 510;
  L_noise [1] = kaf_L[1] - 350;
  //////////////check nashode/////////////
  R_noise [0] = kaf_R[0] - 740;
  R_noise [1] = kaf_R[1] - 735; 
  B_noise [0] = kaf_B[0] - 435;
  B_noise [1] = kaf_B[1] - 460;
  ////////////////////////////////////
  if (R_noise[0] >= 0)  ra = 1;
  else   ra = 0; 
//  Serial.print("ra=");  
//  Serial.println(ra);
  if ( F_noise[0] >= 0)  fa = 1;
  else   fa = 0;
   Serial.print("fa=");  
    Serial.println(fa);
  if ( L_noise[0] >= 0)  la = 1;
  else   la = 0;
   Serial.print("la=");  
  Serial.println(la);
  if ( B_noise[0] >= 0)  ba = 1;
  else   ba = 0;
   Serial.print("ba=");  
 Serial.println(ba);
  //////////////////out of bound 2
  if ( R_noise[1] >= 0)  rb = 1;
  else   rb = 0;
//   Serial.print("rb=");  
// Serial.println(rb);
  if (F_noise[1] >= 0)  fb = 1;
  else   fb = 0;
   Serial.print("fb=");  
 Serial.println(fb);
  if ( L_noise[1] >= 0)  lb = 1;
  else  lb = 0;
   Serial.print("lb=");  
 Serial.println(lb);
  if ( B_noise[1] >= 0)  bb = 1;
  else   bb = 0;
   Serial.print("bb=");  
   Serial.println(bb);
}
////14//////////////////////////VOLTAGE BATTERY/////////////////////////////
//void get_battery_voltage()
//{
//  battery_voltage = (FEEDBACK * 12.7) / 524;
//}
////20////////////////////BIG SENSOR/////////////////////////////////
void biggestt(void)
{
  refreshs();
  int b = 17, c = 0;
  for (int i = 0; i < 16; i++)
  {
    if (c < SENSOR[i])
    {
      c = SENSOR[i];
      b = i;
    }
  }
  big_sensor = c;
  big_sensor_num = b;
  //      Serial.print(b);
  //      Serial.print(" | ");
  //      Serial.println(c);
  //      delay(500);
}


///////////////////////SHOW Kaf/////////////////////////////////////
void SHOWKAF(void)
{
  Kaf_setup();
//       Serial.print("KAF FA:");
//       Serial.println(kaf_F[0]);
//       delay(200);
//       Serial.print("KAF RA:");
//       Serial.println(kaf_R[0]);
//       delay(200);
//       Serial.print("KAF BA:");
//       Serial.println(kaf_B[0]);
//       delay(200);
//       Serial.print("KAF LA:");
//       Serial.println(kaf_L[0]);
//       delay(400);
//       Serial.print("KAF FB:");
//       Serial.println(kaf_F[1]);
//       delay(400);
//       Serial.print("KAF RB:");
//       Serial.println(kaf_R[1]);
//       delay(200);
//       Serial.print("KAF BB:");
//       Serial.println(kaf_B[1]);
//       delay(200);
//       Serial.print("KAF LB:");
//       Serial.println(kaf_L[1]);
//       delay(200);
}

void SHOWSENSOR(void)
{
  refreshs();
  biggestt();
  for (int i = 0; i < 16; i++)
  {
    Serial.print(" ");
    Serial.print(i);
    Serial.print(":");
    Serial.print(SENSOR[i]);
    delay(1);
  }
  Serial.println(" ");

    sprintf (bigsensornum, "%03d", big_sensor_num);
//    Serial.print("big sensor number=");
    Serial.print(bigsensornum);
    delay(50);
     Serial.print(" | ");
    sprintf (bigsensor, "%03d", big_sensor);
  //  Serial.print("big sensor=");
    Serial.println(bigsensor);
  //  delay(50);
}
void SHOWCMP()
{
   Read_Compass();
    CMPS();
    Serial.print(nSETUP);
    Serial.print(" | ");
    Serial.println(CMPS()); //Compass
    delay(10);
}
