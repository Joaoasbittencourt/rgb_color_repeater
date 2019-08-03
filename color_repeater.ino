#include <seeed-kit.h>
#include <Wire.h>

int colors[3][3];

double rotation = 0.0;
double brightness = 0.0;

double program_delay = 50;

boolean button_pressed = false;
boolean button_active = false;
double button_cooldown = 0;
double button_cooldown_time = 1000;

int red = 0;
int green = 0;
int blue = 0;

void initComponents() 
{
	init();
	lcdInit();
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
	for (int color = 0; color < 3; color++) 
	{
		int component = 0;
		while (component < 3)
		{
			printUserColorConfigControl(color, component);
			updateInputs();
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
	lcdClear();
	lcdBacklightColour(r, g, b);	 
	lcdPrint("(");
	lcdPrint(r);
	lcdPrint(",");
	lcdPrint(g);
	lcdPrint(",");
	lcdPrint(b);
	lcdPrint(")");
}

void runColors()
{
	int i = 0;
	while(i < 3)
	{
		red = colors[i][0];
		green = colors[i][1];
		blue = colors[i][2];
		
		int increments = 100;
	
		int next_red = colors[i + 1][0];
		int next_green = colors[i + 1][1];
		int next_blue = colors[i + 1][2];

		int red_increment = (next_red - red) / increments;
		int green_increment = (next_green - green ) / increments;
		int blue_increment = (next_blue - blue) / increments;

		int j = 0;
		while(j < increments)
		{
				delay(program_delay);	
				red += red_increment;
				green += green_increment;
				blue += blue_increment;
				printRGBValues(red, green, blue);
				j++;
		}
		
		lcdBacklightColour(next_red, next_green, next_blue);
		i++;

		if(i > 2){
			i = 0; 
		}
	}
}

int main() 
{
	initComponents();
	lcdClear();
	requestUserColorInput();
	runColors();
	return 0;
}
