/*
 * Copyright (c) 2019 Jonathan Anderson
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 *
 * * Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "Grove_LCD_RGB_Backlight/rgb_lcd.h"
#include "lcd-display.h"

rgb_lcd lcd;


void lcdInit()
{
	lcd.begin(16, 2);
	lcd.clear();
	lcd.setRGB(10, 10, 10);
}

void lcdBacklightColour(int red, int green, int blue)
{
	lcd.setRGB(red, green, blue);
}

void lcdClear()
{
	lcd.clear();
}

void lcdMoveCursor(int x, int y)
{
	lcd.setCursor(x, y);
}

void lcdPrint(double x)
{
	lcd.print(x);
}

void lcdPrint(int n)
{
	lcd.print(n);
}

void lcdPrint(const char *message)
{
	lcd.print(message);
}

void lcdPrint(char c)
{
	lcd.print(c);
}

