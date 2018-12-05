/////////////////////////////////
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
  SENSOR[2]=((SENSOR[1]+SENSOR[2])/2);
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
  if (R_noise[0] < kaf_R[0])  ra = 1;
  else   ra = 0;

  if (F_noise[0] < kaf_F[0])  fa = 1;
  else   fa = 0;

  if ( L_noise[0] < kaf_L[0])  la = 1;
  else   la = 0;

  if ( B_noise[0] < kaf_B[0])  ba = 1;
  else   ba = 0;

  ////////////////out of bound 2
  if ( R_noise[1] < kaf_R[1])  rb = 1;
  else   rb = 0;

  if (F_noise[1] < kaf_F[1])  fb = 1;
  else   fb = 0;

  if ( L_noise[1] < kaf_L[1])  lb = 1;
  else  lb = 0;

  if ( B_noise[1] < kaf_B[1])  bb = 1;
  else   bb = 0;

}
void set_kaf() {
  F_noise [0] = kaf_F[0] + 150;
  F_noise [1] = kaf_F[1] + 90 ;
  L_noise [0] = kaf_L[0] + 100;
  L_noise [1] = kaf_L[1] + 60 ;
  R_noise [0] = kaf_R[0] + 70 ;
  R_noise [1] = kaf_R[1] + 60 ;
  B_noise [0] = kaf_B[0] + 150;
  B_noise [1] = kaf_B[1] + 190;
}

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
//         Serial.print("KAF FA:");
//         Serial.println(kaf_F[0]);
//         delay(200);
//         Serial.print("KAF RA:");
//         Serial.println(kaf_R[0]);
//         delay(200);
//         Serial.print("KAF BA:");
//         Serial.println(kaf_B[0]);
//         delay(200);
//         Serial.print("KAF LA:");
//         Serial.println(kaf_L[0]);
//         delay(200);
//  Serial.print("KAF FB:");
//  Serial.println(kaf_F[1]);
//  delay(200);
         Serial.print("KAF RB:");
         Serial.println(kaf_R[1]);
         delay(200);
//         Serial.print("KAF BB:");
//         Serial.println(kaf_B[1]);
//         delay(200);
//         Serial.print("KAF LB:");
//         Serial.println(kaf_L[1]);
//         delay(200);
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
void SHOW_KAF()
{
  set_bits();
  Serial.print("F1: "); Serial.print(fa); Serial.print(" F2:"); Serial.print(fb); Serial.print(" R1:"); Serial.print(ra); Serial.print( " R2:");
  Serial.print(rb); Serial.print(" B1:"); Serial.print(ba); Serial.print(" B2:"); Serial.print(bb); Serial.print(" L1:"); Serial.print(la);
  Serial.print(" L2:"); Serial.println(lb);
}
void BLINK(void){
 digitalWrite(led,HIGH);
 delay(100);
 digitalWrite(led,LOW);
 delay(100);
}
