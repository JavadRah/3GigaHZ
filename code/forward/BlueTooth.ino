////13///////////////////////////////////////////////////////////////
////,,,,,,,,,,,,,,,,,,,,,,,,,BLUETOOTH,,,,,,,,,,,,,,,,,,,,,,,,,,//
//////////////////////////////////////////////////////////////////
//void send_data(void)
//{
//  char buf[5];
//  sprintf(buf, "%2d", big_sensor_num);
//  Serial.print(buf);
//  sprintf(buf, "%3d", big_sensor);
//  Serial.print(buf);
//  sprintf(buf, "%2d", location);
//  Serial.println(buf);
//}
//
//int StringInter (char *input, int start, int end)
//{
//  int j;
//  char heyvoon[15];
//  for (j = start; j <= end; j++)
//  {
//    heyvoon[j - start] = input[j];
//  }
//  return atoi(heyvoon);
//}
//
//void bluetooth_analyze(void)
//{
//  other_location = StringInter(bluetooth_input, 3, 3);
//  other_big_sensor = StringInter(bluetooth_input, 1, 2);
//  other_dn = bluetooth_input[4];
//}
//
//void bluetooth_manager(void)
//{
//  bluetooth_analyze();
//  if ((big_sensor_num <= 2 || big_sensor_num >= 14) && (other_big_sensor > 2 && other_big_sensor < 14) && location == 1)
//  {
//    Mode = 'F';
//    O_Mode = 'G';
//  }
//  else if ((big_sensor_num < 14 && big_sensor_num > 2) && (other_big_sensor <= 2 || other_big_sensor >= 14) && other_location == 1)
//  {
//    Mode = 'G';
//    O_Mode = 'F';
//  }
//}
