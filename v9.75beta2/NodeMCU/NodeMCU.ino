
// Fill-in information from your Blynk Template here
#define BLYNK_TEMPLATE_ID "***"
#define BLYNK_DEVICE_NAME "Rep Al Mower"
#define BLYNK_FIRMWARE_VERSION        "0.1.0"
#define BLYNK_PRINT Serial


//#define BLYNK_DEBUG
#define APP_DEBUG

//#define WEBSERVER			    // Uncomment if using WebServer - mower data on web page
//#define BLYNK_NOT_USED		// Uncomment if using blynk and web server in parrallel, comment when using only webserver without Blynk
//#define DBG_TELNET


// Enter the Auth code for the WEMOSD1 controlling the Wire ON/OFF
// If not used please leave blank "";
// char auth_WEMOS[] = "..";




// Uncomment your board, or configure a custom board in Settings.h
//#define USE_SPARKFUN_BLYNK_BOARD
#define USE_NODE_MCU_BOARD
//#define USE_WITTY_CLOUD_BOARD
//#define USE_WEMOS_D1_MINI

#include "BlynkEdgent.h"
#include "SerialCom_non_blocking.h"

SoftwareSerial NodeMCU(RX, TX);  //RXD2 TXD3
SerialCom NodeMCUCom (NodeMCU, 80);

#if defined(WEBSERVER)
#include <WiFiClient.h>
#include <ESP8266HTTPClient.h>
#include <ESP8266WebServer.h>
#include "WebPages.h"

ESP8266WebServer server(80);

IPAddress staticIP(192, 168, 1, 23);
IPAddress gateway(192, 168, 1, 254);
IPAddress subnet(255, 255, 255, 0);
IPAddress dns(10, 0, 0, 1);
#endif // -(WEBSERVER)-

#if defined(DBG_TELNET)
  #include "TelnetSpy.h"
  TelnetSpy Telnet;
  #define SerialDebug Telnet
#else
  #define SerialDebug Serial
#endif // -(DBG_TELNET)-

int   buttonState = 0;
int   Docked_Counts = 0;


// RX Variables
float val_VoltNow;                  // Battery Voltage from MEGA
float BatteryVoltage;               // Voltage read last RX
int Loop_Cycle_Mowing;              // Current Loop Cycle from MEGA

int Mower_Parked;
int Mower_Parked_Low_Batt;
int Mower_Docked;
int Mower_Docked_Filter;
int Mower_Running;
int Mower_Running_Filter;
int Mower_Lost;
int Charge_Detected;
int Tracking_Wire;
int Compass_Heading_Lock;


// Setting Sync 1
int Compass_Activate;
int Compass_Heading_Hold_Enabled;
int GYRO_Enabled;
int Sonar_1_Activate;
int Sonar_2_Activate;
int Sonar_3_Activate;
int Bumper_Activate_Frnt;


// Settings Sync 2
int Alarm_1_ON;
int Alarm_2_ON;
int Alarm_3_ON;
int GPS_Enabled;
int Angle_Sensor_Enabled;
int Tip_Over_Sensor_Enabled;
int Wheel_Amp_Sensor_ON;

int i;                              // Transmit blank code

bool Mower_Already_Started = 0;
bool Going_Home_Already = 0;

int j;
int k;
int transmit_blynk_code = 0;

bool Manuel_Mode;
int Automatic_Mode;
bool Wire_Status_ON_OFF;


int loopstatus = 0;
int All;
int RX_Data_Recieved;
bool RX_data_from_Mega_updated = false;  // show data on serial console only if they are refreshed
int lastConnectionAttempt = millis();
int connectionDelay = 5000; // try to reconnect every 5 seconds

// MEGA Check
int Loop_Cycle_Mowing_Check_1;
int Loop_Cycle_Mowing_Check_2;
float val_VoltNow_Check_1;
float val_VoltNow_Check_2;
int Check_MEGA = 0;
int Error_Loop;
int Error_Volt;
int Total_Error;
int Max_Error = 40;
int Sync_Settings_Now = 0;

//Mow Calendar Variables
byte Alarm_Hour_Now;
byte Time_Second;
byte Time_Minute;
byte Time_Hour;
byte Time_Date;
byte Time_Month;
int Time_Year;
byte Time_Day;


//LOOP_OPTIMIZE - loop cycle time optimization - send command to Blynk only when data are changed
// memory of last state of variables
int Compass_Activate_Last;
int Compass_Heading_Hold_Enabled_Last;
int GYRO_Enabled_Last;
int Sonar_1_Activate_Last;
int Sonar_2_Activate_Last;
int Sonar_3_Activate_Last;
int Bumper_Activate_Frnt_Last;
int Alarm_1_ON_Last;
int Alarm_2_ON_Last;
int Alarm_3_ON_Last;
int GPS_Enabled_Last;
int Angle_Sensor_Enabled_Last;
int Tip_Over_Sensor_Enabled_Last;
int Wheel_Amp_Sensor_ON_Last;
int Charge_Detected_Last;
int Tracking_Wire_Last;
int Mower_Parked_Last;
int Mower_Running_Filter_Last;
int Mower_Docked_Filter_Last;

bool V0_Last;
bool V1_Last;
bool V2_Last;
bool V10_Last;



// Settings NODEMCU
//----------------------------------------------------

// Node MCU Version

char  Version[16] = "V9.3";

bool Auto_Sync_Settings_Enabled = 0;        // Peridoically Syncs the settings tab on the APP with actual Mower Settings
bool MEGA_Watch_Enabled = 0;                // Detects if the Mower MEGA has forzen and resets it
bool Auto_Wire = 0;                         // Turns the wire on and off automatically (Requires PCB version of Wire transmitter)

/************************************************************************************************************/

float Amps;
byte Robot_Status_Value;
byte Low_Battery_Detected;
int MAG_Now;
byte Mower_RunBack;
byte Mower_Error_Value;
byte Compass_Steering_Status;
float WheelAmps;
float Compass_Heading_Degrees;
byte Manouver_Turn_Around_Phase;
byte Manouver_Turn_Around_Sonar_Phase;
byte PWM_Right;
byte PWM_Left;
float Compass_Error;
bool Sonar_Status;
bool Outside_Wire;
bool Bumper;
bool Tilt_Angle_Sensed;
bool Tilt_Orientation_Sensed;
bool GPS_Inside_Fence;
bool Rain_Detected;
bool Wheel_Blocked_Status;

int distance1;
int distance2;
int distance3;
byte Sonar_Hit_1_Total;
byte Sonar_Hit_2_Total;
byte Sonar_Hit_3_Total;
bool Wheels_Activate;
bool Ramp_Motor_ON;
bool MAG_Speed_Adjustment;
bool Perimeter_Wire_Enabled;
bool Use_Charging_Station;
bool Wire_Detected;
byte Wheel_Status_Value;

bool Fake_All_Settings;
bool Fake_Loops;
bool Fake_Wire;
bool Fake_WheelAmp;

String MowerTime = "00:00";

bool Blade_flagRun;

// struct for timer function in general.ino file
struct timerVar_t
{
	signed long ACC = 0;
	signed long REF = (signed long)millis();
	int PRE;
	bool flagRun = 0;
};
timerVar_t T10;

int Command; // Serial Command Input
bool F_EN[33]; // Blocking bit for quick enable/ disable function

//----------------------------------------------------

WidgetLED ParkedLED(V6);
WidgetLED MowingLED(V7);
WidgetLED DockedLED(V8);
WidgetLED TrackingLED(V9);
WidgetLED ChargingLED(V12);
WidgetLED ErrorLED(V11);



BlynkTimer timer;
WidgetBridge PCBWire_WEMOSD1(V1);

//BLYNK_CONNECTED() {
  // Place the AuthToken of the WEMOS D1 for the wire control
  // PCBWire_WEMOSD1.setAuthToken(auth_WEMOS);
//}


void myTimerEvent()  {
  if (  (BatteryVoltage > 10) && (BatteryVoltage < 15) ) {
    Blynk.virtualWrite(V3, BatteryVoltage);
  }

  Blynk.virtualWrite(V5, Loop_Cycle_Mowing);


}

void setup()
{
  SerialDebug.begin(115200);
  NodeMCU.begin(57600);
  NodeMCUCom.begin ();
  SerialDebug.println("");
  SerialDebug.println("");
  SerialDebug.println("");
  SerialDebug.println("");
  SerialDebug.println("");
  SerialDebug.print("ReP_AL Mower Node MCU Version:");
  SerialDebug.println(Version);
  SerialDebug.println("Setting up NODEMCU........");
  SerialDebug.println("");
  pinMode(RX, INPUT);
  pinMode(TX, OUTPUT);
  pinMode(D5, OUTPUT);
  digitalWrite(D5, HIGH);                             // Reset Switch
  pinMode(D6, OUTPUT);                                // ESP32 CAM ON/OFF Relay
  digitalWrite(BOARD_LED_PIN, HIGH);                          // Turn off LED Light
  pinMode(BOARD_LED_PIN, OUTPUT);
  timer.setInterval(1000L, myTimerEvent);
  BlynkEdgent.begin();

  Clear_APP();

#if defined(WEBSERVER)
  startServer();
#endif //-(WEBSERVER)-

#if defined(DBG_TELNET)
  //Telnet.begin();
#endif // -(DBG_TELNET)-
  }

void loop() {

  Check_Serial_Input();

  loopstatus = loopstatus + 1 ;
  RX_Data_Recieved = 0;                         // resets the data received bool

  BlynkEdgent.run();
  timer.run();
  //digitalWrite(LED, LOW);         //LED is inverted on a MODEMCU...
  Receive_All_From_MEGA();
  Update_Blynk_App_With_Status();
  if (Auto_Wire == 1) Set_PCB_Wire_Status();
  if (MEGA_Watch_Enabled == 1) Check_MEGA_Status();
  if (Auto_Sync_Settings_Enabled == 1) Sync_Settings();
  //SerialDebug.println("");     // new line serial monitor
  if (!Blynk.connected()) digitalWrite(BOARD_LED_PIN, LOW);
  if (!Blynk.connected()) digitalWrite(BOARD_LED_PIN, HIGH);

  RuntimeMeasuring(); // loop cycle time measuring
}
