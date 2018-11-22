////4/////////////MOTOR///////////////////////////////
void MOTOR(int pwmlf, int pwmlb, int pwmrf, int pwmrb)
{
  char buf[25];
  pwmlf = pwmlf * 1 * reduction;
  pwmlb = pwmlb * 1 * reduction;
  pwmrf = pwmrf * 1 * reduction;
  pwmrb = pwmrb * 1 * reduction;


  if (pwmlf > 1023)   pwmlf = 1023;
  if (pwmlb > 1023)   pwmlb = 1023;
  if (pwmrb > 1023)   pwmrb = 1023;
  if (pwmrf > 1023)   pwmrf = 1023;
  if (pwmlf < -1023)   pwmlf = -1023;
  if (pwmlb < -1023)   pwmlb = -1023;
  if (pwmrb < -1023)   pwmrb = -1023;
  if (pwmrf < -1023)   pwmrf = -1023;

  //*********************Left's MOTOR MAIN
  if (pwmlf > 0)
  {
    digitalWrite(GPIO_MLF, LOW);
    analogWrite(PWM_MLF, pwmlf);
  }
  else if (pwmlf < 0)
  {
    digitalWrite(GPIO_MLF, HIGH);
    analogWrite(PWM_MLF, 1023 + pwmlf);
  }
  else if (pwmlf == 0)
  {
    digitalWrite(GPIO_MLF,HIGH);
    analogWrite(PWM_MLF, 1023);
  }

  //*********************Left's MOTOR MAIN
  if (pwmlb > 0)
  {
    digitalWrite(GPIO_MLB, LOW);
    analogWrite(PWM_MLB, pwmlb);
  }
  else if (pwmlb < 0)
  {
    digitalWrite(GPIO_MLB, HIGH);
    analogWrite(PWM_MLB, pwmlb + 1023);
  }
  else if (pwmlb == 0)
  {
    digitalWrite(GPIO_MLB,HIGH);
    analogWrite(PWM_MLB, 1023);
  }
  //*********************Right's MOTOR MAIN
  if (pwmrf > 0)
  {
    digitalWrite(GPIO_MRF, LOW);
    analogWrite(PWM_MRF, pwmrf);
  }
  else if (pwmrf < 0)
  {
    digitalWrite(GPIO_MRF, HIGH);
    analogWrite(PWM_MRF, pwmrf + 1023);
  }
  else if (pwmrf == 0)
  {
    digitalWrite(GPIO_MRF, HIGH);
    analogWrite(PWM_MRF, 1023);
  }
  //*********************Right's MOTOR MAIN
  if (pwmrb > 0)
  { digitalWrite(GPIO_MRB, LOW);
    analogWrite(PWM_MRB, pwmrb);
  }
  else if (pwmrb < 0)
  {
    digitalWrite(GPIO_MRB, HIGH);
    analogWrite(PWM_MRB, pwmrb + 1023);

  }
  else if (pwmrb == 0)
  {
    digitalWrite(GPIO_MRB, HIGH);
    analogWrite(PWM_MRB, 1023);
  }
  sprintf(buf, "%d,%d,%d,%d ", pwmlf, pwmlb, pwmrf, pwmrb);
  Serial.println(buf);
}
////8////MOVEMENT//////////////////////////////
////int set_m=0;
void Move(int a)
{

  switch (a)
  {
    case 0:
      MOTOR(1023 + set_m, 1023 + set_m, -1023 + set_m, -1023 + set_m);
      break;

    case 1:
      MOTOR(1023 + set_m, 512 + set_m, -512 + set_m, -1023 + set_m);
      break;

    case 2:
      MOTOR(1023 + set_m, 0 + set_m, 0 + set_m, -1023 + set_m);
      break;

    case 3:
      MOTOR(1023 + set_m, -512 + set_m, 512 + set_m, -1023 + set_m);
      break;

    case 4:
      MOTOR(1023 + set_m, -1023 + set_m, 1023 + set_m, -1023 + set_m);
      break;

    case 5:
      MOTOR(512 + set_m, -1023 + set_m, 1023 + set_m, -512 + set_m);
      break;

    case 6:
      MOTOR(0 + set_m, -1023 + set_m, 1023 + set_m, 0 + set_m);
      break;

    case 7:
      MOTOR(-512 + set_m, -1023 + set_m, 1023 + set_m, 512 + set_m);
      break;

    case 8:
      MOTOR(-1023 + set_m, -1023 + set_m, 1023 + set_m, 1023 + set_m);
      break;

    case 9:
      MOTOR(-1023 + set_m, -512 + set_m, 512 + set_m, 1023 + set_m);
      break;

    case 10:
      MOTOR(-1023 + set_m, 0 + set_m, 0 + set_m, 1023 + set_m);
      break;

    case 11:
      MOTOR(-1023 + set_m, 512 + set_m, -512 + set_m, 1023 + set_m);
      break;

    case 12:
      MOTOR(-1023 + set_m, 1023 + set_m, -1023 + set_m, 1023 + set_m);
      break;

    case 13:
      MOTOR(-512 + set_m, 1023 + set_m, -1023 + set_m, 512 + set_m);
      break;

    case 14:
      MOTOR(0 + set_m, 1023 + set_m, -1023 + set_m, 0 + set_m);
      break;

    case 15:
      MOTOR(512 + set_m, 1023 + set_m, -1023 + set_m, -512 + set_m);
      break;
  }
  Movement = a;
}
//9//////////////////////////////////////////////////////////////
//*************************FOLLOW****************************//
//////////////////////////////////////////////////////////////
void follow(void)
{
  refreshs();
  biggestt();
  //  if (big_sensor > distance)
  //  {
  //    set_bits();
  //    if (SORB == 1)
  //    {
  //      stop_out = 1;
  //      Move(9);
  //    }
  //    else if (SOLB == 1)
  //    {
  //      stop_out = 1;
  //      Move(7);
  //    }
  //    else if (SOBA == 1 && big_sensor_num > 1 && big_sensor_num < 8)
  //    {
  //      stop_out = 0;
  //      Move(4);
  //    }
  //    else if (SOBA == 1 && big_sensor_num < 13 && big_sensor_num > 9)
  //    {
  //      stop_out = 1;
  //      Move(12);
  //    }
  //    else if (SOBB == 1  && big_sensor_num > 3 && big_sensor_num < 8)
  //    {
  //      stop_out = 1;
  //      Move(2);
  //    }
  //    else if (SOBB == 1  && big_sensor_num < 13 && big_sensor_num > 9)
  //    {
  //      stop_out = 1;
  //      Move(13);
  //    }
  //    else
  //    {
  //      switch (big_sensor_num)
  //      {
  //        case 0:
  //          Move(0);
  //          break;
  //
  //        case 1:
  //          Move(2);
  //          break;
  //
  //        case 2:
  //          Move(4);
  //          break;
  //
  //        case 3:
  //          Move(5);
  //          break;
  //
  //        case 4:
  //          Move(6);
  //          break;
  //
  //        case 5:
  //          Move(8);
  //          break;
  //
  //        case 6:
  //          Move(8);
  //          break;
  //
  //        case 7:
  //          Move(10);
  //          break;
  //
  //        case 8:
  //          Move(5);
  //          break;
  //
  //        case 9:
  //          Move(6);
  //          break;
  //
  //        case 10:
  //          Move(8);
  //          break;
  //
  //        case 11:
  //          Move(8);
  //          break;
  //
  //        case 12:
  //          Move(10);
  //          break;
  //
  //        case 13:
  //          Move(11);
  //          break;
  //
  //        case 14:
  //          Move(11);
  //          break;
  //
  //        case 15:
  //          Move(14);
  //          break;
  //    //  }
  //    }

  //  }
  //  else
  //  {
  switch (big_sensor_num)
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
//-}

////11///////////////////////STOP///////////////////////////////////
//void STOP(void)
//{
//  reduction = 1;
//  MOTOR(set_s, set_s, set_s, set_s);
//}
