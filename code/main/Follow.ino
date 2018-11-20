//
////8////MOVEMENT//////////////////////////////
//
//void Move(int a)
//{
//
//  switch (a)
//  {
//    case 0:
//      MOTOR(255 + set_m, 255 + set_m, -255 + set_m, -255 + set_m);
//      break;
//
//    case 1:
//      MOTOR(255 + set_m, 127 + set_m, -127 + set_m, -256 + set_m);
//      break;
//
//    case 2:
//      MOTOR(255 + set_m, 0 + set_m, 0 + set_m, -255 + set_m);
//      break;
//
//    case 3:
//      MOTOR(255 + set_m, -127 + set_m, 127 + set_m, -255 + set_m);
//      break;
//
//    case 4:
//      MOTOR(255 + set_m, -255 + set_m, 255 + set_m, -255 + set_m);
//      break;
//
//    case 45:
//      MOTOR(191 + set_m, -255 + set_m, 255 + set_m, -191 + set_m);
//      break;
//
//    case 5:
//      MOTOR(127 + set_m, -255 + set_m, 255 + set_m, -127 + set_m);
//      break;
//
//    case 6:
//      MOTOR(0 + set_m, -255 + set_m, 255 + set_m, 0 + set_m);
//      break;
//
//    case 7:
//      MOTOR(-127 + set_m, -255 + set_m, 255 + set_m, 127 + set_m);
//      break;
//
//    case 8:
//      MOTOR(-255 + set_m, -255 + set_m, 255 + set_m, 255 + set_m);
//      break;
//
//    case 9:
//      MOTOR(-255 + set_m, -127 + set_m, 127 + set_m, 255 + set_m);
//      break;
//
//    case 10:
//      MOTOR(-255 + set_m, 0 + set_m, 0 + set_m, 255 + set_m);
//      break;
//
//    case 11:
//      MOTOR(-255 + set_m, 127 + set_m, -127 + set_m, 255 + set_m);
//      break;
//
//    case 12:
//      MOTOR(-255 + set_m, 255 + set_m, -255 + set_m, 255 + set_m);
//      break;
//
//    case 13:
//      MOTOR(-127 + set_m, 255 + set_m, -255 + set_m, 127 + set_m);
//      break;
//
//    case 14:
//      MOTOR(0 + set_m, 255 + set_m, -255 + set_m, 0 + set_m);
//      break;
//
//    case 15:
//      MOTOR(127 + set_m, 255 + set_m, -255 + set_m, -127 + set_m);
//      break;
//
//    case 17:  //(0,15)
//      MOTOR(191 + set_m, 255 + set_m, -255 + set_m, -191 + set_m);
//      break;
//
//    case 18: //(15,17)
//      MOTOR(159 + set_m, 255 + set_m, -255 + set_m, -159 + set_m);
//      break;
//
//    case 19: //(8,7)
//      MOTOR(-191 + set_m, -255 + set_m, 255 + set_m, 191 + set_m);
//      break;
//    case 20: //(8,9)
//      MOTOR(-255 + set_m, -191 + set_m, 191 + set_m, 255 + set_m);
//      break;
//
//
//  }
//  Movement = a;
//}
////9//////////////////////////////////////////////////////////////
////*************************FOLLOW****************************//
////////////////////////////////////////////////////////////////
//void follow(void)
//{
//
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
//      }
//    }
//
//  }
//  else
//  {
//    switch (big_sensor_num)
//    {
//      case 0:
//        Move(0);
//        break;
//
//      case 1:
//        Move(1);
//        break;
//
//      case 2:
//        Move(2);
//        break;
//
//      case 3:
//        Move(3);
//        break;
//
//      case 4:
//        Move(4);
//        break;
//
//      case 5:
//        Move(5);
//        break;
//
//      case 6:
//        Move(6);
//        break;
//
//      case 7:
//        Move(7);
//        break;
//
//      case 8:
//        Move(8);
//        break;
//
//      case 9:
//        Move(9);
//        break;
//
//      case 10:
//        Move(10);
//        break;
//
//      case 11:
//        Move(11);
//        break;
//
//      case 12:
//        Move(12);
//        break;
//
//      case 13:
//        Move(13);
//        break;
//
//      case 14:
//        Move(14);
//        break;
//
//      case 15:
//        Move(15);
//        break;
//    }
//  }
//  //    }
//}
//
////11///////////////////////STOP///////////////////////////////////
//void STOP(void)
//{
//  reduction = 1;
//  MOTOR(set_s, set_s, set_s, set_s);
//}
