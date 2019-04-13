/*

	Project:	SplitFlapClock
	File:		Communication.cpp
	Created:	2019-04-12
	Modified:	2019-04-12
	Author:		Gabriel Fontaine-Escobar
	Version:	0.1

	Description:

	References:
	The AVR Microcontroller and Embedded Systems Using Assembly And C. ISBN10 0138003319. ISBN13 9780138003319.

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

#include "Communication.h"

Communication::TWI::TWI()
{
	init_master();
}

void Communication::TWI::init_master(unsigned char twbr)
{
	TWBR = twbr; // TWBR = ((F_CPU / F_TWI) - 16) / 2          ---0x48
	TWSR = 0x00; // No Prescaler
	TWCR = 0x04; // Enable TWI
}

void Communication::TWI::init_master()
{
	TWBR = 0x48; // TWBR = ((F_CPU / F_TWI) - 16) / 2          ---0x48
	TWSR = 0x00; // No Prescaler
	TWCR = 0x04; // Enable TWI
}

void Communication::TWI::start()
{
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTA);
	while ((TWCR & (1<<TWINT))==0);
}

void Communication::TWI::stop()
{
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
}

void Communication::TWI::init_slave(unsigned char address)
{
	TWCR = 0x04; // Enable TWI
	TWAR = address;
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA); // Init TWI
}

void Communication::TWI::listen()
{
	while ((TWCR & (1<<TWINT))==0); // Wait
}

void Communication::TWI::send(unsigned char data)
{
	TWDR = data;
	TWCR = (1<<TWINT)|(1<<TWEN);
	while ((TWCR & (1<<TWINT))==0);
}

unsigned char Communication::TWI::receive(unsigned char isLast)
{
	if (!isLast) {TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);} // ACK
	else {TWCR = (1<<TWINT)|(1<<TWEN);} // NACK
	while ((TWCR & (1<<TWINT))==0);
	return TWDR;
}
