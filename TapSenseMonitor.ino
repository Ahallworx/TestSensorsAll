void TapSenseMonitor()
{
digitalWrite(BATTERY_SENSOR_EN, HIGH);  //tapsense on
tSense3 = analogRead(THIRD_CELL_READ);  //adc read cell 3
tSense2 = analogRead(SECOND_CELL_READ); //adc read cell 2
tSenseTop = analogRead(TOP_CELL_READ);  //adc read cell top


tSense3_V = (((tSense3*3)/1024)*5.99);      //Voltage cell 3. 
tSense2_V = (((tSense2*3)/1024)*5.99);      //Voltage of cell 2.
tSenseTop_V = (((tSenseTop*3)/1024)*5.99);  //Voltage of Top cell.
//digitalWrite(BATTERY_SENSOR_EN, LOW);   //tapsense off
}


//tSense4 = analogRead(BATTERY_CELL_READ); //uncomment for 4 cell Batt
//tSense4_V = (((tSense4*3)/1024)*5.99);   //uncomment for 4 cell Batt
