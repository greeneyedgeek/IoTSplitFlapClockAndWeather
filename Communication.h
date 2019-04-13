/*

	Project:	SplitFlapClock
	File:		Communication.h
	Created:	2019-04-12
	Modified:	2019-04-12
	Author:		Gabriel Fontaine-Escobar
	Version:	0.1

	Description:


 	This code is in the public domain.
	https://github.com/greeneyedgeek/SplitFlapClock

 	MIT License

	Copyright (c) 2019 Gabriel Fontaine-Escobar

	Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated
	documentation files (the "Software"), to deal in the Software without restriction, including without limitation
	the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software,
	and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

	The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
	OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
	LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR
	IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

*/

#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#ifndef F_CPU
#define F_CPU 16000000UL
#endif // F_CPU

#include <avr/io.h>
#include <util/delay.h>

typedef uint8_t Direction;
typedef uint16_t Steps;
typedef uint8_t Delay;
typedef volatile uint8_t Port;
typedef uint8_t Mask;

enum{clockwise, counterclockwise};

namespace Communication
{
	class UART
	{
	public:

	private:


	};

	class TWI
	{
	public:
		TWI();
		void init_master(unsigned char twbr);
		void init_master();
		void start();
		void stop();

		void init_slave(unsigned char address);
		void listen();

		void send(unsigned char data);
		unsigned char receive(unsigned char isLast);
	};
}

#endif // COMMUNICATION_H
