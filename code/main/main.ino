
/////////////////////////////StarT//////////////////////////////
#include <Wire.h>
#include <EEPROM.h>
#define address 0x60
//-------------------------- VAR -------------------------//
unsigned int n_cmp, big_sensor, big_sensor_num = 17;
float reduction;
////EEPROM write
int nSETUP, high, low;
signed int set_m = 0, set_s = 0, Compass;
char Movement;
int SRFReader[6];
char srfl[3];
char srfb[3];
char srfr[3], Mode;
unsigned char O_Mode, Out, Out_old;
boolean stop_out, other_location, location;
char bluetooth_input[9], other_dn, dn, c;
int other_big_sensor , other_sensor_value;
float battery_voltage, V;
int Sensor, eeprom_cmp;
unsigned int distance = 450,noise= 50;
int kaf_F[2] , kaf_L[2] , kaf_B[2] , kaf_R[2] , Dip[4], DSensor[20];
int F_noise[2], R_noise[2], L_noise[2], B_noise[2], SENSOR[17];
int Sofa, Sofb, Sola, Solb, Sora, Sorb, Sobb, Soba;
bool fa, fb, la, lb, ra, rb, bb, ba;
char cmp[3], bigsensor[3], bigsensornum[2];
// const int led = 13;
int a[16];

//eeprom
//**************************PINS*************************//
int RX = 0, TX = 1, SET = 2, RX1 = 7, TX1 = 8, PWM_MRF = 22, PWM_MLF = 21, PWM_MRB = 20, PWM_MLB = 10, SHOOT = 11;
int SDA1 = 18, SCLl = 19, GPIO_MRF = 24, GPIO_MLF = 25, GPIO_MRB = 26, GPIO_MLB = 27, BUZ = 28;
int SOFA = 34, SOFB = 33, SORA = 37, SORB = 38, SOLA = 35, SOLB = 36, SOBA = 32, SOBB = 31, FEEDBACK = 21, SCENSE1 = 14, SCENSE2 = 15, BALL = 39, D4 = 3, D3 = 4, D2 = 5, D1 = 6;
int AD3 = 30, AD2 = 29, AD0 = 9, AD1 = 12;
int mlf, mrb, mlb, mrf;
int srfL , srfB , srfR ;
//******************************************************//
//......................FUNC.............................//

//15///////////////////////WIN///////////////////////
void win(void)
{
  digitalWrite(BUZ, HIGH);
  delay(200);
  digitalWrite(BUZ, LOW);
  delay(150);

  digitalWrite(BUZ, HIGH);
  delay(200);
  digitalWrite(BUZ, LOW);
  delay(150);

  digitalWrite(BUZ, HIGH);
  delay(100);
  digitalWrite(BUZ, LOW);
  delay(100);

  digitalWrite(BUZ, HIGH);
  delay(100);
  digitalWrite(BUZ, LOW);
  delay(150);

  digitalWrite(BUZ, HIGH);
  delay(200);
  digitalWrite(BUZ, LOW);
  delay(200);
}
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
/////////////////////////nSETUP//////////////////////////////////
void setup()
{
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
  pinMode(SOFA, INPUT);
    pinMode(SOBB, INPUT);
    pinMode(SOBA, INPUT);
  //  pinMode(SORA, INPUT);
  //  pinMode(SORB, INPUT);
  pinMode(SOFB, INPUT);
  //  pinMode(SOLA, INPUT);
  //  pinMode(SOLB, INPUT);
  pinMode(BUZ, OUTPUT);
  pinMode(SET, INPUT_PULLUP);
  //  pinMode(D1,INPUT);
  //  pinMode(D2,INPUT);
  //  pinMode(D3,INPUT);
  //  pinMode(D4,INPUT);
  //  pinMode(led,OUTPUT);
  //  //pinMode(,);
  //=============================================//
  Serial.begin(38400);
  Wire.begin();
  // Serial.begin(9600);
  digitalWrite(BUZ, HIGH);
  delay(100);
  digitalWrite(BUZ, LOW);
  delay(10);
  digitalWrite(BUZ, HIGH);
  delay(105);
  digitalWrite(BUZ, LOW);
  delay(300);
  digitalWrite(BUZ, HIGH);
  delay(200);
  digitalWrite(BUZ, LOW);
  delay(100);
  analogWriteResolution(10);
  analogWriteFrequency(20, 29296);
//Calibrate();
  nSETUP = (EEPROM.read(1) << 8) | EEPROM.read(2);
}

void loop()
{

  reduction = 0.5;
  // refreshs();
  //SHOWKAF();
//  biggestt();
////SHOWSENSOR();
//  ultrasonic ();
//  SHOWSRF();
//  delay(100);
//
//  if (big_sensor > noise)   
  Move_Width();
//  else
//  BackToGoal   (); 

  set_m = spin_speed(1, 40, 10);
  set_s = spin_speed(1, 40, 10);

  //////harekate vazie mah//////
  /*
    for(int i = 0;i< 16; i++)
    {
    Serial.print(i);
    Serial.print(" : ");
    Move(i);
    delay(100);
    }*/
  ////////////////////////////
  Read_Compass();
//  Serial.println(Compass);
  if (digitalRead(SET) == LOW)
  {
    while (digitalRead(SET) == LOW)
    {
      Read_Compass();
      digitalWrite(BUZ, HIGH);
      delay(100);
     //Serial.println(n_cmp);
      nSETUP = n_cmp;
    }
    EEPROM.write(1, highByte(nSETUP));
    EEPROM.write(2, lowByte(nSETUP));
    digitalWrite(BUZ, LOW);
    Kaf_setup();
    delay(100);
  }
  //      if(digitalRead(D1)==HIGH)
  //      {
  //        while(digitalRead(D1)==HIGH)
  //        {
  //          SHOWKAF();
  //        }
  //      }
  //     if(digitalRead(D2)==HIGH)
  //      {
  //        while(digitalRead(D2)==HIGH)
  //        {
  //          SHOWSENSOR();
  //        }

  //      }
}
