/***********************************
	Author: 	Raghul
	Date:		26/09/2019
	Time:		11:59 PM
	Version:	0.1
***********************************/

#include "CircularBuffer.h"

CircularBuffer::CircularBuffer(const uint32_t length){
	initialized=false;
	if(length<1) return;
	Buffer=(uint8_t *)malloc(length);
	if(Buffer==NULL) return;	
	flushPacket(length);
	Length=length;
	initialized=true;
}

CircularBuffer::~CircularBuffer(void){
	flushPacket(Length);
	free(Buffer);
	Buffer=NULL;
	initialized=false;
}

void CircularBuffer::flushPacket(const uint32_t length){
	for(uint32_t i=0;i<length;i++){
		Buffer[i]=0;
	}
	Length=0;
	Head=0;
	Tail=0;
	bufferFull=false;
}

bool CircularBuffer::write(const uint8_t data){
	if(!initialized || bufferFull) return false;
	Buffer[Head++]=data;
	if(Head==Length) Head=0;
	if(Head==Tail) bufferFull=true;
}

bool CircularBuffer::write(const uint8_t *data, uint32_t length){
	if((getSize()<=length) || !initialized)	return false;
	for(uint32_t i=0;i<length;i++){
		write(data[i]);
	}
}

const uint8_t CircularBuffer::read(void){
	uint32_t data;
	if(!initialized || (Head==Tail && !bufferFull)) return 0;
	data=Buffer[Tail++];
	if(Tail==Length) Tail=0;
	bufferFull=false;
	return data;
}

bool CircularBuffer::remove(const uint32_t length){
	if((getSize()<=length) || !initialized)	return false;
	for(uint32_t i=0;i<length;i++){
		read();
	}
	return true;
}

const uint32_t CircularBuffer::getSize(void){
	if(!initialized)	return 0;
	if(Head>Tail){
		return (Length-Head)+Tail;
	}
	else if(Head<Tail){
		return (Tail-Head);
	}
	else {
		if(!bufferFull)	return Length;
		else return 0;
	}
}

