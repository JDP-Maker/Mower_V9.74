void Read_Serial1_Nano() {
	#if defined(PIXHAWK)		// PIXHAWK
		if (Mower_PIXHAWK == 0) {
			
			byte recvBuff [10] = {0};
			
			if (SerialCom1.update ())
			{
				byte length = SerialCom1.getLength ();
				if (length > sizeof (recvBuff)) length = sizeof (recvBuff);
				memcpy (&recvBuff, SerialCom1.getData (), length);
				
				RawValueAmp =   recvBuff[0] | recvBuff[1] << 8;
				RawValueVolt =  recvBuff[2] | recvBuff[3] << 8;
				Rain_Detected = recvBuff[4] | recvBuff[5] << 8;
				RawWheelAmp =   recvBuff[6] | recvBuff[7] << 8;
				RawDrillAmp =   recvBuff[8] | recvBuff[9] << 8;
			}  // end if something received
			
			//Serial.print(F("WAmpRaw: "));
			//Serial.print(F(RawWheelAmp));
			//Serial.print(F(" |"));
			
			//Serial.print(F("DAMpRaw: "));
			//Serial.print(F(RawDrillAmp));
			//Serial.print(F(" |"));
			
			Calculate_Volt_Amp_Charge();
			
		}
	#endif
}

