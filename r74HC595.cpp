#include "r74HC595.h"
void r74HC595::setup(){
	pinMode(latchPin, OUTPUT);
	pinMode(clockPin, OUTPUT);
	pinMode(dataPin, OUTPUT);
}
r74HC595::r74HC595(int DS,int ST_CP,int SH_CP,int count){
	dataPin=DS;
	clockPin=SH_CP;
	latchPin=ST_CP;
	this->count=count;
	data=new unsigned char[count];
}
void r74HC595::autoWrite(int id,bool val){
	write(id,val);
	send();
}
void r74HC595::write(int id,bool val){
	if(val)
		data[id/8]|=1<<(id%8);
	else
		data[id/8]&=0<<(id%8);
}
void r74HC595::send(){
	digitalWrite(latchPin, LOW);
	for(int i=0;i<count;i++)
		  shiftOut(dataPin, clockPin, MSBFIRST, data[i]);
	digitalWrite(latchPin, HIGH);
}