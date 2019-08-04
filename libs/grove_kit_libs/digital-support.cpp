/*
 * Copyright (c) 2019 Lori Hogan
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

#include "digital-support.h"

//Functions to support various "typical" digital devices

/**
 * This function plays a note of the given frequency using the Grove speaker/buzzer
 *
 * @param   	f     	the frequency of note to be played in Hz @pre > 0
 * @param		port  	the digital post into which the buzzer or speaker in connected
 * @param		seconds	approximate time in seconds you want note to play
 *
 * @returns     nothing
 * @modifies	plays a note from the speaker/buzzer corresponding to the frequency
 */
void speakerPlayNote(int f, int port, float seconds)
{

  //Convert frequency of note to time period in microseconds
  int time = 1000000.0 / (2 * f);

  //Send digital square wave to speaker with the calculated period
  for (int i = 0; i < 300*seconds; i++)
  {
    digitalWrite(port, HIGH);
    delayMicroseconds(time);
    digitalWrite(port, LOW);
    delayMicroseconds(time);
  }
}
