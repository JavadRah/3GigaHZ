/////////////////////////////StarT//////////////////////////////
#include<Wire.h>
#define address 0x60 
//--------------------------VAR-------------------------//
//int Compass;
//float reduction = 1;
unsigned int n_cmp, big_sensor, big_sensor_num;
////EEPROM write
//unsigned char SETUP;
//signed int set_m, set_s;
//char Movement;
//int reader[4];
//char srfl[3];
//char srfb[3];
//char srfr[3], Mode;
//unsigned char O_Mode, Out, Out_old;
//boolean stop_out, other_location, location;
//char bluetooth_input[9], other_dn, dn, c;
//int other_big_sensor , other_sensor_value;
//float battery_voltage, V;
int Sensor;
unsigned int distance = 700 , noise = 358;
int kaf_F[2] , kaf_L[2] , kaf_B[2] , kaf_R[2] , Dip[4], DSensor[20];
int F_noise[2], R_noise[2], L_noise[2], B_noise[2];
float reduction =0.5;
int Sofa,Sofb,Sola,Solb,Sora,Sorb,Sobb,Soba,fa,fb,la,lb,ra,rb,bb,ba;
char cmp[3],bigsensor[3],bigsensornum[2];
////
//eeprom
//**************************PINS*************************//
 int RX=0,TX=1,SET=2,RX1=7,TX1=8,PWM_MRF=22,PWM_MLF=21,PWM_MRB=20,PWM_MLB=10,SHOOT=11;
  int SDA1=18,SCLl=19,GPIO_MRF=24,GPIO_MLF=25,GPIO_MRB=26,GPIO_MLB=27,BUZ=28;
 int SOFA=34,SOFB=33,SORA=37,SORB=38,SOLA=35,SOLB=36,SOBA=32,SOBB=31,FEEDBACK=21,SCENSE1=14,SCENSE2=15,BALL=39,D4=3,D3=4,D2=5,D1=6;
int AD3=30,AD2=29,AD0=9,AD1=12,SENSOR[17];
int mlf,mrb,mlb,mrf;
int srfL=121,srfB=122,srfR=123;
//******************************************************//
//......................FUNC.............................//

//15///////////////////////WIN///////////////////////
//void win(void)
//{
//digitalWrite(BUZ,HIGH);
//  delay(200);
//  digitalWrite(BUZ,LOW);
//  delay(150);
//
//digitalWrite(BUZ,HIGH);
//  delay(200);
//  digitalWrite(BUZ,LOW);
//  delay(150);
//
//digitalWrite(BUZ,HIGH);
//  delay(100);
// digitalWrite(BUZ,LOW);
//  delay(100);
//
//digitalWrite(BUZ,HIGH);
//  delay(100);
//  digitalWrite(BUZ,LOW);
//  delay(150);
//
//digitalWrite(BUZ,HIGH);
//  delay(200);
//digitalWrite(BUZ,LOW);
//  delay(200);
//}
//16//////////////////////CHECK EN////////////////////////////////
//void EN (void)
//{
//  biggest();
//  if (big_sensor_num != 0 && big_sensor_num < 8 && srfR > 75 )
//  {
//    Move(4);
//  }
//  else if (big_sensor_num > 8 && srfL > 75)
//  {
//    Move(12);
//  }
//  else
//  {
//    set_m = spin_speed(2, 10, 3);
//    set_s = spin_speed(1, 20, 5);
//    STOP();
//  }
//}
//
//
// const int led = 13;
int a[16];
/////////////////////////SetuP//////////////////////////////////
void setup()
{
  analogWriteResolution(10);
  //=====================PINS=============================//
  pinMode(PWM_MRF, OUTPUT);
  pinMode(PWM_MLF, OUTPUT);
  pinMode(PWM_MRB, OUTPUT);
  pinMode(PWM_MLB, OUTPUT);
  pinMode(AD0, OUTPUT);
  pinMode(AD1, OUTPUT);
  pinMode(AD2, OUTPUT);
  pinMode(AD3, OUTPUT);
  pinMode(GPIO_MRF, OUTPUT);
  pinMode(GPIO_MLF, OUTPUT);
  pinMode(GPIO_MRB, OUTPUT);
 pinMode(GPIO_MLB, OUTPUT);
  pinMode(BALL, INPUT);
  pinMode(SOFA,INPUT);
//  pinMode(SOBB, INPUT);
//  pinMode(SOBA, INPUT);
//  pinMode(SORA, INPUT);
//  pinMode(SORB, INPUT);
 pinMode(SOFB,INPUT);
//  pinMode(SOLA, INPUT);
//  pinMode(SOLB, INPUT);
  pinMode(BUZ, OUTPUT);
//  pinMode(SET, INPUT_PULLUP);//pullup??
//  pinMode(D1,INPUT);
//  pinMode(D2,INPUT);
//  pinMode(D3,INPUT);
//  pinMode(D4,INPUT);
//  //pinMode(,);
//  pinMode(led,OUTPUT);
  //=============================================//
  Serial.begin(38400);
// Serial.begin(9600);
//  set_m = spin_speed(1, 15, 3);
//  set_s = spin_speed(1, 15, 7);
digitalWrite(BUZ,HIGH);
  delay(200);
digitalWrite(BUZ,LOW);
  delay(50);
digitalWrite(BUZ,HIGH);
  delay(100);
digitalWrite(BUZ,LOW);
  delay(20);
  digitalWrite(BUZ,HIGH);
  delay(200);
digitalWrite(BUZ,LOW);
 delay(200);
analogWriteFrequency(6,29296);
}

void loop()
{
 /*sprintf (cmp,"%03d", Compass);
 Serial.println(cmp);
 delay(100);
 sprintf (bigsensor,"%03d", Compass);
 Serial.println(bigsensor);
 delay(100);
 sprintf (bigsensornum,"%03d", Compass);
 Serial.println(bigsensornum);
 delay(100);*/
//SHOWSENSOR();
//set_bits();  
//refreshs();
//convert_adc(0);
MOTOR(-1023,1023,-255,1023);
//analogWrite(PWM_MLB,255);
//digitalWrite(GPIO_MLB,HIGH);

//Serial.println(big_sensor_num);
/*
int b=0;
 int c=0;
for(int i=0;i<16;i++)
{  
 a[i] = convert_adc(i);
  Serial.println(a[i]);
  delay(100);
  if(c<=a[i])
  {
    c=a[i];
    b=i;
  }
//if(b==0){
//  Serial.println("nothing really");
//}
  }   

     Serial.println(b);
     delay(500);*/
  
 
//   if(SET==HIGH)
//    {
//        while(SET==HIGH)
//        {
//            Read_Compass();
//            refreshs();
//           pinMode(BUZ,HIGH);
//           delay(100);
//        }
//        pinMode(BUZ,LOW);
//        SETUP = n_cmp;
//        Kaf_setup();
//    }
//    if(D1==HIGH)
//    {
//      while(D1==HIGH)
//      {
//        SHOWKAF();
//      }
//    }
//   if(D2==HIGH)
//    {
//      while(D2==HIGH)
//      {
//        SHOWSENSOR();
//      }
//    }*/
}
