void printSensor(void)

{
  char portkey;
  if(Serial.available()>0)
  {
    portkey = (char)Serial.read(); //read serial data, cast as character into variable called portkey.
    switch (portkey)//switch variable for each case comparison.
    {
      case 'I': //print portkey list
      Serial.println("Press: ");
      Serial.println("P - Pressure");
      Serial.println("T - Temperature");
      Serial.println("C - Current");
      Serial.println("L - Leak voltage");
      Serial.println("B - Battery Cell voltages");
      Serial.println("D - External Pressure and Depth");

      break;
      
      case 'P': //print internal pressure.
      Serial.print("Pressure: ");
      Serial.print(pressure);
      Serial.println("(kPa)");

      break;

      case 'T': //print internal temperature.
      Serial.print("Temperature: ");
      Serial.print(temp);
      Serial.println("(deg C)");
      Serial.println(adcVal_temp);
      Serial.println(temp_Vout);
      Serial.println(temp_Vout3);

      break;

      case 'C': //print current amperage of system.
      Serial.print("Current:");
      Serial.print(current);
      Serial.println("(A)");

      break;

      case 'L': //print leak detector voltage.
      Serial.print("Leak:");
      Serial.print(leak);
      Serial.println("Volts");

      break;

      case 'B': //print battery cell voltages.
      Serial.print("Cell 3 Voltage: ");
      Serial.print(tSense3_V);
      Serial.println("volts");
      Serial.print("Cell 2 Voltage: ");
      Serial.print(tSense2_V);
      Serial.println("volts");
      Serial.print("Cell Top Voltage: ");
      Serial.print(tSenseTop_V);
      Serial.println("volts");

      break;

      case 'D': //print depth sensor pressure.
      Serial.print("External Pressure: ");
      Serial.print(pressure_Pa);
      Serial.println("(Pa)");
      Serial.print("Current Depth: ");
      Serial.print(depth);
      Serial.println("(m)");
      Serial.print("ADC value:");
      Serial.println(adcVal_IntPress);
      
    }
  }
}
