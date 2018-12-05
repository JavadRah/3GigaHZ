
/////////////////////////////StarT//////////////////////////////
#include <Wire.h>
#include <EEPROM.h>
IntervalTimer myTimer;
#define address 0x60
//-------------------------- VAR -------------------------//
unsigned int n_cmp, big_sensor, big_sensor_num = 17, r_stop, nointerrupt;
float reduction;
volatile unsigned int interrupt = 0;
int nSETUP, high, low;
signed int set_m = 0, set_s = 0, Compass;
char Movement;
//unsigned char O_Mode, Out, Out_old;
//boolean stop_out, other_location, location;
//char bluetooth_input[9], other_dn, dn, c;
//int other_big_sensor , other_sensor_value;
//float battery_voltage, V;
int Sensor;
unsigned int distance = 450, noise = 70, distanceM = 450;
int kaf_F[2] , kaf_L[2] , kaf_B[2] , kaf_R[2] , Dip[4], DSensor[20];
int F_noise[2], R_noise[2], L_noise[2], B_noise[2], SENSOR[17];
int Sofa, Sofb, Sola, Solb, Sora, Sorb, Sobb, Soba;
bool fa, fb, la, lb, ra, rb, bb, ba;
char cmp[3], bigsensor[3], bigsensornum[2];
char srfl[3];
char srfb[3];
char srfr[3], Mode;
int SRFReader[6];
int a[16];
int s;
void SRF(void);
//eeprom

//**************************PINS*************************//
int RX = 0, TX = 1, SET = 2, RX1 = 7, TX1 = 8, PWM_MRF = 22, PWM_MLF = 21, PWM_MRB = 20, PWM_MLB = 10, SHOOT = 11;
int SDA1 = 18, SCLl = 19, GPIO_MRF = 24, GPIO_MLF = 25, GPIO_MRB = 26, GPIO_MLB = 27, BUZ = 28;
int SOFA = 34, SOFB = 33, SORA = 37, SORB = 38, SOLA = 35, SOLB = 36, SOBA = 32, SOBB = 31, FEEDBACK = 21, SCENSE1 = 14, SCENSE2 = 15, BALL = 39, D4 = 6, D3 = 4, D2 = 5, D1 = 3;
int AD3 = 30, AD2 = 29, AD0 = 9, AD1 = 12;
int mlf, mrb, mlb, mrf;
int srfL , srfB , srfR ;
const int led = 13;
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
  pinMode(SORA, INPUT);
  pinMode(SORB, INPUT);
  pinMode(SOFB, INPUT);
  pinMode(SOLA, INPUT);
  pinMode(SOLB, INPUT);
  pinMode(BUZ, OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(SET, INPUT_PULLUP);
//  pinMode(D1, INPUT);
//  pinMode(D2, INPUT);
//  pinMode(D3, INPUT);
//  pinMode(D4, INPUT);
  pinMode(led, OUTPUT);
  //  //pinMode(,);
  //=============================================//
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
  //////////start///////
  Serial.begin(38400);
  Wire.begin();
  analogWriteResolution(10);
  analogWriteFrequency(20, 29296);
  //Calibrate();
  myTimer.begin(SRF, 25000);
  /////////////////EEPROM
  nSETUP = (EEPROM.read(1) << 8) | EEPROM.read(2);
  R_noise[0] = (EEPROM.read(3) << 8 | EEPROM.read(4));
  R_noise[1] = (EEPROM.read(5) << 8 | EEPROM.read(6));
  F_noise[0] = (EEPROM.read(7) << 8 | EEPROM.read(8));
  F_noise[1] = (EEPROM.read(9) << 8 | EEPROM.read(10));
  L_noise[0] = (EEPROM.read(11) << 8 | EEPROM.read(12));
  L_noise[1] = (EEPROM.read(13) << 8 | EEPROM.read(14));
  B_noise[0] = (EEPROM.read(15) << 8 | EEPROM.read(16));
  B_noise[1] = (EEPROM.read(17) << 8 | EEPROM.read(18));
}

void loop()
{
  //Kaf_setup();
  //refreshs();
  //SHOWKAF
  biggestt();
  set_bits();
 
  ///////////////////////////////////
  if(big_sensor>noise)
  {
    if (big_sensor>distanceM & srfB<60)
    {
      OUT();
    }
    else
    { 
      Move_Width();
    }
  }
  else {
    
    BackToGoal();
  }
//  //////harekate vazie mah//////
  /*
    for(int i = 0;i< 16; i++)
    {
    Serial.print(i);
    Serial.print(" : ");
    Move(i);
    delay(100);
    }*/


  ////////////////////////////SET
  if (digitalRead(SET) == LOW)
  {
    while (digitalRead(SET) == LOW)
    {
      nointerrupt = 100;
      Read_Compass();
      digitalWrite(BUZ, HIGH);
      //     Serial.println(n_cmp);
      nSETUP = n_cmp;
      set_kaf();
    }
    nointerrupt = 0;
    EEPROM.write(1, highByte(nSETUP));
    EEPROM.write(2, lowByte(nSETUP));
    EEPROM.write(3, highByte(R_noise[0]));
    EEPROM.write(4, lowByte(R_noise[0]));
    EEPROM.write(5, highByte(R_noise[1]));
    EEPROM.write(6, lowByte(R_noise[1]));
    EEPROM.write(7, highByte(F_noise[0]));
    EEPROM.write(8, lowByte(F_noise[0]));
    EEPROM.write(9, highByte(F_noise[1]));
    EEPROM.write(10, lowByte(F_noise[1]));
    EEPROM.write(11, highByte(L_noise[0]));
    EEPROM.write(12, lowByte(L_noise[0]));
    EEPROM.write(13, highByte(L_noise[1]));
    EEPROM.write(14, lowByte(L_noise[1]));
    EEPROM.write(15, highByte(B_noise[0]));
    EEPROM.write(16, lowByte(B_noise[0]));
    EEPROM.write(17, highByte(B_noise[1]));
    EEPROM.write(18, lowByte(B_noise[1]));
    digitalWrite(BUZ, LOW);
    Kaf_setup();
  }
  ////////////////////////DIP
//  if (digitalRead(D1) == HIGH)
//  {
//    while (digitalRead(D1) == HIGH)
//    {
//      digitalWrite(BUZ, HIGH);
//      SHOWSENSOR();
//    }
//    digitalWrite(BUZ,LOW);
//  }

  //     if(digitalRead(D2)==HIGH)
  //      {
  //        while(digitalRead(D2)==HIGH)
  //        {
  //          SHOWSENSOR();
  //        }

  //      }
}
