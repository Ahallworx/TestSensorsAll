
// include libraries
#include <Adafruit_GPS.h>
#include <Servo.h>
#include <SD.h>
#include <SPI.h>

// declare serial constants
#define GPS_Serial Serial3
#define radio Serial2

// declare GPS
Adafruit_GPS GPS(&GPS_Serial);

// declare servo
Servo servo;

// define pin constants
#define ESC_RC_PW 2                 // Motor controller ESC
#define GPS_TXD 7                   // GPS comms
#define GPS_RXD 8                   // GPS comms
#define RADIO_TX 9                  // Xbee radio comms
#define RADIO_RX 10                 // Xbee radio comms
#define CURR_SENSOR 14              // Internal Current sensor
#define TEMPERATURE_SENSOR 15       // Internal Temperature sensor
#define LEAK_SENSOR 16              // Internal Leak sensor
#define INT_PRESS_SENSOR 17         // Internal Pressure sensor
#define IMU_SDA 18                  // 
#define IMU_SCL 19                  //
#define SOLENOID_1 20               // Solenoid 1
#define SOLENOID_2 21               // -//-     2
#define SOLENOID_3 22               // -//-     3
#define DEPTH_SENSOR 23             // External Pressure sensor (Teensy pin matched ok.)
#define BATTERY_SENSOR_EN 31        // Battery Cell Tap Sense enable pin 
#define BATTERY_CELL_READ 32        // For 4 cell Batt use
#define THIRD_CELL_READ 33          // Batt cell 3
#define SECOND_CELL_READ 34         // Batt cell 2
#define TOP_CELL_READ 35            // Batt cell 1 (top)
#define chipSelect BUILTIN_SDCARD   //SD card built in pin (teensy)

#define g 9.81 // (gravity m/s^2)
#define RHO 1025 // density of seawater (kg/m^3)
#define Vs 5 // voltage supplied to depth sensor (V)
#define Vt 3 //voltage value input into teensy (V)

// Declare the moving average window size, latitude/longitude buffers and initialization flag
const int winsz = 10;
double zbuffer[winsz];
boolean avginit = true;

double current;
double pressure;
double temp;
double leak;
  double sensorValue;
  double sensorVoltage_3V;
  double sensorVoltage_5V;
  double scaledVoltage;
  double pressure_psi;
  double pressure_Pa;
  double depth;
    double tSense3; 
    double tSense2;
    double tSenseTop;
    double tSense3_V;
    double tSense2_V;
    double tSenseTop_V;
      // Variables to store adc values read.
      int adcVal_curr;
      int adcVal_temp;
      int adcVal_leak;
      int adcVal_IntPress;
      // Variables for sensor calcs
      double temp_Vout3;
      double temp_Vout; 
char prtkey=0;

void setup() {
Serial.begin(9600);
pinMode(BATTERY_SENSOR_EN, OUTPUT); //set tapsense enable pin as output.
}

void loop() {
checkSafe();  //get internal sensor values
TapSenseMonitor(); //Battery tap sense values
getDepth();   //get depth pressure value
printSensor();


}
