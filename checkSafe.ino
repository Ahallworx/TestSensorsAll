void checkSafe(void)
{


// Get ADC values and store in variables.
adcVal_curr = analogRead(CURR_SENSOR);
adcVal_temp = analogRead(TEMPERATURE_SENSOR);
adcVal_leak= analogRead(LEAK_SENSOR);
adcVal_IntPress= analogRead(INT_PRESS_SENSOR);

////// DA conversions.
// Current Sensor:
double curr_Vout = (adcVal_curr*(3.3/1024));        //convert ADC current value to Vout value.
current = (0.11/(curr_Vout - 1.65));         //Current (A).
    //double currVal3 = (3.33*(adcVal_curr/1024));  //Use this scaling conversion if Voltage scale is 0-5v not 0-3.3.
    //double currVal5 = (5*(currVal3/3.3));         //-//-

// Pressure Sensor:
double press_Vout3 = ((adcVal_IntPress* 3)/1024);     //Scaled to 0-3vdc. 
double press_Vout5 = ((press_Vout3*5.5)/3);         //Scaled to 0-5.5.
pressure = (((press_Vout5/5.1)+.04)/(0.004));  //Pressure (kPa)

// Temperature Sensor:
temp_Vout3= (adcVal_temp*(3/1024));  //(adcVal_temp*(3/1024)+(.1)); convert ADC temp value to Vout value. 
temp_Vout=(((1.65*temp_Vout3)/3)+.1);         
temp = ((temp_Vout-.5)/.01);             //Temp in (deg. C).
 
// Leak Sensor:
leak = (adcVal_leak* (3.3/1024));  



////

////Vout equations:
//Current: Vout = 110mV/A+Vcc/2 , Vcc = 3.3 vdc, Vcc/2 = 1.65, Vout= (adcVal_curr*3.3)/1024
//Pressure: Vout=Vcc*(P*0.004-0.04)   Note: Vcc = 5.1+-0.25 Vdc
//Temp: Vout=(10mV*T)+500mV  >> Temp=((Vout-.5)/.01)
//Supply voltage to temp range is 100mV-1750mV (typ) for -40-125 C(deg)
//Vout=

//Leak: Vout = 3.3+ full range roughly.  Determine arbitrary thresh for leek(voltage drop)
// 1. Get the safe ranges for each sensor.
//      * Current:
//      * Press:
//      * Temp:
//      * Leak:

// 5. Determine Abort procedure if out of range value.
// 6. Send message of out of range/non safe condition.
    //pinMode(CURR_SENSOR, INPUT); //WHAT DOES THIS READ???  
    //pinMode(TEMPERATURE_SENSOR, INPUT); //FIND IN ANSYS IN CDR FOR MAX TEMP.
    //pinMode(LEAK_SENSOR, INPUT); //ON OFF SWITCH? OR RANGE?
    //pinMode(INT_PRESS_SENSOR, INPUT); //WHAT IS THE SENSOR READING AND RANGE?

//// Pressure (internal)----------------------------------------
  // Check for signal of internal pressure sensor
 /* if (!analogRead(INT_PRESS_SENSOR))
  {   
  // Send error message to Serial Monitor
  Serial.println(F("No internal pressure sensor signal, check sensor!"));
  }
    else if(analogRead(INT_PRESS_SENSOR))
    {
    // Send OK GO msg.
    Serial.println(F("Internal Pressure Sensor GO!"));
    }
    
    
//// Temperature------------------------------------------------
  // Check for signal of temperature sensor
  if (!analogRead(TEMPERATURE_SENSOR))
  {   
  // Send error message to Serial Monitor
  Serial.println(F("No temperature sensor signal, check sensor!"));
  }
    else if(analogRead(TEMPERATURE_SENSOR))
    {
    // Send OK GO msg.
    Serial.println(F("Internal Temp Sensor GO!"));
    }
    
//// Current (Battery)--------------------------------------------
  // Check for signal of temperature sensor
  if (!analogRead(CURR_SENSOR))
  {   
  // Send error message to Serial Monitor
  Serial.println(F("No current sensor signal, check sensor!"));
  }
    else if(analogRead(CURR_SENSOR))
    {
    // Send OK GO msg.
    Serial.println(F("Internal Current Sensor GO!"));
    }
//// Leak Detect------------------------------------------------------  
  // Check for signal of leak sensor
  if (!analogRead(LEAK_SENSOR))
  {   
  // Send error message to Serial Monitor
  Serial.println(F("No leak sensor signal, check sensor!"));
  }
    else if(analogRead(LEAK_SENSOR))
    {
    // Send OK GO msg.
    Serial.println(F("Internal Leak Sensor GO!"));
    }
*/
}
