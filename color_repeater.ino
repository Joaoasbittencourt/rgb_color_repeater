#include <seeed-kit.h>
#include <Wire.h>


const int NUM_OF_COLORS = 4;
int colors[NUM_OF_COLORS][3]; 

// Rotation at the rotary dial
double rotation = 0.0;

// Ambient Brightness
double brightness = 0.0;

// Time in ms to each program loop
double program_delay = 50;

// If the button is currently pressed
boolean button_pressed = false;

// if the button is available for a action
boolean button_active = false;

// time till the button can be pressed again
double button_cooldown = 0;

// total amout of ms that the button will be off after being pressed
double button_cooldown_time = 1000;

// current colors on the LCD
double red = 0;
double green = 0;
double blue = 0;



/**
   Return information indicating the polar coordinates of the joystick and
   whether or not it has been clicked.

   @param   r         radius/distance from origin of joystick position
   @param   theta     angle in radians betewen x-axis and line form origin to joystick position

   @returns click    whether or not joystick has been clicked

   @modifies   value of r and theta to store current joystck polar coordinates
*/

/**
   Initialize every component used
*/
void initComponents();

/**
   Set LCD brightness during color menu 
*/
void setConfigBrightness();


/**
   Return correspondent letter for each one of RGB values

   @param  i  RGB component code index
*/
char getColorIndexNameByIndex(int i);
void updateButtonCooldown();
void printStats();
void updateInputs();
void printUserColorConfigControl(int colorIndex, int colorComponentIndex);
void requestUserColorInput();
void printRGBValues(int r, int g, int b);
void printTransitionProgress(int start, int end, double percentage);
void runColors();

int main() 
{
	initComponents();
	lcdClear();
	requestUserColorInput();
	runColors();
	return 0;
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

void printStats() 
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
		int increments = 100;

		if (next_color_index > NUM_OF_COLORS - 1)
		{
			next_color_index = 0;
		}

		red = colors[i][0];
		green = colors[i][1];
		blue = colors[i][2];
		
		double dr = (colors[next_color_index][0] - red) / increments;
		double dg = (colors[next_color_index][1] - green) / increments;
		double db = (colors[next_color_index][2] - blue) / increments;
	
		for(int j = 0; j < increments; j++)
		{
			red += dr;
			green += dg;
			blue += db;
			double percentage = j * 100.0 / increments;
			
			lcdClear();
			printRGBValues(red, green, blue);
			printTransitionProgress(i + 1, next_color_index + 1, percentage);
			delay(program_delay);
		}
		
		i = next_color_index;  
	}
}
