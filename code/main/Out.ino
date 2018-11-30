//.......................OUT.................................//
//10/////////////////////////////////////////////////////////////
//
void OUT(void)
{
  reduction=0.3;
  set_bits();
  biggestt();

  if (ra || rb)
  {
    while (big_sensor_num < 8)
    {
      biggestt();
      set_bits();
//       set_m = spin_speed(1, 40, 10);
//       set_s = spin_speed(1, 40, 10);
     if (ra)
      {
        Move(12);   
      }
      else if (fa || fb)
      {
        if (fa) Move(9);
        else if (fb)
        {
          while (!fa)
          {
            Move(9);
            set_bits();
//             set_m = spin_speed(1, 40, 10);
//             set_s = spin_speed(1, 40, 10);
      /*      if (srfB < 50)
            {
              Move(8);
              delay(300);
              break;
            }*/
          }
        }
      }
      else if (ba || bb)
      {
        if (ba) Move(15);
        else if (bb)
        {
          while (!ba /*&& srfB < 50*/)
          {
            Move(15);
            set_bits();
//            set_m = spin_speed(1, 40, 10);
//            set_s = spin_speed(1, 40, 10);
          }
        }
      }
      else if (rb)
      {
        while (!ra /*&& srfR < 50*/)
        {
//            set_m = spin_speed(1, 40, 10);
//            set_s = spin_speed(1, 40, 10);
          Move(12);
          set_bits();
        }
      }
      else 
      STOP();
      ;
    }
    ////////////////////////////////////////// Khareje While /////////////////////////////////////////////////
    if (ra)
    {
      Move(12);
    }
    else if (fa || fb)
    {
      if (fa) Move(9);
      else if (fb)
      {
        while (!fa)
        {
          Move(9);
          set_bits();
            set_m = spin_speed(1, 40, 10);
            set_s = spin_speed(1, 40, 10);
         /* if (srfB < 50)
          {
            Move(8);
            delay(300);
            break;
          }*/
        }
      }
    }
    else if (ba || bb)
    {
      if (ba) Move(15);
      else if (bb)
      {
        while (!ba /*&& srfB < 50*/)
        {
          Move(15);
          set_bits();
            set_m = spin_speed(1, 40, 10);
            set_s = spin_speed(1, 40, 10);
        }
      }
    }
    else if (rb)
    {
      while (!ra /*&& srfR < 50*/)
      {
            set_m = spin_speed(1, 40, 10);
            set_s = spin_speed(1, 40, 10);
        Move(12);
        set_bits();
      }
    }
    else STOP();

  }
  else if (la || lb)
  {
    //boogh();
    while (big_sensor_num > 8)
    {
      biggestt();
      biggestt();
      set_bits();
            set_m = spin_speed(1, 40, 10);
            set_s = spin_speed(1, 40, 10);
      if (la)
      {
        Move(4);
      }
      else if (fa || fb)
      {
        if (fa) Move(7);
        else if (fb)
        {
          while (!fa)
          {
            set_m = spin_speed(1, 40, 10);
            set_s = spin_speed(1, 40, 10);
            Move(7);
            set_bits();
           /* if (srfB < 50)
            {
              Move(8);
              delay(300);
              break;
            }*/
          }
        }
      }
      else if (ba || bb)
      {
        if (ba) Move(1);
        else if (bb)
        {
          while (!ba /*&& srfB < 50*/)
          {
            set_m = spin_speed(1, 40, 10);
            set_s = spin_speed(1, 40, 10);
            Move(1);
            set_bits();
          }
        }
      }
      else if (lb)
      {
        while (!la /*&& srfL < 50*/)
        {
            set_m = spin_speed(1, 40, 10);
            set_s = spin_speed(1, 40, 10);
          Move(4);
          set_bits();
        }
      }
      else STOP();
    }
    if (la)
    {
      Move(4);
    }
    else if (fa || fb)
    {
      if (fa) Move(7);
      else if (fb)
      {
        while (!fa)
        {
            set_m = spin_speed(1, 40, 10);
            set_s = spin_speed(1, 40, 10);
          Move(7);
          set_bits();
          /*if (srfB < 50)
          {
            Move(8);
            delay(300);
            break;
          }*/
        }
      }
    }
    else if (ba || bb)
    {
      if (ba) Move(1);
      else if (bb)
      {
        while (!ba /*&& srfB < 50*/)
        {
            set_m = spin_speed(1, 40, 10);
            set_s = spin_speed(1, 40, 10);
          Move(1);
          set_bits();
        }
      }
    }
    else if (lb)
    {
      while (!la /*&& srfL < 50*/)
      {
            set_m = spin_speed(1, 40, 10);
            set_s = spin_speed(1, 40, 10);
        Move(4);
        set_bits();
      }
    }
    else STOP();
  }

  else if (fa || fb)
  {
    while (big_sensor_num > 11 || big_sensor_num < 5)
    {
      biggestt();
      biggestt();
      set_bits();
            set_m = spin_speed(1, 40, 10);
            set_s = spin_speed(1, 40, 10);
      if (fa)
      {
        Move(8);
      }
      else if (ra || rb)
      {
        if (ra) Move(9);
        else if (rb)
        {
          while (!ra /*&& srfR < 50*/)
          {
            Move(9);
            set_bits();
            set_m = spin_speed(1, 40, 10);
            set_s = spin_speed(1, 40, 10);
          }
        }
      }
      else if (la || lb)
      {
        if (la) Move(7);
        else if (lb)
        {
          while (!la /*&& srfL < 50*/)
          {
            Move(7);
            set_bits();
            set_m = spin_speed(1, 40, 10);
            set_s = spin_speed(1, 40, 10);
          }
        }
      }
      else if (fb)
      {
        while (!fa)
        {
          Move(8);
          set_bits();
            set_m = spin_speed(1, 40, 10);
            set_s = spin_speed(1, 40, 10);
         /* if (srfB < 50)
          {
            Move(8);
            delay(300);
            break;
          }*/
        }
      }
      else STOP();
    }
    if (fa)
    {
      Move(8);
    }
    else if (ra || rb)
    {
      if (ra) Move(9);
      else if (rb)
      {
        while (!ra/* && srfR < 50*/)
        {
          Move(9);
          set_bits();
            set_m = spin_speed(1, 40, 10);
            set_s = spin_speed(1, 40, 10);
        }
      }
    }
    else if (la || lb)
    {
      if (la) Move(7);
      else if (lb)
      {
        while (!la /*&& srfL < 50*/)
        {
          Move(7);
          set_bits();
            set_m = spin_speed(1, 40, 10);
            set_s = spin_speed(1, 40, 10);
        }
      }
    }
    else if (fb)
    {
      while (!fa)
      {
        Move(8);
        set_bits();
            set_m = spin_speed(1, 40, 10);
            set_s = spin_speed(1, 40, 10);
      /*  if (srfB < 50)
        {
          Move(8);
          delay(300);
          break;
        }*/
      }
    }
    else STOP();
  }

  else if (ba || bb)
  {
    while (big_sensor_num < 13 && big_sensor_num > 3)
    {
      biggestt();
      biggestt();
      set_bits();
            set_m = spin_speed(1, 40, 10);
            set_s = spin_speed(1, 40, 10);
      if (ba)
      {
        Move(0);
      }
      else if (ra || rb)
      {
        if (ra) Move(15);
        else if (rb)
        {
          while (!ra /*&& srfR < 50*/)
          {
            set_m = spin_speed(1, 40, 10);
            set_s = spin_speed(1, 40, 10);
            Move(15);
            set_bits();
          }
        }
      }
      else if (la || lb)
      {
        if (la) Move(1);
        else if (lb)
        {
          while (!la /*&& srfL < 50*/)
          {
            set_m = spin_speed(1, 40, 10);
            set_s = spin_speed(1, 40, 10);
            Move(1);
            set_bits();
          }
        }
      }
      else if (bb)
      {
        while (!ba /*&& srfB < 50*/)
        {
            set_m = spin_speed(1, 40, 10);
            set_s = spin_speed(1, 40, 10);
          Move(0);
          set_bits();
        }
      }
      else STOP();
    }
    if (ba)
    {
      Move(0);
    }
    else if (ra || rb)
    {
      if (ra) Move(15);
      else if (rb)
      {
        while (!ra /*&& srfR < 50*/)
        {
            set_m = spin_speed(1, 40, 10);
            set_s = spin_speed(1, 40, 10);
          Move(15);
          set_bits();
        }
      }
    }
    else if (la || lb)
    {
      if (la) Move(1);
      else if (lb)
      {
        while (!la /*&& srfL < 50*/)
        {
            set_m = spin_speed(1, 40, 10);
            set_s = spin_speed(1, 40, 10);
          Move(1);
          set_bits();
        }
      }
    }
    else if (bb)
    {
      while (!ba /*&& srfB < 50*/)
      {
            set_m = spin_speed(1, 40, 10);
            set_s = spin_speed(1, 40, 10);
        Move(0);
        set_bits();
      }
    }
    else STOP();
  }
  
  else
  {
    if (big_sensor > noise) follow();
    else STOP();
    
  }
}
