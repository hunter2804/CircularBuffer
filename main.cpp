#include "CircularBuffer.h"

#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

uint8_t data;

CircularBuffer buffer(10);

int main(void){
	while(1){
		std::cin>>&data;
		if(data == 'B')	goto exit;
		else if(data=='R'){
			std::cout<<buffer.read()<<std::endl;
			printf("balance size: %d\r\n",buffer.getSize());
			continue;
		}
		buffer.write(data);
		printf("balance size: %d\r\n",buffer.getSize());
	}
	exit:
	return 0;
}
