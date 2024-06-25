#include "GUI.h"
#include "ili9163.h"
#include "fonts.h"
#include "colors.h"
#include "ili9163.h"

//External variables
extern char input[10];
extern char keyChar;

//Function calls
void getTitleScreen();
void getShiftScreen();
void correctPassword();
void incorrectPassword();
void savedPassword();
void enterPassword();
char screenClr();

void getTitleScreen()
{
	//INITIALIZE TITLE SCREEN UI/UX
	ILI9163_init(0);
	HAL_Delay(1000);
	ILI9163_newFrame();

	//TITLE SCREEN BACKGROUND
	ILI9163_fillRect(0, 0, ILI9163_WIDTH, ILI9163_HEIGHT, BLUE);

	//TITLE SCREEN TITLE
	ILI9163_drawStringF(36, 5, Font_11x18, WHITE, "Password");
	ILI9163_drawStringF(14, 25, Font_11x18, WHITE, "Keypad Guide");

	//RECTANGLE BOARDER
	ILI9163_drawRect(5, 45, 155, 123, 3, BLACK);

	//CALCULATOR KEY PAD ROW 1
	ILI9163_drawStringF(10, 50, Font_11x18, WHITE, "1");
	ILI9163_drawStringF(47, 50, Font_11x18, WHITE, "2");
	ILI9163_drawStringF(90, 50, Font_11x18, WHITE, "3");
	ILI9163_drawStringF(132, 50, Font_11x18, WHITE, "A");

	//CALCULATOR KEY PAD ROW 2
	ILI9163_drawStringF(10, 68, Font_11x18, WHITE, "4");
	ILI9163_drawStringF(47, 68, Font_11x18, WHITE, "5");
	ILI9163_drawStringF(90, 68, Font_11x18, WHITE, "6");
	ILI9163_drawStringF(132, 68, Font_11x18, WHITE, "B");

	//CALCULATOR KEY PAD ROW 3
	ILI9163_drawStringF(10, 86, Font_11x18, WHITE, "7");
	ILI9163_drawStringF(47, 86, Font_11x18, WHITE, "8");
	ILI9163_drawStringF(90, 86, Font_11x18, WHITE, "9");
	ILI9163_drawStringF(132, 86, Font_11x18, WHITE, "C");

	//CALCULATOR KEY PAD ROW 4
	ILI9163_drawString(10, 107, Font_7x10, WHITE, "sft");
	ILI9163_drawStringF(47, 104, Font_11x18, WHITE, "0");
	ILI9163_drawStringF(90, 107, Font_7x10, WHITE, "set");
	ILI9163_drawStringF(132, 104, Font_11x18, WHITE, "D");

	//RENDER TITLE SCREEN UI/UX
	HAL_Delay(50);
	ILI9163_render();
	HAL_Delay(1000);
}

void getShiftScreen()
{
	//INITIALIZE TITLE SCREEN UI/UX
	ILI9163_init(0);
	HAL_Delay(1000);
	ILI9163_newFrame();

	//TITLE SCREEN BACKGROUND
	ILI9163_fillRect(0, 0, ILI9163_WIDTH, ILI9163_HEIGHT, BLUE);

	//TITLE SCREEN TITLE
	ILI9163_drawStringF(53, 5, Font_11x18, WHITE, "Shift");
	ILI9163_drawStringF(60, 25, Font_11x18, WHITE, "Mode");

	//RECTANGLE BOARDER
	ILI9163_drawRect(5, 45, 155, 123, 3, BLACK);

	//CALCULATOR KEY PAD ROW 1
	ILI9163_drawStringF(10, 50, Font_11x18, WHITE, "1");
	ILI9163_drawStringF(47, 50, Font_11x18, WHITE, "2");
	ILI9163_drawStringF(90, 50, Font_11x18, WHITE, "3");
	ILI9163_drawStringF(132, 50, Font_11x18, WHITE, "!");

	//CALCULATOR KEY PAD ROW 2
	ILI9163_drawStringF(10, 68, Font_11x18, WHITE, "4");
	ILI9163_drawStringF(47, 68, Font_11x18, WHITE, "5");
	ILI9163_drawStringF(90, 68, Font_11x18, WHITE, "6");
	ILI9163_drawStringF(132, 68, Font_11x18, WHITE, "@");

	//CALCULATOR KEY PAD ROW 3
	ILI9163_drawStringF(10, 86, Font_11x18, WHITE, "7");
	ILI9163_drawStringF(47, 86, Font_11x18, WHITE, "8");
	ILI9163_drawStringF(90, 86, Font_11x18, WHITE, "9");
	ILI9163_drawStringF(132, 90, Font_11x18, WHITE, "$");

	//CALCULATOR KEY PAD ROW 4
	ILI9163_drawStringF(10, 110, Font_11x18, WHITE, "*");
	ILI9163_drawStringF(47, 104, Font_11x18, WHITE, "chk");
	ILI9163_drawStringF(90, 104, Font_11x18, WHITE, "clr");
	ILI9163_drawStringF(132, 100, Font_11x18, WHITE, "_");

	//RENDER TITLE SCREEN UI/UX
	HAL_Delay(50);
	ILI9163_render();
	HAL_Delay(3000);
}

void displayInput()
{
	keyChar = 0;
	ILI9163_newFrame();
	ILI9163_drawStringF(5, 5, Font_11x18, BLUE, input);
	ILI9163_render();
}

void correctPassword()
{
	ILI9163_init(0);
	HAL_Delay(1000);
	ILI9163_newFrame();

	//TITLE SCREEN BACKGROUND
	ILI9163_fillRect(0, 0, ILI9163_WIDTH, ILI9163_HEIGHT, GREEN);

	//TITLE SCREEN TITLE
	ILI9163_drawStringF(41.5, 71, Font_11x18, WHITE, "Correct");

	//RENDER TITLE SCREEN UI/UX
	HAL_Delay(100);
	ILI9163_render();
	HAL_Delay(1000);
}

void incorrectPassword()
{
	ILI9163_init(0);
	HAL_Delay(1000);
	ILI9163_newFrame();

	//TITLE SCREEN BACKGROUND
	ILI9163_fillRect(0, 0, ILI9163_WIDTH, ILI9163_HEIGHT, RED);

	//TITLE SCREEN TITLE
	ILI9163_drawStringF(30.5, 41, Font_11x18, WHITE, "Incorrect");
	ILI9163_drawStringF(14, 64, Font_11x18, WHITE, "Please retry");

	//RENDER TITLE SCREEN UI/UX
	HAL_Delay(100);
	ILI9163_render();
	HAL_Delay(1000);
}

//void --> can't remember what I was going to put here

void savedPassword()
{
	ILI9163_init(0);
	HAL_Delay(1000);
	ILI9163_newFrame();

	//TITLE SCREEN BACKGROUND
	ILI9163_fillRect(0, 0, ILI9163_WIDTH, ILI9163_HEIGHT, BLUE);

	//TITLE SCREEN TITLE
	ILI9163_drawString(3, 41, Font_11x18, WHITE, "A new password");
	ILI9163_drawString(3, 64, Font_11x18, WHITE, "has been saved");

	//RENDER TITLE SCREEN UI/UX
	HAL_Delay(100);
	ILI9163_render();
	HAL_Delay(3000);
}

void enterPassword()
{
	ILI9163_init(0);
	HAL_Delay(1000);
	ILI9163_newFrame();

	//TITLE SCREEN BACKGROUND
	ILI9163_fillRect(0, 0, ILI9163_WIDTH, ILI9163_HEIGHT, BLUE);

	//TITLE SCREEN TITLE
	ILI9163_drawString(3, 41, Font_11x18, WHITE, "Enter password");
	ILI9163_drawString(36, 64, Font_11x18, WHITE, "to login");

	//RENDER TITLE SCREEN UI/UX
	HAL_Delay(100);
	ILI9163_render();
	HAL_Delay(3000);
}

//void updateScreen(char* writeString)
//{
//    ILI9163_newFrame();
//    ILI9163_drawStringF(5, 55, Font_11x18, BLUE, writeString);
//    ILI9163_render();
//}

char screenClr()
{
	input[0] = '\0';
	ILI9163_newFrame();
	ILI9163_render();
	return 0;
}
