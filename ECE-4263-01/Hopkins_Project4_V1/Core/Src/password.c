/*
 *  password.c
 *
 *  Created on: Nov 2, 2023
 *  Author: tymehopkins
 *
 */
#include "password.h"
#include "GUI.h"
#include "ili9163.h"

extern char input[10];
extern char password[10];
char passwordtemp[10];
int inputLen = 0;
char inputLenChar[10];

void setPassword();
void checkPassword();

void setPassword()
{
	for (int i = 0; i <= strlen(input); i++)
	{
		password[i] = input[i];
	}
	password[strlen(password)] = '\0'; //Converts the character array 'input' to a string
	savedPassword(); //GUI to tell user their password has been saved
	enterPassword(); //GUI to tell user to enter a password to login
	//input[0] = '\0';
	screenClr();
//	ILI9163_newFrame();
//	sprintf(passwordtemp, "Set Password: %s", &password);
//	ILI9163_drawStringF(5, 5, Font_11x18, BLUE, passwordtemp);
//	ILI9163_render();
}

//Checks if the password is correct, incorrect, or needs to be entered
void checkPassword()
{
	//password[strlen(password)] = '\0';
	//input[strlen(input)] = '\0'; //Converts the character array 'input' to a string
	if(strcmp(password, input) == 0) //Need to create something that will save the newPassword and then I can type in the password to see if it matches
	{
		correctPassword(); //GUI to say "Password is Correct"
		enterPassword(); //GUI to tell user to enter a password to login
		HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_0); //Flashes green light
		HAL_Delay(3000); //Flashes green light for 3 seconds
		screenClr();
	}
	else
	{
		incorrectPassword(); //GUI to say "Password is Correct"
		HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_2); //Flashes red light
		HAL_Delay(3000); //Flashes red light for 3 seconds
		screenClr();
	}
}
