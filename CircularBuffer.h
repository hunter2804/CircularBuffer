#ifndef __CIRCULAR_BUFFER_H__
#define __CIRCULAR_BUFFER_H__

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define debug printf

#define Buffer			packet.buffer
#define Length		packet.bufferLength
#define Head			packet.head
#define Tail			packet.tail
#define bufferFull		packet.isBufferFull

class CircularBuffer{
	private:
		struct circularBuffer{
			uint8_t *buffer;
			uint32_t bufferLength;
			uint32_t head;
			uint32_t tail;
			bool isBufferFull;
		}packet;

		bool initialized;
		void flushPacket(const uint32_t length);
	public:
		CircularBuffer(const uint32_t dataLength);
		~CircularBuffer(void);

		bool write(const uint8_t data);
		bool write(const uint8_t *data, uint32_t length);

		const uint8_t read(void);

		bool remove(const uint32_t length=1);

		const uint32_t getSize(void);
};

#endif

