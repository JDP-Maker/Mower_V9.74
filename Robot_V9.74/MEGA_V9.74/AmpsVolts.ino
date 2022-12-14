// The voltage is transfered to the MEGA from the Nano via the serial com.
// The vlaues from the Nano are the raw sensor values.
// The Amps and volts are then calculated via equations


void Process_Volt_Information()   {
//  Logic for how the battery readings should be handled
    
    if (Volts < Battery_Min) {
      Low_Battery_Detected = (Low_Battery_Detected + 1);
      Serial.print(F("VLow:"));
      Serial.print(Low_Battery_Detected);
      Serial.print(F("|"));
      if (Low_Battery_Detected > Low_Battery_Instances_Chg) {
         Serial.println(F(""));
         Serial.println(F("Low Battery Detected"));
         if (Use_Charging_Station == 1) {
          // need to add a low batt code... to TFT
          Manouver_Go_To_Charging_Station();                       // Stops the mowing and sends the mower back to the charging station via the permieter wire
          }
         if (Use_Charging_Station == 0) Manouver_Park_The_Mower_Low_Batt();                      // Parks the mower with a low battery warning
         }
      }

    if (Volts >= Battery_Min) {
      Serial.print(F("VLow:"));
      Serial.print(Low_Battery_Detected);
      Serial.print(F("|"));
      Low_Battery_Detected = 0;
      }
}



// checks to see if the mower is on the charging station
void Check_if_Charging() {


    if (Charging == 4)  {                            // If the value recieved is equal to 1 or 0 as expected then print the value to the serial monitor
        Serial.print(F("Charging:"));
        Serial.print(Charging);
        Serial.print(F("|"));
        Charge_Detected_MEGA = 1;
        Print_Charging_LCD();
        Serial.print(F("MEGA = 1|"));
        }
    if (Charging == 0)  {                            // If the value recieved is equal to 1 or 0 as expected then print the value to the serial monitor
        Serial.print(F("Charging:"));
        Serial.print(Charging);
        Serial.print(F("|"));
        Charge_Detected_MEGA = 0;
        Print_Charging_LCD();
        }
      if ((Charging != 4) && (Charging !=0)) {
        Serial.print(F("Charging:"));
        Serial.print(Charging);
        Serial.print(F("|"));
        Charge_Detected_MEGA = 0;
        Print_Charging_LCD();
        }

}



void Check_if_Docked() {
  
  if (Charge_Detected_MEGA == 1) {                                    // if Amps are between this there is a charge detected.  Amps above 4 are discounted as a miscommunication
        Motor_Action_Stop_Motors();    
        Serial.println(F(""));
        Serial.println(F("Charging Current detected"));
        Serial.println(F(""));
        Serial.println(F("----------------"));
        Serial.println(F("| Mower Docked |"));
        Serial.println(F("----------------"));
        Serial.println(F(""));
        
        #if defined(LCD_KEYPAD)
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print(F("Docked in"));
        lcd.setCursor(0, 1);
        lcd.print(F("Charging Station"));                                // Prints info to LCD display 
        #endif
        
        delay(2000);
        Mower_Docked = 1;
        // Update the TFT Screen
        if (TFT_Screen_Menu == 1) {
            //Send_Mower_Docking_Data();
            Turn_To_Home = 0;
            Find_Wire_Track = 0;
            Go_To_Charging_Station = 0;
            }
        Manouver_Dock_The_Mower();                                    // Shuts down the Mower ready for charging and mowing again.
        
        #if defined(LCD_KEYPAD)
        lcd.clear();
        #endif
        
        }
   Serial.println(F(""));
  }
        
void Calculate_Volt_Amp_Charge() {

if (Show_TX_Data == 1) {
      Serial.print(F("Amp:"));
      Serial.print(RawValueAmp);
      Serial.print(F("|"));
      Serial.print(F("Volt:"));
      Serial.print(RawValueVolt);
      Serial.print(F("|"));
      Serial.print(F("Rain:"));
      Serial.print(Rain_Detected);
      Serial.print(F("|"));
      if (Wheel_Amp_Sensor_ON == 1) {
          Serial.print(F("WBlock:"));
          Serial.print(Wheel_Blocked);
          Serial.print(F("|"));
          }
      }

// Calculate Amps from NANO RX Data
 int mVperAmp = 185;
 int ACSoffset = 2500; 
 double VoltageAmp = 0;
 double Amps_Now = 0;
 VoltageAmp = (RawValueAmp / 1024.0) * 5000; // Gets you mV
 Amps_Now =  ((VoltageAmp - ACSoffset) / mVperAmp);
 Amps = Amps_Now;
 
 Serial.print(F("A:"));    
 Serial.print(Amps);
 Serial.print(F("|"));


// Calculate Voltage from NANO RX Data

 if (RawValueVolt > 100)  {
 float vout = 0.0;
 float R1 = 30000;                                   
 
// Set R2 vaklue in mower settings (usually between 6000 and 7500)
 float R2 = Volts_R2_Value;         
 
 vout = (RawValueVolt * 5.0) / 1024.0; // see text
 Volts = vout / (R2/(R1+R2));

 // can be enbaled from the serial command for testing only
 
 
 Volts_Last = Volts;
 Zero_Volts = 0;
 }

 else {
 Volts = Volts_Last;
 Zero_Volts = Zero_Volts + 1;
 if (Zero_Volts > 5) Volts = 0;
 
 }

 if (Fake_All_Settings == 1) Execute_Fake_It();

 Serial.print(F("V:"));    
 Serial.print(Volts);
 Serial.print(F("|"));

 if (Amps < Amps_Charging_Setting) Charging = 0;
 if (Amps >= Amps_Charging_Setting) Charging = 4;
 //Serial.print("Charging = ");  
 //Serial.print(Charging);
 //Serial.print("|");

}
