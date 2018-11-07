
/////////////////////////////StarT//////////////////////////////
#include<Wire.h>

//--------------------------VAR-------------------------//
int Compass;
float reduction=1;

//**************************PINS*************************//
const int RX=0,TX=1,SET=2,PWM_MRF=5,PWM_MLF=6,PWM_MRB=9,PWM_MLB=10,BALL=14;
const int SDAA=18,SCLL=19,SOBB=21,GPIO_MRF=24,GPIO_MLF=25,GPIO_MRB=26,GPIO_MLB=27,BUZ=28;//,AD3=30;
const int SOFA=33,SOFB=34,SORA=35,SORB=36,SOLA=37,SOLB=38,SOBA=39;
int AD3=30,AD2=29,AD0=7,AD1=8,SENSOR[17],address;
//******************************************************//
//......................FUNC.............................//
//PWMMOTOR
/*void MOTOR(){
 int mrf,mlf,mrb,mlb,o;
//mrf= map(mrf,0,255,0,100);
//mlf= map(mlf,0,255,0,100);
//mrb= map(mrb,0,255,0,100);
//mlb= map(mlb,0,255,0,100);
switch (o){
  case 0:
  mlf=-100,mrf=-100,mlb=100,mrb=100;
   case 22.5:
  mlf=-100,mrf=-100,mlb=100,mrb=100;
  case 45:
    mlf=-100,mrf=-100,mlb=100,mrb=100;
  case 67.5:
    mlf=-100,mrf=-100,mlb=100,mrb=100;
  case 
  }
}*/
unsigned int read_adc(int c){
  int o=analogRead(c);
  float p= (1023*o)/5;
  return p;}
  
unsigned int  convert_adc(int Sensor)
{
        AD3=(((Sensor)/1)%2);
        AD2=(((Sensor)/2)%2);
        AD1=(((Sensor)/4)%2);
        AD0=(((Sensor)/8));
        return read_adc(14);
 }
 
void multi_read(void)
 {
    int k;
    for (k=0;k<16;k++)
    {
        SENSOR[k]=1023-convert_adc(k);
        if(SENSOR[k] > 1000) SENSOR[k] = 0;
    }
 }
//MOTOR 
/*
void MOTOR(int pwmlf,int pwmlb,int pwmrf,int pwmrb)
 {

        pwmlf = pwmlf*-1*reduction;
        pwmlb = pwmlb*-1*reduction;
        pwmrf = pwmrf*-1*reduction;
        pwmrb = pwmrb*-1*reduction;


     if(pwmlf>255)   pwmlf=255;
     if(pwmlb>255)   pwmlb=255;
     if(pwmrb>255)   pwmrb=255;
     if(pwmrf>255)   pwmrf=255;
     if(pwmlf<-255)   pwmlf=-255;
     if(pwmlb<-255)   pwmlb=-255;
     if(pwmrb<-255)   pwmrb=-255;
     if(pwmrf<-255)   pwmrf=-255;

  //*********************Left's MOTOR MAIN
      if(pwmlf>0)
      {
        mlf=0;
        PWM_MLF=pwmlf;
      }
       else if(pwmlf<0)
      {
        mlf=1;
        PWM_0MLF=255+pwmlf;
      }
      else if(pwmlf==0)
      {
        mlf=1;
        PWM_MLF=255;
      }

    //*********************Left's MOTOR MAIN
      if(pwmlb>0)
      {
        mlb=0;
        PWM_MLB=pwmlb;
      }
      else if(pwmlb<0)
      {
        mlb=1;
        PWM_MLB=255+pwmlb;
      }
      else if(pwmlb==0)
      {
        mlb=1;
        PWM_MLB=255;
      }
    //*********************Right's MOTOR MAIN
      if(pwmrf>0)
      {
        mrf=0;
        PWM_MRF=pwmrf;
      }
      else if(pwmrf<0)
      {
        mrf=1;
        PWM_MRF=255+pwmrf;
      }
      else if(pwmrf==0)
      {
        mrf=1;
        PWM_MRF=255;
      }
    //*********************Right's MOTOR MAIN
      if(pwmrb>0)
      {
        mrb=0;
        PWM_MRB=pwmrb;
      }
      else if(pwmrb<0)
      {
        mrb=1;
        PWM_MRB=255+pwmrb;

      }
      else if(pwmrb==0)
      {
        mrb=1;
        PWMRB=255;
      }
 }*/
 //COMPASS
 void Read_Compass()
{
  Wire.beginTransmission(address);  ////starts communication with cmp03
  Wire.write(1);                    /////sends the register we wish to read
  Wire.endTransmission();
  Wire.requestFrom(address, 1);     /////requests high byte
  Compass = Wire.read();
  Wire.endTransmission();
}
//MOVEMENT
/*
void Move(int a)
 {

    switch(a)
    {
        case 0:
        MOTOR(2515+set_m,255+set_m,-255+set_m,-255+set_m);
        break;

        case 1:
        MOTOR(255+set_m,127+set_m,-127+set_m,-256+set_m);
        break;

        case 2:
        MOTOR(255+set_m,0+set_m,0+set_m,-255+set_m);
        break;

        case 3:
        MOTOR(255+set_m,-127+set_m,127+set_m,-255+set_m);
        break;

        case 4:
        MOTOR(255+set_m,-255+set_m,255+set_m,-255+set_m);
        break;  
         
        case 45:
        MOTOR(191+set_m,-255+set_m,255+set_m,-191+set_m);
        break;

        case 5:
        MOTOR(127+set_m,-255+set_m,255+set_m,-127+set_m);
        break;

        case 6:
        MOTOR(0+set_m,-255+set_m,255+set_m,0+set_m);
        break;

        case 7:
        MOTOR(-127+set_m,-255+set_m,255+set_m,127+set_m);
        break;

        case 8:
        MOTOR(-255+set_m,-255+set_m,255+set_m,255+set_m);
        break;

        case 9:
        MOTOR(-255+set_m,-127+set_m,127+set_m,255+set_m);
        break;

        case 10:
        MOTOR(-255+set_m,0+set_m,0+set_m,255+set_m);
        break;

        case 11:
        MOTOR(-255+set_m,127+set_m,-127+set_m,255+set_m);
        break;

        case 12:
        MOTOR(-255+set_m,255+set_m,-255+set_m,255+set_m);
        break;

        case 13:
        MOTOR(-127+set_m,255+set_m,-255+set_m,127+set_m);
        break;

        case 14:
        MOTOR(0+set_m,255+set_m,-255+set_m,0+set_m);
        break;

        case 15:
        MOTOR(127+set_m,255+set_m,-255+set_m,-127+set_m);
        break;

        case 17:  //(0,15)
        MOTOR(191+set_m,255+set_m,-255+set_m,-191+set_m);
        break;

        case 18: //(15,17)
        MOTOR(159+set_m,255+set_m,-255+set_m,-159+set_m);
        break;

        case 19: //(8,7)
        MOTOR(-191+set_m,-255+set_m,255+set_m,191+set_m);
        break;
        case 20: //(8,9)
        MOTOR(-255+set_m,-191+set_m,191+set_m,255+set_m);
        break;


  }
    Movement=a;
 }
 */
//

/////////////////////////SetuP//////////////////////////////////
void setup() {
//=====================PINS=============================//
pinMode(RX,INPUT);
pinMode(TX,INPUT);
pinMode(PWM_MRF,OUTPUT);
pinMode(PWM_MLF,OUTPUT);
pinMode(PWM_MRB,OUTPUT);
pinMode(PWM_MLB,OUTPUT);
pinMode(AD0,OUTPUT);
pinMode(AD1,OUTPUT);
pinMode(AD2,OUTPUT);
pinMode(AD3,OUTPUT);
pinMode(GPIO_MRF,OUTPUT);
pinMode(GPIO_MLF,OUTPUT);
pinMode(GPIO_MRB,OUTPUT);
pinMode(GPIO_MLB,OUTPUT);
pinMode(BALL,INPUT);
pinMode(SOFA,OUTPUT);
pinMode(SOBB,OUTPUT);
pinMode(SOBA,OUTPUT);
pinMode(SORA,OUTPUT);
pinMode(SORB,OUTPUT);
pinMode(SOFB,OUTPUT);
pinMode(SOLA,OUTPUT);
pinMode(SOLB,OUTPUT);
pinMode(BUZ,OUTPUT);
pinMode(SET,INPUT_PULLUP);
//pinMode(,);
//=============================================//
Serial.begin(38400);
}

void loop() {
  // put your main code here, to run repeatedly:

}
