/*
	RemoteXY_WIFI.h
	-- LawnBot --
	
	This source code of graphical user interface
	has been generated automatically by RemoteXY editor.
	To compile this code using RemoteXY library 2.4.3 or later version
	download by link http://remotexy.com/en/library/
	To connect using RemoteXY mobile app by link http://remotexy.com/en/download/
	- for ANDROID 4.5.1 or later version;
	- for iOS 1.4.1 or later version;
	
	This source code is free software; you can redistribute it and/or
	modify it under the terms of the GNU Lesser General Public
	License as published by the Free Software Foundation; either
	version 2.1 of the License, or (at your option) any later version.
*/



//////////////////////////////////////////////
//        RemoteXY include library          //
//////////////////////////////////////////////

// RemoteXY select connection mode and include library

//pick the right define for connect type
#define REMOTEXY_MODE__ESP8266_HARDSERIAL  //connect to exsisting WiFi Access Point, get IP, App connect to IP
//#define REMOTEXY_MODE__ESP8266_HARDSERIAL_POINT  //ESP8266 will create a WiFi Access Point
//#define REMOTEXY_MODE__ESP8266_HARDSERIAL_CLOUD  //conect to exsisting WiFi Access Point, then Cloud server
//#define REMOTEXY__DEBUGLOGS message_out

#include <RemoteXY.h>


// RemoteXY connection settings
#ifdef REMOTEXY_MODE__ESP8266_HARDSERIAL
	#define REMOTEXY_SERIAL Serial2
	#define REMOTEXY_SERIAL_SPEED 115200
	#define REMOTEXY_WIFI_SSID "PAGEWORLD"
	#define REMOTEXY_WIFI_PASSWORD "JOHN2018"
	#define REMOTEXY_SERVER_PORT 6377
#endif

// RemoteXY connection settings
#ifdef REMOTEXY_MODE__ESP8266_HARDSERIAL_CLOUD
	#define REMOTEXY_SERIAL Serial2
	#define REMOTEXY_SERIAL_SPEED 115200
	#define REMOTEXY_WIFI_SSID "PAGEWORLD"
	#define REMOTEXY_WIFI_PASSWORD "JOHN2018"
	#define REMOTEXY_CLOUD_SERVER "cloud.remotexy.com"
	#define REMOTEXY_CLOUD_PORT 6376
	#define REMOTEXY_CLOUD_TOKEN "68761ab39de863f1222b58f5a0acb5e7"
#endif

// RemoteXY connection settings
#ifdef REMOTEXY_MODE__ESP8266_HARDSERIAL_POINT
	#define REMOTEXY_SERIAL Serial2
	#define REMOTEXY_SERIAL_SPEED 115200
	#define REMOTEXY_WIFI_SSID "RemoteXY"
	#define REMOTEXY_WIFI_PASSWORD "12345678"
	#define REMOTEXY_SERVER_PORT 6377
#endif


// RemoteXY configurate  
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =   // 526 bytes
{ 255,33,0,144,0,7,2,16,16,5,1,1,3,81,39,7,2,31,31,0,
	1,1,3,73,39,7,2,31,31,0,1,1,3,65,39,7,2,31,31,0,
	1,1,3,57,39,7,2,31,31,0,1,1,3,49,39,7,2,31,31,0,
	1,1,3,41,39,7,2,31,31,0,1,1,3,33,39,7,2,31,31,0,
	1,1,3,25,39,7,2,31,31,0,1,1,3,17,57,7,2,31,31,0,
	67,4,3,81,40,7,2,2,26,16,67,4,3,73,40,7,2,2,26,16,
	67,4,3,65,40,7,2,2,26,16,67,4,3,57,40,7,2,2,26,16,
	67,4,3,49,40,7,2,2,26,16,67,4,3,41,40,7,2,2,26,16,
	67,4,3,33,40,7,2,2,26,16,67,4,3,25,40,7,2,2,26,16,
	67,4,3,17,58,7,2,2,26,16,5,32,3,43,55,55,1,39,54,31,
	4,128,2,32,65,11,1,5,26,129,0,21,29,23,4,1,8,66,108,97,
	100,101,32,83,112,101,101,100,0,131,1,1,1,38,6,1,2,31,82,101,
	109,111,116,101,32,67,111,110,116,114,111,108,0,131,0,40,1,20,7,2,
	2,31,77,101,110,117,115,0,1,2,2,90,32,8,2,2,31,67,97,110,
	99,101,108,32,47,32,66,97,99,107,0,1,2,37,90,23,8,2,2,31,
	83,97,118,101,0,7,22,45,25,16,7,2,2,26,2,7,22,45,33,16,
	7,2,2,26,2,7,22,45,41,16,7,2,2,26,2,7,22,45,49,16,
	7,2,2,26,2,7,22,45,57,16,7,2,2,26,2,7,22,45,81,16,
	7,2,2,26,2,7,22,45,73,16,7,2,2,26,2,7,22,45,65,16,
	7,2,2,26,2,2,0,35,18,27,8,1,2,26,31,31,79,78,0,79,
	70,70,0,2,0,3,18,27,8,1,2,26,31,31,79,78,0,79,70,70,
	0,129,0,36,13,26,4,1,8,77,111,116,111,114,115,32,82,101,108,97,
	121,0,129,0,1,14,32,4,1,8,82,101,109,111,116,101,32,67,111,110,
	116,114,111,108,0,129,0,9,10,15,4,1,8,65,99,116,105,118,97,116,
	101,0,2,1,36,9,26,7,2,2,26,31,31,79,78,0,79,70,70,0,
	129,0,1,10,34,4,2,8,65,99,116,105,118,97,116,101,32,77,101,110,
117,115,32,45,62,0 };

// this structure defines all the variables and events of your control interface 
struct {
	
    // input variables
	uint8_t Menu_button_8; // =1 if button pressed, else =0 
	uint8_t Menu_button_7; // =1 if button pressed, else =0 
	uint8_t Menu_button_6; // =1 if button pressed, else =0 
	uint8_t Menu_button_5; // =1 if button pressed, else =0 
	uint8_t Menu_button_4; // =1 if button pressed, else =0 
	uint8_t Menu_button_3; // =1 if button pressed, else =0 
	uint8_t Menu_button_2; // =1 if button pressed, else =0 
	uint8_t Menu_button_1; // =1 if button pressed, else =0 
	uint8_t Menu_button; // =1 if button pressed, else =0 
	int8_t joystick_1_x; // from -100 to 100  
	int8_t joystick_1_y; // from -100 to 100  
	int8_t Blade_Speed; // =0..100 slider position 
	uint8_t Cancel_Back_button; // =1 if button pressed, else =0 
	uint8_t Save_button; // =1 if button pressed, else =0 
	int16_t Menu_value_1;  // 32767.. +32767 
	int16_t Menu_value_2;  // 32767.. +32767 
	int16_t Menu_value_3;  // 32767.. +32767 
	int16_t Menu_value_4;  // 32767.. +32767 
	int16_t Menu_value_5;  // 32767.. +32767 
	int16_t Menu_value_8;  // 32767.. +32767 
	int16_t Menu_value_7;  // 32767.. +32767 
	int16_t Menu_value_6;  // 32767.. +32767 
	uint8_t Motor_Relay_switch; // =1 if switch ON and =0 if OFF 
	uint8_t Activate_Remote_Control_switch; // =1 if switch ON and =0 if OFF 
	uint8_t Activate_Menus_switch; // =1 if switch ON and =0 if OFF 
	
    // output variables
	char Menu_text_8[16];  // string UTF8 end zero 
	char Menu_text_7[16];  // string UTF8 end zero 
	char Menu_text_6[16];  // string UTF8 end zero 
	char Menu_text_5[16];  // string UTF8 end zero 
	char Menu_text_4[16];  // string UTF8 end zero 
	char Menu_text_3[16];  // string UTF8 end zero 
	char Menu_text_2[16];  // string UTF8 end zero 
	char Menu_text_1[16];  // string UTF8 end zero 
	char Menu_text[16];  // string UTF8 end zero 
	
    // other variable
	uint8_t connect_flag;  // =1 if wire connected, else =0 
	//uint8_t RemoteXY_isConnected ()
	uint8_t menu_level = 0;
	uint8_t main_menu_all_ready_displayed = 0;
	uint8_t Quick_Go_Menu_all_ready_displayed =0;
	
	
} RemoteXY;
#pragma pack(pop)


/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////

/* defined the right motor control pins */
#define PIN_MOTOR_RIGHT_UP 23
#define PIN_MOTOR_RIGHT_DN 22
#define PIN_MOTOR_RIGHT_SPEED 7

/* defined the left motor control pins */
#define PIN_MOTOR_LEFT_UP 25
#define PIN_MOTOR_LEFT_DN 26
#define PIN_MOTOR_LEFT_SPEED 6

/* defined the Relay pin */
#define RELAY 26

// defined the Mow Motors pins 
#define PIN_MOW_MOTOR_RIGHT_UP 27
#define PIN_MOW_MOTOR_RIGHT_DN 28
#define PIN_MOW_MOTOR_RIGHT_SPEED 8
// defined the Center Mow Motors pins
//#define PIN_MOW_MOTOR_CENTER_UP 44
//#define PIN_MOW_MOTOR_CENTER_DN 45
//#define PIN_MOW_MOTOR_CENTER_SPEED 7
// defined the Left Mow Motors pins
//#define PIN_MOW_MOTOR_LEFT_UP 46
//#define PIN_MOW_MOTOR_LEFT_DN 47
//#define PIN_MOW_MOTOR_LEFT_SPEED 8


int Status = 0;
int Old_Status = 0;
int Relay_Status = 0;
int Old_Relay_Status = 0;
int Mow_Motor_Speed = 0;
int Old_Mow_Motor_Speed = 0;
int while_Remote_Control_loop_active = 0;
int Button_Press = 0;
int Current_Menu = 0;

/*const char *menu0[9] = {
	"Main Menu", "Sub Menu 1", "Sub Menu 2", 
	"Sub Menu 3", "Sub Menu 4", "Sub Menu 5",
	"Sub Menu 6", "Sub Menu 7", "Sub Menu 8"
}
	/*const char *menu1[9] = {
	"Sub Menu 1", "Sub Menu 1.1", "Sub Menu 1.2", 
	"Sub Menu 1.3", "Sub Menu 1.4", "Sub Menu 1.5",
	"Sub Menu 1.6", "Sub Menu 1.7", "Sub Menu 1.8"
	};
	const char *menu2[9] = {
	"Sub Menu 2", "Sub Menu 2.1", "Sub Menu 2.2", 
	"Sub Menu 2.3", "Sub Menu 2.4", "Sub Menu 2.5",
	"Sub Menu 2.6", "Sub Menu 2.7", "Sub Menu 2.8"
	};
	const char *menu3[9] = {
	"Sub Menu 3", "Sub Menu 3.1", "Sub Menu 3.2", 
	"Sub Menu 3.3", "Sub Menu 3.4", "Sub Menu 3.5",
	"Sub Menu 3.6", "Sub Menu 3.7", "Sub Menu 3.8"
	};
	const char *menu4[9] = {
	"Sub Menu 4", "Sub Menu 4.1", "Sub Menu 4.2", 
	"Sub Menu 4.3", "Sub Menu 4.4", "Sub Menu 4.5",
	"Sub Menu 4.6", "Sub Menu 4.7", "Sub Menu 4.8"
	};
	const char *menu5[9] = {
	"Sub Menu 5", "Sub Menu 5.1", "Sub Menu 5.2", 
	"Sub Menu 5.3", "Sub Menu 5.4", "Sub Menu 5.5",
	"Sub Menu 5.6", "Sub Menu 5.7", "Sub Menu 5.8"
	};
	const char *menu6[9] = {
	"Sub Menu 6", "Sub Menu 6.1", "Sub Menu 6.2", 
	"Sub Menu 6.3", "Sub Menu 6.4", "Sub Menu 6.5",
	"Sub Menu 6.6", "Sub Menu 6.7", "Sub Menu 6.8"
	};
	const char *menu7[9] = {
	"Sub Menu 7", "Sub Menu 7.1", "Sub Menu 7.2", 
	"Sub Menu 7.3", "Sub Menu 7.4", "Sub Menu 7.5",
	"Sub Menu 7.6", "Sub Menu 7.7", "Sub Menu 7.8"
	};
	const char *menu8[9] = {
	"Sub Menu 8", "Sub Menu 8.1", "Sub Menu 8.2", 
	"Sub Menu 8.3", "Sub Menu 8.4", "Sub Menu 8.5",
	"Sub Menu 8.6", "Sub Menu 8.7", "Sub Menu 8.8"
	};
	const char *menu1_1[9] = {
	"Sub Menu 1.1", "Setting 1.1.1", "Setting 1.1.2", 
	"Setting 1.1.3", "Setting 1.1.4", "Setting 1.1.5",
	"Setting 1.1.6", "Setting 1.1.7", "Setting 1.1.8"
	};
	const char *menu1_2[9] = {
	"Sub Menu 1.2", "Setting 1.1.1", "Setting 1.1.2", 
	"Setting 1.1.3", "Setting 1.1.4", "Setting 1.1.5",
	"Setting 1.1.6", "Setting 1.1.7", "Setting 1.1.8"
	};
*/
/* defined two arrays with a list of pins for each motor */
unsigned char RightMotor[3] =
{PIN_MOTOR_RIGHT_UP, PIN_MOTOR_RIGHT_DN, PIN_MOTOR_RIGHT_SPEED};
unsigned char LeftMotor[3] =
{PIN_MOTOR_LEFT_UP, PIN_MOTOR_LEFT_DN, PIN_MOTOR_LEFT_SPEED};
