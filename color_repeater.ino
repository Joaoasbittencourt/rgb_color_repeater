#include <seeed-kit.h>
#include <Wire.h>

const int NUM_OF_COLORS = 4;

int colors[NUM_OF_COLORS][3]; 
							// {{ 255, 0, 0 },
 							//  { 0, 255, 0 },
 							//  { 0, 0, 255 },
							//  { 0, 255, 0 }};

double rotation = 0.0;
double brightness = 0.0;

double program_delay = 50;

boolean button_pressed = false;
boolean button_active = false;
double button_cooldown = 0;
double button_cooldown_time = 1000;

double red = 0;
double green = 0;
double blue = 0;

void runTest() 
{
	runColors();
}

void initComponents() 
{
	init();
	lcdInit();
}

void setConfigBrightness()
{
	if (brightness > 1) {
		brightness = 1;
	}

	if (brightness < 0) {
		brightness = 0;
	}

	double value =  255 - 245.0 * brightness;
	lcdBacklightColour(value, value, value);
}

char getColorIndexNameByIndex(int i) 
{
	if (i == 0) return 'R';
	else if (i == 1) return 'G';
	else return 'B';
}

void updateButtonCooldown()
{
	if (button_cooldown > 1)
	{
		button_cooldown -= program_delay;
	}

	if (button_cooldown < 0) 
	{
		button_cooldown = 0;
	}

	if (button_pressed && button_cooldown == 0)
	{
		button_cooldown = button_cooldown_time;
		button_active = true;
	}

	if(!button_pressed && button_cooldown == 0)
	{
		button_active = false;
	}
}


void updateInputs()
{
	rotation = analogRead(A0) / 1023.0;
	brightness = analogRead(A2) / 780.0;
	button_pressed = digitalRead(3);
	updateButtonCooldown();
}

void printStats () 
{
	lcdPrint("rotation = ");
	lcdPrint(rotation);
	lcdMoveCursor(0, 1);
	lcdPrint("brightness = ");
	lcdPrint(brightness);
}


void printUserColorConfigControl(int colorIndex, int colorComponentIndex)
{
	lcdClear();
	lcdPrint("Color ");
	lcdPrint(colorIndex + 1);
	lcdPrint(" ");
	lcdPrint(getColorIndexNameByIndex(colorComponentIndex));
	lcdPrint(": ");
	lcdPrint(rotation * 255);
	lcdMoveCursor(0, 1);
	lcdPrint("button to cont.");
}

void requestUserColorInput() 
{
	for (int color = 0; color < NUM_OF_COLORS; color++) 
	{
		int component = 0;
		while (component < 3)
		{
			printUserColorConfigControl(color, component);
			updateInputs();
			setConfigBrightness();
			delay(program_delay);

			if (button_active) 
			{
				colors[color][component] = rotation * 255;
				button_active = false;
				component++;
			}
		}
	}
	lcdClear();
}


void printRGBValues(int r, int g, int b)
{
	lcdBacklightColour(r, g, b);	 
	lcdPrint("R:");
	lcdPrint(r);
	lcdPrint(" G:");
	lcdPrint(g);
	lcdPrint(" B:");
	lcdPrint(b);
}

void printTransitionProgress(int start, int end, double percentage) 
{
	lcdMoveCursor(0, 1);
	lcdPrint(start);
	lcdMoveCursor(15, 1);
	lcdPrint(end);
	lcdMoveCursor(1, 1);

	double n = (14.0 * percentage) / 100.0; 	
	for (int i = 0; i < n; i++) 
	{
		lcdPrint("|");
	}
}

void runColors()
{
	int i = 0;

	while(i < NUM_OF_COLORS)
	{
		int next_color_index = i + 1;

		if (next_color_index > NUM_OF_COLORS - 1)
		{
			next_color_index = 0;
		}

		red = colors[i][0];
		green = colors[i][1];
		blue = colors[i][2];
		
		int increments = 100;
	
		int next_red = colors[next_color_index][0];
		int next_green = colors[next_color_index][1];
		int next_blue = colors[next_color_index][2];

		double dr = (next_red - red) / increments;
		double dg = (next_green - green ) / increments;
		double db = (next_blue - blue) / increments;
	
		for(int j = 0; j < increments; j++)
		{
			delay(program_delay);

			red += dr;
			green += dg;
			blue += db;
			double percentage = j * 100.0 / increments;
			lcdClear();
			printRGBValues(red, green, blue);
			printTransitionProgress(i + 1, next_color_index + 1, percentage);
		}
		
		i = next_color_index;  
	}
}

int main() 
{
	initComponents();
	lcdClear();

	// runTest();

	requestUserColorInput();
	runColors();
	return 0;
}
