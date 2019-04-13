/*

	Project:	SplitFlapClock
	File:		SplitFlapClock.cpp
	Created:	2019-04-10
	Modified:	2019-04-10
	Author:		Gabriel Fontaine-Escobar
	Version:	0.1

	Description:


	References:
	The AVR Microcontroller and Embedded Systems Using Assembly And C. ISBN10 0138003319. ISBN13 9780138003319.


	The circuit:
 	*
 	*

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

#include "Actuators.h"

#define F_CPU 16000000

namespace
{
	int main()
	{
			DDRB = 0x0F;
			Actuators::Steppers stepper1(&PORTB, 0x0F);

			while (1)
			{
				stepper1.rotate(clockwise, 4096, 1);
				_delay_ms(2000);
				stepper1.rotate(counterclockwise, 4096, 1);
				_delay_ms(2000);
			}
	}
}

