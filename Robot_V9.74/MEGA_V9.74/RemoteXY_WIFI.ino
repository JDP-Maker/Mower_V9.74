/*   RemoteXY_WIFI.ino
	
	
	
*/
void Setup_RemoteXY () {
	/* initialization module RemoteXY */
	Serial.println(F("Setup RemoteXY before setup"));
  RemoteXY_Init ();
	Serial.println(F("Setup RemoteXY after setup"));
}

/*	speed control of the motor
	motor - pointer to an array of pins
	v - motor speed can be set from -100 to 100
*/
void Wheel (unsigned char * motor, int v){
	if (v > 100) v = 100;
	if (v < -100) v = -100;
	if (v > 0) {
		digitalWrite(motor[0], HIGH);
		digitalWrite(motor[1], LOW);
		analogWrite(motor[2], v * 2.55);
	}
	else if (v < 0) {
		digitalWrite(motor[0], LOW);
		digitalWrite(motor[1], HIGH);
		analogWrite(motor[2], (-v) * 2.55);
	}
	else {
		digitalWrite(motor[0], LOW);
		digitalWrite(motor[1], LOW);
		analogWrite(motor[2], 0);
	}
}

void Spin_mow_motors_right () {
	digitalWrite(PIN_MOW_MOTOR_RIGHT_UP, HIGH);
	digitalWrite(PIN_MOW_MOTOR_RIGHT_DN, LOW);
	//digitalWrite(PIN_MOW_MOTOR_CENTER_UP, HIGH);
	//digitalWrite(PIN_MOW_MOTOR_CENTER_DN, LOW);
	//digitalWrite(PIN_MOW_MOTOR_LEFT_UP, HIGH);
	//digitalWrite(PIN_MOW_MOTOR_LEFT_DN, LOW);
}

void Spin_mow_motors_left () {
	digitalWrite(PIN_MOW_MOTOR_RIGHT_UP, LOW);
	digitalWrite(PIN_MOW_MOTOR_RIGHT_DN, HIGH);
	//digitalWrite(PIN_MOW_MOTOR_CENTER_UP, LOW);
	//digitalWrite(PIN_MOW_MOTOR_CENTER_DN, HIGH);
	//digitalWrite(PIN_MOW_MOTOR_LEFT_UP, LOW);
	//digitalWrite(PIN_MOW_MOTOR_LEFT_DN, HIGH);
}

void Main_RemoteXY_Loop () 
{
	//*event handler module RemoteXY
	RemoteXY_Handler ();
	// test all remotexy variables for debug
	Serial.print( "|connect_flag = ");
	Serial.print( RemoteXY.connect_flag);
	Serial.print( "|Blade_Speed = ");
	Serial.print( RemoteXY.Blade_Speed);
	Serial.print( "|Menus_switch = ");
	Serial.print( RemoteXY.Activate_Menus_switch);
	Serial.print( "|Remote_Control = ");
	Serial.print( RemoteXY.Activate_Remote_Control_switch); 
	Serial.print( "|Relay_switch = ");
	Serial.println( RemoteXY.Motor_Relay_switch); 
	Serial.print( "|Save_button = ");
	Serial.print( RemoteXY.Save_button); 
	Serial.print( "|Cancel_Back = ");
	Serial.print( RemoteXY.Cancel_Back_button); 
	Serial.print( "|joystick_1_y = ");
	Serial.print( RemoteXY.joystick_1_y);
	Serial.print( "|joystick_1_x = ");
	Serial.print( RemoteXY.joystick_1_x);
	Serial.print( "|Menu_button_1 = ");
	Serial.println( RemoteXY.Menu_button_1); 
	
	////Serial.print(F("RemoteXY section"));
	
	Status = RemoteXY.connect_flag;
	// if curent status is 0 and old_status is 1 then the connection just dropped and we need to stop all
	Serial.print ( "Status section " );
	Serial.print ( "|Status = " );
	Serial.print ( Status );
	Serial.print ( "|Old_Status = " );
	Serial.println ( Old_Status );
	
	if ((Status == 0) && (Old_Status == 1)) 
	{
		Old_Status = Status;
		Serial.println( "Disconected" );
		lcd.clear();
		lcd.print("Connection lost");
		lcd.setCursor(0,1);
		lcd.print("SHUT OFF ALL MOTORS");
		//turn motors off after Disconect
		digitalWrite (RELAY, LOW);
		return; 
	}
	else if ( Status == 1 )
	{
		Serial.println( "Connected 1" );
		lcd.clear();
		lcd.print("Connected");
		Old_Status = Status;
	}
	else 
	{
		Old_Status = Status;
		return;
	}
	
	// check the Relay status
	// only update if changed (don't need relay updating every loop)
	Relay_Status = RemoteXY.Motor_Relay_switch;
	Serial.print ("|Relay_Status section|");		
	Serial.print ("|Relay_Status  = ");
	Serial.print (Relay_Status);
	Serial.print ("|oldRelay_Status = ");
	Serial.println (Old_Relay_Status);
	if (Relay_Status != Old_Relay_Status) {
		lcd.clear();
		lcd.print("Relay_Status = ");
		lcd.print(Relay_Status);
		Old_Relay_Status = Relay_Status;
		digitalWrite (RELAY, (Relay_Status == 0) ? LOW : HIGH);
	}
	//else Serial.println ("relay new = old - do nothing");  // since no change do nothing with relay
	
	
	// Mow Motor control - only update when there is a change
	// All Motors go the same speed
	Mow_Motor_Speed = (RemoteXY.Blade_Speed * 2.55);
	Spin_mow_motors_right ();
	Serial.println ("|Mow motor section |");
	if (Mow_Motor_Speed != Old_Mow_Motor_Speed) {
		Serial.print ("new Mow Motor Speed = ");
		Serial.println (Mow_Motor_Speed);
		lcd.setCursor(0,1);
		lcd.print("Blade Speed = ");
		lcd.print(Mow_Motor_Speed);
		lcd.print ("   ");   
		Old_Mow_Motor_Speed = Mow_Motor_Speed;
		analogWrite(PIN_MOW_MOTOR_RIGHT_SPEED, Mow_Motor_Speed);
		//analogWrite(PIN_MOW_MOTOR_CENTER_SPEED, Mow_Motor_Speed);
		//analogWrite(PIN_MOW_MOTOR_LEFT_SPEED, Mow_Motor_Speed);
	}
	
	
	// manage the right Wheel motor 
	Wheel (RightMotor, RemoteXY.joystick_1_y - RemoteXY.joystick_1_x);
	// manage the left Wheel motor
	Wheel (LeftMotor, RemoteXY.joystick_1_y + RemoteXY.joystick_1_x);
	
	
	if ( RemoteXY.Activate_Menus_switch == 1) {
		if (RemoteXY.menu_level ==0) {
			if(RemoteXY.main_menu_all_ready_displayed ==0) Display_Main_Menu (); //don't need to keep updating menu text
			Main_menu_button_press ();
		}
		else if (RemoteXY.menu_level ==11) {
			if(RemoteXY.Quick_Go_Menu_all_ready_displayed ==0) Display_Quick_Go_Menu (); //don't need to keep updating menu text
			Quick_Go_menu_button_press ();
		}
	}	
}		
void Display_Main_Menu () {
	RemoteXY.menu_level = 0;
	RemoteXY.main_menu_all_ready_displayed = 1;
	//Serial.println ("| display menu ");
	sprintf (RemoteXY.Menu_text, "Top level Menu");
	sprintf (RemoteXY.Menu_text_1, "Quick Go");
	sprintf (RemoteXY.Menu_text_2, "Exit Dock"); 
	sprintf (RemoteXY.Menu_text_3, "Setup");    
	sprintf (RemoteXY.Menu_text_4, "blank4");  
	sprintf (RemoteXY.Menu_text_5, "blank5");   
	sprintf (RemoteXY.Menu_text_6, "blank6");    
	sprintf (RemoteXY.Menu_text_7, "blank7");   
	sprintf (RemoteXY.Menu_text_8, "blank8"); 
}	

void Main_menu_button_press () {
	if (RemoteXY.Menu_button_1 == 1) {
		sprintf (RemoteXY.Menu_text, "Quick Go");	//flashs text to top menu field
		Display_Quick_Go_Menu ();
	}
	else if (RemoteXY.Menu_button_2 == 1) {
	sprintf (RemoteXY.Menu_text, "Exit Dock");	//flashs text to top menu field
	}
	else if (RemoteXY.Menu_button_3 == 1) {
	sprintf (RemoteXY.Menu_text, "Setup");		//flashs text to top menu field
	}
	else if (RemoteXY.Menu_button_4 == 1) sprintf (RemoteXY.Menu_text, "Button press 4");
	else if (RemoteXY.Menu_button_5 == 1) sprintf (RemoteXY.Menu_text, "Button press 5");
	else if (RemoteXY.Menu_button_6 == 1) sprintf (RemoteXY.Menu_text, "Button press 6");
	else if (RemoteXY.Menu_button_7 == 1) sprintf (RemoteXY.Menu_text, "Button press 7");
	else if 	(RemoteXY.Menu_button_8 == 1) sprintf (RemoteXY.Menu_text, "Button press 8");
	}
	
	
	
	
	void Display_Quick_Go_Menu () {
	RemoteXY.menu_level = 11;
	//Serial.println ("| display menu ");
	sprintf (RemoteXY.Menu_text, "Quick Go Menu");
	sprintf (RemoteXY.Menu_text_1, "Just Go");
	sprintf (RemoteXY.Menu_text_2, "1hr Mow"); 
	sprintf (RemoteXY.Menu_text_3, "2hr Mow");    
	sprintf (RemoteXY.Menu_text_4, "Max Mow");  
	sprintf (RemoteXY.Menu_text_5, "blank5");   
	sprintf (RemoteXY.Menu_text_6, "blank6");    
	sprintf (RemoteXY.Menu_text_7, "blank7");   
	sprintf (RemoteXY.Menu_text_8, "blank8"); 
	}
	
	void Quick_Go_menu_button_press () {
	if (RemoteXY.Menu_button_1 == 1) {
	sprintf (RemoteXY.Menu_text, "Just Go");	//flashs text to top menu field
	//some code to do
	}
	else if (RemoteXY.Menu_button_2 == 1) {
	sprintf (RemoteXY.Menu_text, "1hr Mow");	//flashs text to top menu field
	//some code to do
    }
	else if (RemoteXY.Menu_button_3 == 1) {
	sprintf (RemoteXY.Menu_text, "2hr Mow");	//flashs text to top menu field
	//some code to do
	}
	else if (RemoteXY.Menu_button_4 == 1) {
	sprintf (RemoteXY.Menu_text, "Max Mow");		//flashs text to top menu field
	//some code to do
	}
	else if (RemoteXY.Menu_button_5 == 1) sprintf (RemoteXY.Menu_text, "Button press 5");
	else if (RemoteXY.Menu_button_6 == 1) sprintf (RemoteXY.Menu_text, "Button press 6");
	else if (RemoteXY.Menu_button_7 == 1) sprintf (RemoteXY.Menu_text, "Button press 7");
	else if (RemoteXY.Menu_button_8 == 1) sprintf (RemoteXY.Menu_text, "Button press 8");
	}
	/*	sprintf (RemoteXY.Menu_text, menu_text[0]);      char *menu_text[]
	sprintf (RemoteXY.Menu_text_1, menu_text[1]);
	sprintf (RemoteXY.Menu_text_2, menu_text[2]); 
	sprintf (RemoteXY.Menu_text_3, menu_text[3]);    
	sprintf (RemoteXY.Menu_text_4, menu_text[4]);  
	sprintf (RemoteXY.Menu_text_5, menu_text[5]);   
	sprintf (RemoteXY.Menu_text_6, menu_text[6]);    
	sprintf (RemoteXY.Menu_text_7, menu_text[7]);   
	sprintf (RemoteXY.Menu_text_8, menu_text[8]); 
	end comments
	}	
	
	void Wait_For_Button_Press () {
	Button_Press = 0;
	while (Button_Press == 0) {
	RemoteXY_Handler ();
	if (RemoteXY.Menu_button_1 == 1) Button_Press = 1;
	if (RemoteXY.Menu_button_2 == 1) Button_Press = 2;
	if (RemoteXY.Menu_button_3 == 1) Button_Press = 3;
	if (RemoteXY.Menu_button_4 == 1) Button_Press = 4;
	if (RemoteXY.Menu_button_5 == 1) Button_Press = 5;
	if (RemoteXY.Menu_button_6 == 1) Button_Press = 6;
	if (RemoteXY.Menu_button_7 == 1) Button_Press = 7;
	if (RemoteXY.Menu_button_8 == 1) Button_Press = 8;
	if (RemoteXY.Cancel_Back_button == 1) Button_Press = -1;
	//Serial.print ( "| Button_Press = ");
	//Serial.println ( Button_Press);
	//Serial.print ( "| Menu Value 1 = ");
	//Serial.println ( RemoteXY.Menu_value_1 );
	}
	}	
	*/
		