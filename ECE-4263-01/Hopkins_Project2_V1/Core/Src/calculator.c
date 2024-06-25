
#include "calculator.h"
#include "ili9163.h"
#include "fonts.h"
#include "colors.h"
#include "ili9163.h"

void getTitleScreen()
{
	//INITIALIZE TITLE SCREEN UI/UX
	ILI9163_init(0);
	HAL_Delay(1000);
	ILI9163_newFrame();

	//TITLE SCREEN BACKGROUND
	ILI9163_fillRect(0, 0, ILI9163_WIDTH, ILI9163_HEIGHT, BLUE);

	//TITLE SCREEN TITLE
	ILI9163_drawStringF(50, 5, Font_11x18, WHITE, "Tyme's");
	ILI9163_drawStringF(25, 25, Font_11x18, WHITE, "Calculator");

	//RECTANGLE BOARDER
	ILI9163_drawRect(5, 45, 155, 123, 3, BLACK);

	//CALCULATOR KEY PAD ROW 1
	ILI9163_drawStringF(10, 50, Font_11x18, WHITE, "1");
	ILI9163_drawStringF(47, 50, Font_11x18, WHITE, "2");
	ILI9163_drawStringF(90, 50, Font_11x18, WHITE, "3");
	ILI9163_drawStringF(132, 50, Font_11x18, WHITE, "/");

	//CALCULATOR KEY PAD ROW 2
	ILI9163_drawStringF(10, 68, Font_11x18, WHITE, "4");
	ILI9163_drawStringF(47, 68, Font_11x18, WHITE, "5");
	ILI9163_drawStringF(90, 68, Font_11x18, WHITE, "6");
	ILI9163_drawStringF(132, 68, Font_11x18, WHITE, "x");

	//CALCULATOR KEY PAD ROW 3
	ILI9163_drawStringF(10, 86, Font_11x18, WHITE, "7");
	ILI9163_drawStringF(47, 86, Font_11x18, WHITE, "8");
	ILI9163_drawStringF(90, 86, Font_11x18, WHITE, "9");
	ILI9163_drawStringF(132, 86, Font_11x18, WHITE, "-");

	//CALCULATOR KEY PAD ROW 4
	ILI9163_drawStringF(10, 110, Font_11x18, WHITE, "*");
	ILI9163_drawStringF(47, 104, Font_11x18, WHITE, "0");
	ILI9163_drawStringF(90, 104, Font_11x18, WHITE, "#");
	ILI9163_drawStringF(132, 104, Font_11x18, WHITE, "+");

	//RENDER TITLE SCREEN UI/UX
	HAL_Delay(100);
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
	ILI9163_drawStringF(132, 50, Font_11x18, WHITE, "(");

	//CALCULATOR KEY PAD ROW 2
	ILI9163_drawStringF(10, 68, Font_11x18, WHITE, "4");
	ILI9163_drawStringF(47, 68, Font_11x18, WHITE, "5");
	ILI9163_drawStringF(90, 68, Font_11x18, WHITE, "6");
	ILI9163_drawStringF(132, 68, Font_11x18, WHITE, ")");

	//CALCULATOR KEY PAD ROW 3
	ILI9163_drawStringF(10, 86, Font_11x18, WHITE, "7");
	ILI9163_drawStringF(47, 86, Font_11x18, WHITE, "8");
	ILI9163_drawStringF(90, 86, Font_11x18, WHITE, "9");
	ILI9163_drawStringF(132, 90, Font_11x18, WHITE, "^");

	//CALCULATOR KEY PAD ROW 4
	ILI9163_drawStringF(10, 110, Font_11x18, WHITE, "*");
	ILI9163_drawStringF(47, 104, Font_11x18, WHITE, "0");
	ILI9163_drawStringF(90, 104, Font_11x18, WHITE, "#");
	ILI9163_drawStringF(132, 100, Font_11x18, WHITE, ".");

	//RENDER TITLE SCREEN UI/UX
	HAL_Delay(100);
	ILI9163_render();
	HAL_Delay(1000);
}


