/*

	Project:	SplitFlapClock
	File:		Actuators.cpp
	Created:	2019-04-10
	Modified:	2019-04-10
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

#include "Actuators.h"

uint8_t Actuators::Steppers::port_values[] {0x03, 0x01, 0x09, 0x08, 0x0C, 0x04, 0x06, 0x02};

Actuators::Steppers::Steppers(Port* port, Mask mask) :
	port(port),
	mask(mask)
{}

void Actuators::Steppers::rotate(Direction direction, Steps steps, Delay ms)
{
	switch (direction)
	{
		case clockwise:
			for(Steps i = 0; i < steps/8; i++)
			{
				for(uint8_t j = 0; j < 8; j++)
				{
					*port = (mask & port_values[j]);
					_delay_ms(ms);
				}

			}
		break;

		case counterclockwise:
			for(Steps i = 0; i < steps/8; i++)
			{
				for(uint8_t j = 7; j >= 0; j--)
				{
					*port = (mask & port_values[j]);
					_delay_ms(ms);
				}
			}
		break;
	}
	PORTB &= ~(0x0F);
}
