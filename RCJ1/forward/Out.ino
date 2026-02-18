//.......................OUT.................................//
//10/////////////////////////////////////////////////////////////
//
// Runtime guard to avoid getting stuck in sensor-driven while loops.
const unsigned long OUT_LOOP_TIMEOUT_MS = 350;
unsigned long out_loop_guard_started_at = 0;

bool out_loop_timed_out(void)
{
  if (millis() - out_loop_guard_started_at > OUT_LOOP_TIMEOUT_MS)
  {
    STOP();
    return true;
  }
  return false;
}

void OUT(void)
{
  out_loop_guard_started_at = millis();
  set_bits();
  biggestt();

  if (ra || rb)
  {
    while ((big_sensor_num < 8) && !out_loop_timed_out())
    {
      biggestt();
      set_bits();
      if (ra)
      {
        Move(12);
      }
      else if (fa || fb)
      {
        if (fa) Move(9);
        else if (fb)
        {
          while ((!fa) && !out_loop_timed_out())
          {
            Move(9);
            set_bits();
          }
        }
      }
      else if (ba || bb)
      {
        if (ba) Move(15);
        else if (bb)
        {
          while ((!ba /*&& srfB < 50*/) && !out_loop_timed_out())
          {
            Move(15);
            set_bits();
          }
        }
      }
      else if (rb)
      {
        while ((!ra /*&& srfR < 50*/) && !out_loop_timed_out())
        {
          Move(12);
          set_bits();
        }
      }
      else
        STOP();
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
        while ((!fa) && !out_loop_timed_out())
        {
          Move(9);
          set_bits();
        }
      }
    }
    else if (ba || bb)
    {
      if (ba) Move(15);
      else if (bb)
      {
        while ((!ba /*&& srfB < 50*/) && !out_loop_timed_out())
        {
          Move(15);
          set_bits();
        }
      }
    }
    else if (rb)
    {
      while ((!ra /*&& srfR < 50*/) && !out_loop_timed_out())
      {
        Move(12);
        set_bits();
      }
    }
    else STOP();

  }
  else if (la || lb)
  {
   
    while ((big_sensor_num > 8) && !out_loop_timed_out())
    {
      biggestt();
      set_bits();
      if (la)
      {
        Move(4);
      }
      else if (fa || fb)
      {
        if (fa) {
          Move(7);
        }
        else if (fb)
        {
          while ((!fa) && !out_loop_timed_out())
          {
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
        if (lb)
        {
          while ((!la) && !out_loop_timed_out())
          {
            set_bits();
            Move(4);
          }
          if (rb || ra)
          {
            while ((!la) && !out_loop_timed_out())
            {
              set_bits();
              Move(4);
            }
          }
        }
      }
      else if (ba || bb)
      {
        if (ba) Move(1);
        else if (bb)
        {
          while ((!ba /*&& srfB < 50*/) && !out_loop_timed_out())
          {
            Move(1);
            set_bits();
          }
        }
      }
      else if (lb)
      {
        while ((!la /*&& srfL < 50*/) && !out_loop_timed_out())
        {
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
        while ((!fa) && !out_loop_timed_out())
        {
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
        while ((!ba /*&& srfB < 50*/) && !out_loop_timed_out())
        {
          Move(1);
          set_bits();
        }
      }
    }
    else if (lb)
    {
      while ((!la /*&& srfL < 50*/) && !out_loop_timed_out())
      {
        Move(4);
        set_bits();
      }
    }
    else STOP();
  }
  else if (fa || fb)
  {
    while ((big_sensor_num > 11 || big_sensor_num < 5) && !out_loop_timed_out())
    {
      biggestt();
      biggestt();
      set_bits();
      if (fa)
      {
        Move(8);
      }
      else if (ra || rb)
      {
        if (ra) Move(9);
        else if (rb)
        {
          while ((!ra /*&& srfR < 50*/) && !out_loop_timed_out())
          {
            Move(9);
            set_bits();
          }
        }
      }
      else if (la || lb)
      {
        if (la) Move(7);
        else if (lb)
        {
          while ((!la /*&& srfL < 50*/) && !out_loop_timed_out())
          {
            Move(7);
            set_bits();
          }
        }
      }
      else if (fb)
      {
        while ((!fa) && !out_loop_timed_out())
        {
          Move(8);
          set_bits();
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
        while ((!ra/* && srfR < 50*/) && !out_loop_timed_out())
        {
          Move(9);
          set_bits();
        }
      }
    }
    else if (la || lb)
    {
      if (la) Move(7);
      else if (lb)
      {
        while ((!la /*&& srfL < 50*/) && !out_loop_timed_out())
        {
          Move(7);
          set_bits();
        }
      }
    }
    else if (fb)
    {
      while ((!fa) && !out_loop_timed_out())
      {
        Move(8);
        set_bits();
      }
    }
    else STOP();
  }

  else if (ba || bb)
  {
    while ((big_sensor_num < 13 && big_sensor_num > 3) && !out_loop_timed_out())
    {
      biggestt();
      biggestt();
      set_bits();
      if (ba)
      {
        Move(0);
      }
      else if (ra || rb)
      {
        if (ra) Move(15);
        else if (rb)
        {
          while ((!ra /*&& srfR < 50*/) && !out_loop_timed_out())
          {
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
          while ((!la /*&& srfL < 50*/) && !out_loop_timed_out())
          {
            Move(1);
            set_bits();
          }
        }
      }
      else if (bb)
      {
        while ((!ba /*&& srfB < 50*/) && !out_loop_timed_out())
        {
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
        while ((!ra /*&& srfR < 50*/) && !out_loop_timed_out())
        {
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
        while ((!la /*&& srfL < 50*/) && !out_loop_timed_out())
        {
          Move(1);
          set_bits();
        }
      }
    }
    else if (bb)
    {
      while ((!ba /*&& srfB < 50*/) && !out_loop_timed_out())
      {
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
