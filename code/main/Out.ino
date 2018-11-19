//10//////////////////////////////////////////////////////////////
//.......................OUT.................................//
///////////////////////////////////////////////////////////////

void OUT(void)
{
  if (SORA || SORB)
  {
    while (big_sensor_num < 8)
    {
      biggest();
      biggest();
      set_bits();
      set_m = spin_speed(1, 15, 3);
      set_s = spin_speed(1, 15, 7);
      if (SORA)
      {
        Move(12);
      }
      else if (SOFA || SOFB)
      {
        if (SOFA) Move(9);
        else if (SOFB)
        {
          while (!SOFA)
          {
            Move(9);
            set_bits();
            set_m = spin_speed(1, 15, 3);
            set_s = spin_speed(1, 15, 7);
            if (srfB < 50)
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
        if (SOBA) Move(15);
        else if (SOBB)
        {
          while (!SOBA && srfB < 50)
          {
            Move(15);
            set_bits();
            set_m = spin_speed(1, 15, 3);
            set_s = spin_speed(1, 15, 7);
          }
        }
      }
      else if (SORB)
      {
        while (!SORA && srfR < 50)
        {
          set_m = spin_speed(1, 15, 3);
          set_s = spin_speed(1, 15, 7);
          Move(12);
          set_bits();
        }
      }
      else STOP();
    }
    ////////////////////////////////////////// Khareje While /////////////////////////////////////////////////
    if (SORA)
    {
      Move(12);
    }
    else if (SOFA || SOFB)
    {
      if (SOFA) Move(9);
      else if (SOFB)
      {
        while (!SOFA)
        {
          Move(9);
          set_bits();
          set_m = spin_speed(1, 15, 3);
          set_s = spin_speed(1, 15, 7);
          if (srfB < 50)
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
      if (SOBA) Move(15);
      else if (SOBB)
      {
        while (!SOBA && srfB < 50)
        {
          Move(15);
          set_bits();
          set_m = spin_speed(1, 15, 3);
          set_s = spin_speed(1, 15, 7);
        }
      }
    }
    else if (SORB)
    {
      while (!SORA && srfR < 50)
      {
        set_m = spin_speed(1, 15, 3);
        set_s = spin_speed(1, 15, 7);
        Move(12);
        set_bits();
      }
    }
    else STOP();

  }
  else if (SOLA || SOLB)
  {
    while (big_sensor_num > 8)
    {
      biggest();
      biggest();
      set_bits();
      set_m = spin_speed(1, 15, 3);
      set_s = spin_speed(1, 15, 7);
      if (SOLA)
      {
        Move(4);
      }
      else if (SOFA || SOFB)
      {
        if (SOFA) Move(7);
        else if (SOFB)
        {
          while (!SOFA)
          {
            set_m = spin_speed(1, 15, 3);
            set_s = spin_speed(1, 15, 7);
            Move(7);
            set_bits();
            if (srfB < 50)
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
        if (SOBA) Move(1);
        else if (SOBB)
        {
          while (!SOBA && srfB < 50)
          {
            set_m = spin_speed(1, 15, 3);
            set_s = spin_speed(1, 15, 7);
            Move(1);
            set_bits();
          }
        }
      }
      else if (SOLB)
      {
        while (!SOLA && srfL < 50)
        {
          set_m = spin_speed(1, 15, 3);
          set_s = spin_speed(1, 15, 7);
          Move(4);
          set_bits();
        }
      }
      else STOP();
    }
    if (SOLA)
    {
      Move(4);
    }
    else if (SOFA || SOFB)
    {
      if (SOFA) Move(7);
      else if (SOFB)
      {
        while (!SOFA)
        {
          set_m = spin_speed(1, 15, 3);
          set_s = spin_speed(1, 15, 7);
          Move(7);
          set_bits();
          if (srfB < 50)
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
      if (SOBA) Move(1);
      else if (SOBB)
      {
        while (!SOBA && srfB < 50)
        {
          set_m = spin_speed(1, 15, 3);
          set_s = spin_speed(1, 15, 7);
          Move(1);
          set_bits();
        }
      }
    }
    else if (SOLB)
    {
      while (!SOLA && srfL < 50)
      {
        set_m = spin_speed(1, 15, 3);
        set_s = spin_speed(1, 15, 7);
        Move(4);
        set_bits();
      }
    }
    else STOP();
  }

  else if (SOFA || SOFB)
  {
    while (big_sensor_num > 11 || big_sensor_num < 5)
    {
      biggest();
      biggest();
      set_bits();
      set_m = spin_speed(1, 15, 3);
      set_s = spin_speed(1, 15, 7);
      if (SOFA)
      {
        Move(8);
      }
      else if (SORA || SORB)
      {
        if (SORA) Move(9);
        else if (SORB)
        {
          while (!SORA && srfR < 50)
          {
            Move(9);
            set_bits();
            set_m = spin_speed(1, 15, 3);
            set_s = spin_speed(1, 15, 7);
          }
        }
      }
      else if (SOLA || SOLB)
      {
        if (SOLA) Move(7);
        else if (SOLB)
        {
          while (!SOLA && srfL < 50)
          {
            Move(7);
            set_bits();
            set_m = spin_speed(1, 15, 3);
            set_s = spin_speed(1, 15, 7);
          }
        }
      }
      else if (SOFB)
      {
        while (!SOFA)
        {
          Move(8);
          set_bits();
          set_m = spin_speed(1, 15, 3);
          set_s = spin_speed(1, 15, 7);
          if (srfB < 50)
          {
            Move(8);
            delay(300);
            break;
          }
        }
      }
      else STOP();
    }
    if (SOFA)
    {
      Move(8);
    }
    else if (SORA || SORB)
    {
      if (SORA) Move(9);
      else if (SORB)
      {
        while (!SORA && srfR < 50)
        {
          Move(9);
          set_bits();
          set_m = spin_speed(1, 15, 3);
          set_s = spin_speed(1, 15, 7);
        }
      }
    }
    else if (SOLA || SOLB)
    {
      if (SOLA) Move(7);
      else if (SOLB)
      {
        while (!SOLA && srfL < 50)
        {
          Move(7);
          set_bits();
          set_m = spin_speed(1, 15, 3);
          set_s = spin_speed(1, 15, 7);
        }
      }
    }
    else if (SOFB)
    {
      while (!SOFA)
      {
        Move(8);
        set_bits();
        set_m = spin_speed(1, 15, 3);
        set_s = spin_speed(1, 15, 7);
        if (srfB < 50)
        {
          Move(8);
          delay(300);
          break;
        }
      }
    }
    else STOP();
  }

  else if (SOBA || SOBB)
  {
    while (big_sensor_num < 13 && big_sensor_num > 3)
    {
      biggest();
      biggest();
      set_bits();
      set_m = spin_speed(1, 15, 3);
      set_s = spin_speed(1, 15, 7);
      if (SOBA)
      {
        Move(0);
      }
      else if (SORA || SORB)
      {
        if (SORA) Move(15);
        else if (SORB)
        {
          while (!SORA && srfR < 50)
          {
            set_m = spin_speed(1, 15, 3);
            set_s = spin_speed(1, 15, 7);
            Move(15);
            set_bits();
          }
        }
      }
      else if (SOLA || SOLB)
      {
        if (SOLA) Move(1);
        else if (SOLB)
        {
          while (!SOLA && srfL < 50)
          {
            set_m = spin_speed(1, 15, 3);
            set_s = spin_speed(1, 15, 7);
            Move(1);
            set_bits();
          }
        }
      }
      else if (SOBB)
      {
        while (!SOBA && srfB < 50)
        {
          set_m = spin_speed(1, 15, 3);
          set_s = spin_speed(1, 15, 7);
          Move(0);
          set_bits();
        }
      }
      else STOP();
    }
    if (SOBA)
    {
      Move(0);
    }
    else if (SORA || SORB)
    {
      if (SORA) Move(15);
      else if (SORB)
      {
        while (!SORA && srfR < 50)
        {
          set_m = spin_speed(1, 15, 3);
          set_s = spin_speed(1, 15, 7);
          Move(15);
          set_bits();
        }
      }
    }
    else if (SOLA || SOLB)
    {
      if (SOLA) Move(1);
      else if (SOLB)
      {
        while (!SOLA && srfL < 50)
        {
          set_m = spin_speed(1, 15, 3);
          set_s = spin_speed(1, 15, 7);
          Move(1);
          set_bits();
        }
      }
    }
    else if (SOBB)
    {
      while (!SOBA && srfB < 50)
      {
        set_m = spin_speed(1, 15, 3);
        set_s = spin_speed(1, 15, 7);
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
//18//////////////////////////Raha///////////////////////////////

void Raha (void)
{
  if (abs(Compass) < 8)
  {
    if (Out != 'A' && Out != Out_old) Out_old = Out;
    if (Out == 'R' && (big_sensor_num >= 8))  {
      Out = 'A';
    }
    if (Out == 'L' && (big_sensor_num <= 8 && big_sensor_num >= 0))   {
      Out = 'A';
    }
    if (Out == 'F' && (big_sensor_num >= 4 && big_sensor_num <= 12)) {
      Out = 'A';
    }
    if (Out == 'B' && (big_sensor_num <= 4 || big_sensor_num >= 12)) {
      Out = 'A';
    }
  }
}

