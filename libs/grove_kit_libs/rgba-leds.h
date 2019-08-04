/*
 * Copyright (c) 2018-2019 Jonathan Anderson
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
 * Prepare the RGB LED chain.
 *
 * @param    digitalPin   pin the chain is connected to (e.g., 4 for D4)
 * @param    count        number of LEDs in the chain
 */
void rgbLedInit(int digitalPin, int count);

/**
 * Set the colours emitted by a specific RGB LED in the chain.
 *
 * @param    led          which LED to change   @pre 0 <= led < count
 * @param    hue          colour  @pre 0 <= r <= 1.0
 * @param    saturation   how colourful the colour is  @pre 0 <= r <= 1.0
 * @param    brightness   overall brightness  @pre 0 <= r <= 1.0
 */
void rgbLedHSB(int led, float hue, float saturation, float brightness);

/**
 * Set the colours emitted by a specific RGB LED in the chain.
 *
 * @param    led     which LED to change   @pre 0 <= led < count
 * @param    red     red component of LED  @pre 0 <= r <= 255
 * @param    green   green component of LED  @pre 0 <= r <= 255
 * @param    blue    blue component of LED  @pre 0 <= r <= 255
 */
void rgbLedRGB(int led, int red, int green, int blue);
