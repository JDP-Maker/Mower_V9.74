void Update_Blynk_App_With_Status() {
        
	if ((Mower_Docked_Filter == 2) ||  (Mower_Running_Filter == 2) ||  (Manuel_Mode == 1) || (Mower_Parked == 1)  )   {
		//App Buttons
		if (V10_Last) Blynk.virtualWrite(V10,LOW);       // Exit Dock Button
		if (V0_Last) Blynk.virtualWrite(V0, LOW);       // Quick Start Button
		if (V2_Last) Blynk.virtualWrite(V2, LOW);       // Pause/Stop Button
		if (V1_Last) Blynk.virtualWrite(V1, LOW);       // Go To Dock Button
           
		if (Manuel_Mode == 1)   {
			ParkedLED.off();               //V6
			MowingLED.off();               //V7
			DockedLED.off();               //V8
			TrackingLED.off();             //V9
		}
	}
        
        
        //delay(100);
	if (Charge_Detected != Charge_Detected_Last) {
		if (Charge_Detected == 4)          ChargingLED.on();
		if (Charge_Detected == 0)          ChargingLED.off();
		Charge_Detected_Last = Charge_Detected;
	}
	if (Tracking_Wire != Tracking_Wire_Last) {
		if (Tracking_Wire == 1)            TrackingLED.on();
		if (Tracking_Wire == 0)            TrackingLED.off();
		Tracking_Wire_Last = Tracking_Wire;
	}
	if (Mower_Parked != Mower_Parked_Last) {
		if (Mower_Parked == 1)             ParkedLED.on();
		if (Mower_Parked == 0)             ParkedLED.off();
		Mower_Parked_Last = Mower_Parked;
	}
	if (Mower_Running_Filter != Mower_Running_Filter_Last) {
		if (Mower_Running_Filter == 2)     MowingLED.on();
		if (Mower_Running_Filter != 2)     MowingLED.off();
		Mower_Running_Filter_Last = Mower_Running_Filter;
	}
	if (Mower_Docked_Filter != Mower_Docked_Filter_Last) {
		if (Mower_Docked_Filter == 2)      DockedLED.on();
		if (Mower_Docked_Filter != 2)      DockedLED.off();
		Mower_Docked_Filter_Last = Mower_Docked_Filter;
	}
        //SerialDebug.print(" *");

        //delay(100);
}


void Update_Blynk_App_With_Status_2() {

     
        /*
        
        // Settings Tab
        if (Compass_Activate == 1) Blynk.virtualWrite(V20, 1);  
        if (Compass_Activate == 0) Blynk.virtualWrite(V20, 2);
          
        if (Compass_Heading_Hold_Enabled == 1) Blynk.virtualWrite(V21, 1);  
        if (Compass_Heading_Hold_Enabled == 0) Blynk.virtualWrite(V21, 2);
          
        if (GYRO_Enabled == 1) Blynk.virtualWrite(V22, 1);  
        if (GYRO_Enabled == 0) Blynk.virtualWrite(V22, 2);

        if (Sonar_1_Activate == 1) Blynk.virtualWrite(V24, 1);  
        if (Sonar_1_Activate == 0) Blynk.virtualWrite(V24, 2);
        if (Sonar_2_Activate == 1) Blynk.virtualWrite(V25, 1);  
        if (Sonar_2_Activate == 0) Blynk.virtualWrite(V25, 2);
        if (Sonar_3_Activate == 1) Blynk.virtualWrite(V26, 1);  
        if (Sonar_3_Activate == 0) Blynk.virtualWrite(V26, 2); 
        
        if (Bumper_Activate_Frnt == 1) Blynk.virtualWrite(V29, 1);  
        if (Bumper_Activate_Frnt == 0) Blynk.virtualWrite(V29, 2); 

        if (Alarm_1_ON == 1) Blynk.virtualWrite(V30, 1);  
        if (Alarm_1_ON == 0) Blynk.virtualWrite(V30, 2);
        if (Alarm_2_ON == 1) Blynk.virtualWrite(V31, 1);  
        if (Alarm_2_ON == 0) Blynk.virtualWrite(V31, 2);
        if (Alarm_3_ON == 1) Blynk.virtualWrite(V32, 1);  
        if (Alarm_3_ON == 0) Blynk.virtualWrite(V32, 2);
        if (GPS_Enabled == 1) Blynk.virtualWrite(V33, 1);  
        if (GPS_Enabled == 0) Blynk.virtualWrite(V33, 2);
        if (Angle_Sensor_Enabled == 1) Blynk.virtualWrite(V34, 1);  
        if (Angle_Sensor_Enabled == 0) Blynk.virtualWrite(V34, 2);
        if (Tip_Over_Sensor_Enabled == 1) Blynk.virtualWrite(V35, 1);  
        if (Tip_Over_Sensor_Enabled == 0) Blynk.virtualWrite(V35, 2);
        if (Wheel_Amp_Sensor_ON == 1) Blynk.virtualWrite(V36, 1);  
        if (Wheel_Amp_Sensor_ON == 0) Blynk.virtualWrite(V36, 2);

        */

       
        }





void Clear_APP() {
  Blynk.virtualWrite(V0, LOW);   // Start Mowing Buton OFF
  Blynk.virtualWrite(V1, LOW);  // Go-Home Button OFF
  Blynk.virtualWrite(V2, LOW);  // Stop Button OFF
  Blynk.virtualWrite(V3, LOW);    // Reset Voltage
  Blynk.virtualWrite(V4, 1);  	// Mowign Mode Seg Switch
  Blynk.virtualWrite(V5, LOW);    // Loops
  ParkedLED.off();  	// V6
  MowingLED.off();		// V7
  DockedLED.off();		// V8
  TrackingLED.off();	// V9
  Blynk.virtualWrite(V10, LOW); // Dock Button OFF
  ErrorLED.off();		// V11
  ChargingLED.off(); 	// V12

  //ParkedLED.setValue(255);
  //MowingLED.setValue(255);
  //DockedLED.setValue(255);
  //TrackingLED.setValue(255);
  //ChargingLED.setValue(255);
}
