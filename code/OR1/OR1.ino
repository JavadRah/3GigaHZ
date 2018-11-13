/////////////////////////////StarT//////////////////////////////
#include<Wire.h>
#define address 0x60 
//--------------------------VAR-------------------------//
int Compass;
float reduction=1;
unsigned int n_cmp,big_sensor,big_sensor_num;
//EEPROM write
unsigned char SETUP;
signed int set_m,set_s;
char Movement;
int reader[4];
char srfl[3];
char srfb[3];
char srfr[3],Mode;
unsigned char O_Mode,Out,Out_old;
boolean stop_out, other_location,location;
char bluetooth_input[9],other_dn,dn,c;
int other_big_sensor , other_sensor_value;
float battery_voltage,V;

unsigned int distance =700 ,noise = 300;
int kaf_F[2] , kaf_L[2] , kaf_B[2] , kaf_R[2] , Dip[4],DSensor[20];
 int F_noise[2], R_noise[2], L_noise[2], B_noise[2];
//eeprom
//**************************PINS*************************//
 int RX=0,TX=1,SET=2,D4=3,D3=4,D2=5,D1=6,RX1=7,TX1=8,PWM_MRF=22,PWM_MLF=21,PWM_MRB=20,PWM_MLB=10,BALL=39,SHOOT=11;
 int SDA1=18,SCLl=19,GPIO_MRF=24,GPIO_MLF=25,GPIO_MRB=26,GPIO_MLB=27,BUZ=28;
 int SOFA=34,SOFB=33,SORA=37,SORB=38,SOLA=35,SOLB=36,SOBA=32,SOBB=31,FEEDBACK=21,SCENSE1=14,SCENSE2=15;
int AD3=30,AD2=29,AD0=9,AD1=12,SENSOR[17];
int mlf,mrb,mlb,mrf;
int srfL=121,srfB=122,srfR=123;
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
  //set_bits
unsigned int  convert_adc(int Sensor){

        AD3=(((Sensor)/1)%2);
        AD2=(((Sensor)/2)%2);
        AD1=(((Sensor)/4)%2);
        AD0=(((Sensor)/8));
        return read_adc(14);
        
  
 }

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

    if(kaf_R[0]<=R_noise[0])  SORA = 1;
    else   SORA = 0;

    if(kaf_F[0]<=F_noise[0])  SOFA = 1;
    else   SOFA = 0;

    if(kaf_L[0]<=L_noise[0])  SOLA = 1;
    else   SOLA = 0;

    if(kaf_B[0]<=B_noise[0])  SOBA = 1;
    else   SOBA = 0;

    //////////////////out of bound 2
    if(kaf_R[1]<=R_noise[1])  SORB = 1;
    else   SORB = 0;

    if(kaf_F[1]<=F_noise[1])  SOFB = 1;
    else   SOFB = 0;

    if(kaf_L[1]<=L_noise[1])  SOLB = 1;
    else   SOLB = 0;

    if(kaf_B[1]<=B_noise[1])  SOBB = 1;
    else   SOBB = 0;
 }

 
 
void refreshs(void)
 {
    int k;
    for (k=0;k<16;k++)
    {
        SENSOR[k]=1023-convert_adc(k);
        if(SENSOR[k] > 1000) SENSOR[k] = 0;
    }
  

 }

///////////////MOTOR/////////////////////////////// 

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
        PWM_MLF=255+pwmlf;
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
        PWM_MRB=255;
      }
 }
 ////////COMPASS////
 void Read_Compass()
{
  Wire.beginTransmission(address);  ////starts communication with cmp03
  Wire.write(1);                    /////sends the register we wish to read
  Wire.endTransmission();
  Wire.requestFrom(address, 1);     /////requests high byte
  Compass = Wire.read();
  Wire.endTransmission();
}
///////////////CMP////////////////////////////////////
signed int CMP(void)
 {
  int b,a;
    Read_Compass();
  a=n_cmp-SETUP;
  if(a>0)
  {b=a;}
  else
  {b=a+256;}
  if(b>128)
  {b=b-256;}
  else
  {b=b;}
    Compass = -b;
  return -b;
 }
///////////////////SPIN SPEED////////////////////////////////
signed int spin_speed(int divided_value,int added_value,int zero_degree)
  {
    int compass_input=0,compass_output=0;
    CMP();
    compass_input=Compass;
    if ( compass_input >= zero_degree )
    compass_output=(compass_input/divided_value)+(added_value*1.5);
    else if (compass_input <= (-zero_degree) )
    compass_output=(compass_input)/divided_value-added_value;
    else
    compass_output=0;
    return compass_output;
 }


//////MOVEMENT//////////////////////////////

void Move(int a)
 {

    switch(a)
    {
        case 0:
        MOTOR(255+set_m,255+set_m,-255+set_m,-255+set_m);
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


 ////////////////////////////////////////////////////////////////
 //*************************FOLLOW****************************//
 //////////////////////////////////////////////////////////////
 void follow(void)
 {

        if (big_sensor > distance)
        {
            set_bits();
             if(SORB == 1)
            {
                stop_out=1;
                Move(9);
            }
            else if(SOLB == 1)
            {
                stop_out=1;
                Move(7);
            }
             else if(SOBA==1 && big_sensor_num > 1&& big_sensor_num < 8)
            {
                stop_out=0;
                Move(4);
            }
            else if (SOBA==1 && big_sensor_num <13 && big_sensor_num>9)
            {
                stop_out=1;
                Move(12);
            }
            else if (SOBB==1  && big_sensor_num >3 && big_sensor_num<8)
            {
                stop_out=1;
                Move(2);
            }
             else if (SOBB==1  && big_sensor_num <13 && big_sensor_num>9)
            {
                stop_out=1;
                Move(13);
            }
            else
            {
        switch(big_sensor_num)
            {
                case 0:
                Move(0);
                break;

                case 1:
                Move(2);
                break;

                case 2:
                Move(4);
                break;

                case 3:
                Move(5);
                break;

                case 4:
                Move(6);
                break;

                case 5:
                Move(8);
                break;

                case 6:
                Move(8);
                break;

                case 7:
                Move(10);
                break;

                case 8:
                Move(5);
                break;

                case 9:
                Move(6);
                break;

                case 10:
                Move(8);
                break;

                case 11:
                Move(8);
                break;

                case 12:
                Move(10);
                break;

                case 13:
                Move(11);
                break;

                case 14:
                Move(11);
                break;

                case 15:
                Move(14);
                break;
            }
        }

        }
        else
        {
            switch(big_sensor_num)
            {
                case 0:
                Move(0);
                break;

                case 1:
                Move(1);
                break;

                case 2:
                Move(2);
                break;

                case 3:
                Move(3);
                break;

                case 4:
                Move(4);
                break;

                case 5:
                Move(5);
                break;

                case 6:
                Move(6);
                break;

                case 7:
                Move(7);
                break;

                case 8:
                Move(8);
                break;

                case 9:
                Move(9);
                break;

                case 10:
                Move(10);
                break;

                case 11:
                Move(11);
                break;

                case 12:
                Move(12);
                break;

                case 13:
                Move(13);
                break;

                case 14:
                Move(14);
                break;

                case 15:
                Move(15);
                break;
            }
        }
//    }
 }
 ////////////////////////////////////////////////////////////////
 //.......................OUT.................................//
 ///////////////////////////////////////////////////////////////
 
 void OUT_CHECK(void)
 {
    if (SORA || SORB)
    {
        while(big_sensor_num < 8)
        {
            biggest();
            biggest();
            set_bits();
            set_m=spin_speed(1,15,3);
            set_s=spin_speed(1,15,7);
            if(SORA)
            {
                Move(12);
            }
            else if (SOFA || SOFB)
            {
                if(SOFA) Move(9);
                else if (SOFB)
                {
                    while(!SOFA)
                    {
                        Move(9);
                        set_bits();
                        set_m=spin_speed(1,15,3);
                        set_s=spin_speed(1,15,7);
                        if(srfB < 50)
                        {
                            Move(8);
                            delay(300);
                            break;
                        }
                    }
                }
            }
            else if (SOBA || SOBB)
            {
                if(SOBA) Move(15);
                else if(SOBB)
                {
                    while(!SOBA && srfB < 50)
                    {
                        Move(15);
                        set_bits();
                        set_m=spin_speed(1,15,3);
                        set_s=spin_speed(1,15,7);
                    }
                }
            }
            else if (SORB)
            {
                while(!SORA && srfR < 50)
                {
                    set_m=spin_speed(1,15,3);
                    set_s=spin_speed(1,15,7);
                    Move(12);
                    set_bits();
                }
            }
            else STOP();
        }
        ////////////////////////////////////////// Khareje While /////////////////////////////////////////////////
        if(SORA)
        {
            Move(12);
        }
        else if (SOFA || SOFB)
        {
            if(SOFA) Move(9);
            else if (SOFB)
            {
                while(!SOFA)
                {
                    Move(9);
                    set_bits();
                    set_m=spin_speed(1,15,3);
                    set_s=spin_speed(1,15,7);
                    if(srfB < 50)
                    {
                        Move(8);
                        delay(300);
                        break;
                    }
                }
            }
        }
        else if (SOBA || SOBB)
        {
            if(SOBA) Move(15);
            else if(SOBB)
            {
                while(!SOBA && srfB < 50)
                {
                    Move(15);
                    set_bits();
                    set_m=spin_speed(1,15,3);
                    set_s=spin_speed(1,15,7);
                }
            }
        }
        else if (SORB)
        {
            while(!SORA && srfR < 50)
            {
                set_m=spin_speed(1,15,3);
                set_s=spin_speed(1,15,7);
                Move(12);
                set_bits();
            }
        }
        else STOP();

    }
    else if(SOLA || SOLB)
    {
        while(big_sensor_num > 8)
        {
            biggest();
            biggest();
            set_bits();
            set_m=spin_speed(1,15,3);
            set_s=spin_speed(1,15,7);
            if(SOLA)
            {
                Move(4);
            }
            else if (SOFA || SOFB)
            {
                if(SOFA) Move(7);
                else if (SOFB)
                {
                    while(!SOFA)
                    {
                        set_m=spin_speed(1,15,3);
                        set_s=spin_speed(1,15,7);
                        Move(7);
                        set_bits();
                        if(srfB < 50)
                        {
                            Move(8);
                            delay(300);
                            break;
                        }
                    }
                }
            }
            else if (SOBA || SOBB)
            {
                if(SOBA) Move(1);
                else if(SOBB)
                {
                    while(!SOBA && srfB < 50)
                    {
                        set_m=spin_speed(1,15,3);
                        set_s=spin_speed(1,15,7);
                        Move(1);
                        set_bits();
                    }
                }
            }
            else if (SOLB)
            {
                while(!SOLA && srfL < 50)
                {
                    set_m=spin_speed(1,15,3);
                    set_s=spin_speed(1,15,7);
                    Move(4);
                    set_bits();
                }
            }
            else STOP();
        }
         if(SOLA)
            {
                Move(4);
            }
            else if (SOFA || SOFB)
            {
                if(SOFA) Move(7);
                else if (SOFB)
                {
                    while(!SOFA)
                    {
                        set_m=spin_speed(1,15,3);
                        set_s=spin_speed(1,15,7);
                        Move(7);
                        set_bits();
                        if(srfB < 50)
                        {
                            Move(8);
                            delay(300);
                            break;
                        }
                    }
                }
            }
            else if (SOBA || SOBB)
            {
                if(SOBA) Move(1);
                else if(SOBB)
                {
                    while(!SOBA && srfB < 50)
                    {
                        set_m=spin_speed(1,15,3);
                        set_s=spin_speed(1,15,7);
                        Move(1);
                        set_bits();
                    }
                }
            }
            else if (SOLB)
            {
                while(!SOLA && srfL < 50)
                {
                    set_m=spin_speed(1,15,3);
                    set_s=spin_speed(1,15,7);
                    Move(4);
                    set_bits();
                }
            }
            else STOP();
        }

    else if(SOFA || SOFB)
    {
        while(big_sensor_num > 11 || big_sensor_num < 5)
        {
            biggest();
            biggest();
            set_bits();
            set_m=spin_speed(1,15,3);
            set_s=spin_speed(1,15,7);
            if(SOFA)
            {
                Move(8);
            }
            else if (SORA || SORB)
            {
                if(SORA) Move(9);
                else if (SORB)
                {
                    while(!SORA && srfR < 50)
                    {
                        Move(9);
                        set_bits();
                        set_m=spin_speed(1,15,3);
                        set_s=spin_speed(1,15,7);
                    }
                }
            }
            else if (SOLA || SOLB)
            {
                if(SOLA) Move(7);
                else if(SOLB)
                {
                    while(!SOLA && srfL < 50)
                    {
                        Move(7);
                        set_bits();
                        set_m=spin_speed(1,15,3);
                        set_s=spin_speed(1,15,7);
                    }
                }
            }
            else if (SOFB)
            {
            while(!SOFA)
                {
                    Move(8);
                    set_bits();
                    set_m=spin_speed(1,15,3);
                    set_s=spin_speed(1,15,7);
                    if(srfB < 50)
                    {
                        Move(8);
                        delay(300);
                        break;
                    }
                }
            }
            else STOP();
        }
        if(SOFA)
            {
                Move(8);
            }
            else if (SORA || SORB)
            {
                if(SORA) Move(9);
                else if (SORB)
                {
                    while(!SORA && srfR < 50)
                    {
                        Move(9);
                        set_bits();
                        set_m=spin_speed(1,15,3);
                        set_s=spin_speed(1,15,7);
                    }
                }
            }
            else if (SOLA || SOLB)
            {
                if(SOLA) Move(7);
                else if(SOLB)
                {
                    while(!SOLA && srfL < 50)
                    {
                        Move(7);
                        set_bits();
                        set_m=spin_speed(1,15,3);
                        set_s=spin_speed(1,15,7);
                    }
                }
            }
            else if (SOFB)
            {
            while(!SOFA)
                {
                    Move(8);
                    set_bits();
                    set_m=spin_speed(1,15,3);
                    set_s=spin_speed(1,15,7);
                    if(srfB < 50)
                    {
                        Move(8);
                        delay(300);
                        break;
                    }
                }
            }
            else STOP();
        }

    else if(SOBA || SOBB)
    {
        while(big_sensor_num < 13 && big_sensor_num > 3)
        {
            biggest();
            biggest();
            set_bits();
            set_m=spin_speed(1,15,3);
            set_s=spin_speed(1,15,7);
            if(SOBA)
            {
                Move(0);
            }
            else if (SORA || SORB)
            {
                if(SORA) Move(15);
                else if (SORB)
                {
                    while(!SORA && srfR < 50)
                    {
                        set_m=spin_speed(1,15,3);
                        set_s=spin_speed(1,15,7);
                        Move(15);
                        set_bits();
                    }
                }
            }
            else if (SOLA || SOLB)
            {
                if(SOLA) Move(1);
                else if(SOLB)
                {
                    while(!SOLA && srfL < 50)
                    {
                        set_m=spin_speed(1,15,3);
                        set_s=spin_speed(1,15,7);
                        Move(1);
                        set_bits();
                    }
                }
            }
            else if (SOBB)
            {
                while(!SOBA && srfB <50)
                {
                    set_m=spin_speed(1,15,3);
                    set_s=spin_speed(1,15,7);
                    Move(0);
                    set_bits();
                }
            }
            else STOP();
        }
         if(SOBA)
            {
                Move(0);
            }
            else if (SORA || SORB)
            {
                if(SORA) Move(15);
                else if (SORB)
                {
                    while(!SORA && srfR < 50)
                    {
                        set_m=spin_speed(1,15,3);
                        set_s=spin_speed(1,15,7);
                        Move(15);
                        set_bits();
                    }
                }
            }
            else if (SOLA || SOLB)
            {
                if(SOLA) Move(1);
                else if(SOLB)
                {
                    while(!SOLA && srfL < 50)
                    {
                        set_m=spin_speed(1,15,3);
                        set_s=spin_speed(1,15,7);
                        Move(1);
                        set_bits();
                    }
                }
            }
            else if (SOBB)
            {
                while(!SOBA && srfB < 50)
                {
                    set_m=spin_speed(1,15,3);
                    set_s=spin_speed(1,15,7);
                    Move(0);
                    set_bits();
                }
            }
            else STOP();
    }
    else
    {
        if(big_sensor > noise) follow();
        else STOP();
    }
 }
 
 //////////////////////////STOP///////////////////////////////////
 void STOP(void)
 {
    reduction=1;
    MOTOR(set_s,set_s,set_s,set_s);
 }
 ////////////////////////MOVE WIDTH//////////////////////////////
 
void MoveWidth (void)
{
if(big_sensor_num!=0 && big_sensor_num<4 && big_sensor > noise && srfR > 145)
          {
           reduction =0.5;
           Move(4);
          }

else if (big_sensor_num>12 && big_sensor > noise && srfL > 145)
          {
           reduction =0.5;
           Move(12);
          }
          else
          {
          STOP();
          }
}
void Move_Width (void)
 {
if(big_sensor_num>0 && big_sensor_num<4 && srfR > 80)
          {
           reduction=0.5;
           Move(4);
          }
else if (big_sensor_num<16 && big_sensor_num>12 && srfL>80)
          {
            reduction=0.5;
            Move(12);
          }
         else
          {
            STOP();
          }
}

/////////////////////////////////////////////////////////////////
//,,,,,,,,,,,,,,,,,,,,,,,,,BLUETOOTH,,,,,,,,,,,,,,,,,,,,,,,,,,//
////////////////////////////////////////////////////////////////
void send_data(void)
 {
  char buf[5];
  sprintf(buf,"%2d",big_sensor_num);
  Serial.print(buf);
  sprintf(buf,"%3d",big_sensor);
  Serial.print(buf);  
  sprintf(buf,"%2d",location);
  Serial.println(buf); 
 }

int StringInter (char *input, int start,int end)
 {
    int j;
    char heyvoon[15];
    for(j=start;j<=end;j++)
    {
        heyvoon[j-start] = input[j];
    }
    return atoi(heyvoon);
 }

void bluetooth_analyze(void)
 {
    other_location = StringInter(bluetooth_input,3,3);
    other_big_sensor = StringInter(bluetooth_input,1,2);
    other_dn=bluetooth_input[4];
 }

void bluetooth_manager(void)
 {
    bluetooth_analyze();
    if((big_sensor_num <= 2 || big_sensor_num>=14) && (other_big_sensor>2 && other_big_sensor<14) && location==1)
    {
        Mode='F';
        O_Mode='G';
    }
    else if((big_sensor_num<14 && big_sensor_num>2) && (other_big_sensor<=2 || other_big_sensor>=14) && other_location==1)
    {
        Mode='G';
        O_Mode='F';
    }
 }

 ////////////////////////////VOLTAGE BATTERY/////////////////////////////
 void get_battery_voltage()
 {
    battery_voltage=(convert_adc(44)*12.4)/524;
 }

 /////////////////////////WIN///////////////////////
 void win(void)
 {
    BUZ=1;
    delay(200);
    BUZ=0;
    delay(150);

    BUZ=1;
    delay(200);
    BUZ=0;
    delay(150);

    BUZ=1;
    delay(100);
    BUZ=0;
    delay(100);

    BUZ=1;
    delay(100);
    BUZ=0;
    delay(150);

    BUZ=1;
    delay(200);
    BUZ=0;
    delay(200);
 }
 ////////////////////////CHECK EN////////////////////////////////
  void EN (void)
      {
        biggest();
        if (big_sensor_num!=0 && big_sensor_num<8 && srfR>75 )
        {
        Move(4);
        }
        else if (big_sensor_num>8 && srfL>75)
        {
        Move(12);
        }
         else
         {
          set_m=spin_speed(2,10,3);
          set_s=spin_speed(1,20,5);
          STOP();
          }
      }
      
///////////////////////////GOAL KEEPER///////////////////////////

void BackToGoal(void)
 {
    reduction = 0.7;
    stop_out = 1;
    Out= 'A';
    if (abs(Compass) > 20){
        STOP();
    }
    else if (srfL<40 && srfR <40 &&  srfB<40)
    {
        Move(0);
    }
    else if (srfL < 50 && srfR > 60)
    {
    if((SORA || SORB) && (SOFA != 1 && SOLA != 1 && SOBA !=0)) Move(6);
    else Move(4) ;
    }
    else if (srfR < 50 && srfL > 60)
    {
    if((SOLA || SOLB) && (SOFA != 1 && SORA != 1 && SOBA !=0)) Move(10);
    else Move(11);
    }
    else if (srfB > 60)
    {
    Move(8);
    }
    else if (srfB < 30)
    {                                                           
    Move(0);
    }
    else
    {
    if(big_sensor > noise)
    {
       EN();
    }
    else STOP();
    }

 }
////////////////////////////Raha///////////////////////////////

 void Raha (void)
 {
    if(abs(Compass) < 8)
    {
        if(Out!='A' && Out != Out_old) Out_old=Out;
        if (Out == 'R' && (big_sensor_num >= 8))  {Out = 'A';}
        if (Out == 'L' && (big_sensor_num <= 8 && big_sensor_num >=0))   {Out = 'A';}
        if (Out == 'F' && (big_sensor_num >= 4 && big_sensor_num <= 12)) {Out = 'A';}
        if (Out == 'B' && (big_sensor_num <= 4 || big_sensor_num >= 12)) {Out = 'A';}
    }
 }


///////////////////////////srf///////////////////////////////////
void ultrasonic()
{
    Wire.beginTransmission(112);
    Wire.write(byte(0x00));
    Wire.write(byte(0x51));
    Wire.endTransmission();
    Wire.beginTransmission(113);
    Wire.write(byte(0x00));
    Wire.write(byte(0x51));
    Wire.endTransmission();
    Wire.beginTransmission(114);
    Wire.write(byte(0x00));
    Wire.write(byte(0x51));
    Wire.endTransmission();
 
// ////////////////////////////////////////////////////////////////////////////////
    Wire.beginTransmission(112);
    Wire.write(byte(0x02));
    Wire.endTransmission();
    Wire.requestFrom(112, 2);
    if (2 <= Wire.available())
    {
      reader[3] = Wire.read();
      reader[3] = reader[3] << 8;
      reader[3] |= Wire.read();
    }
    Wire.beginTransmission(113);
    Wire.write(byte(0x02));
    Wire.endTransmission();
    Wire.requestFrom(113, 2);
    if (2 <= Wire.available())
    {
      reader[1] = Wire.read();
      reader[1] = reader[1] << 8;
      reader[1] |= Wire.read();
    }
    Wire.beginTransmission(114);
    Wire.write(byte(0x02));
    Wire.endTransmission();
    Wire.requestFrom(114, 2);
    if (2 <= Wire.available())
    {
      reader[2] = Wire.read();
      reader[2] = reader [2] << 8;
      reader[2] |= Wire.read();
    }
  
}
//////////////////////BIG SENSOR/////////////////////////////////
 void biggest(void)
 {
  int i,c;
  int MAX=0;
    for(i=0;i<16;i++)
    {
        if(MAX < SENSOR[i])
        {
      c = i;
      MAX=SENSOR[i];
    }
  }
  big_sensor = MAX;
  big_sensor_num = c;

 }
  //    set_m=spin_speed(1,15,3);
 //   set_s=spin_speed(1,15,7);

/////////////////////////SetuP//////////////////////////////////
void setup() 
{
//=====================PINS=============================//
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
void loop()
{
  
}
