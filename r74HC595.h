#ifndef _r74HC595_h_
#define _r74HC595_h_

#include <Arduino.h>

class r74HC595{
	public:
		r74HC595(int DS,int ST_CP,int SH_CP,int count);
		void autoWrite(int id,bool val);
		void write(int id,bool val);
		void send();
		void setup();
		unsigned char* data;
	private:
		int count,dataPin,clockPin,latchPin;
};

#endif
