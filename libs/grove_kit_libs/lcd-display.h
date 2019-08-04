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


/**
 * Set up the LCD screen for use.
 *
 * This function must be called before any of the other LCD functions will work.
 */
void lcdInit();


/**
 * Change the colour of the LCD backlight.
 *
 * @param    red      how red the backlight should be: [0,255]
 * @param    green    how green the backlight should be: [0,255]
 * @param    blue     how blue the backlight should be: [0,255]
 */
void lcdBacklightColour(int red, int green, int blue);

/**
 * Clear all text from the LCD display.
 */
void lcdClear();

/**
 * Move the cursor to a specific location.
 *
 * @param    int x     which column to move the cursor to
 * @param    int y     which row to move the cursor to
 */
void lcdMoveCursor(int x, int y);

/**
 * Print a floating-point number to the LCD screen.
 *
 * @param   f    the number to print
 */
void lcdPrint(double);

/**
 * Print an integer to the LCD screen.
 *
 * @param   n    the integer to print
 */
void lcdPrint(int n);

/**
 * Print a string to the LCD screen.
 */
void lcdPrint(const char *);

/**
 * Print a char to the LCD screen.
 */
 void lcdPrint(char c);
