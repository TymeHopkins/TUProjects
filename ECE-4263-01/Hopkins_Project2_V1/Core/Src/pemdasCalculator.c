// PEMDAS calculator mathematical logic and operations credit due to https://github.com/yousefkotp/PEMDAS-Calculator/tree/main

#include "ili9163.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 100

typedef struct
{
    double items[MAX_SIZE];
    int top;
} OperandStack;

typedef struct
{
    char items[MAX_SIZE];
    int top;
} OperatorStack;

void pushOperand(OperandStack* stack, double value)
{
    if (stack->top == MAX_SIZE - 1)
    {
        printf("Operand Stack overflow\n");
        exit(1);
    }
    stack->items[++stack->top] = value;
}

double popOperand(OperandStack* stack)
{
    if (stack->top == -1)
    {
        printf("Operand Stack underflow\n");
        exit(1);
    }
    return stack->items[stack->top--];
}

void pushOperator(OperatorStack* stack, char value)
{
    if (stack->top == MAX_SIZE - 1)
    {
        printf("Operator Stack overflow\n");
        exit(1);
    }
    stack->items[++stack->top] = value;
}

char popOperator(OperatorStack* stack)
{
    if (stack->top == -1)
    {
        printf("Operator Stack underflow\n");
        exit(1);
    }
    return stack->items[stack->top--];
}

int precedence(char op)
{
    switch (op)
    {
    	case '+':
        case '-':
            return 1;
        case 'x':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

double calculate(const char* expr)
{
    OperatorStack operatorStack = {.top = -1};
    OperandStack operandStack = {.top = -1};

    for (int i = 0; i < strlen(expr); ++i)
    {
        char c = expr[i];

        if (isdigit(c) || c == '.')
        {
            char number[32]; //temporary array
            int j = 0;
            while (isdigit(expr[i]) || expr[i] == '.')
            {
                number[j++] = expr[i++];
            }
            number[j] = '\0'; //Sets null to end of array to convert to string
            pushOperand(&operandStack, atof(number)); //Converts the string of characters to float
            --i;
        }

        else if (c == '(')
        {
            pushOperator(&operatorStack, c);
        }

        else if (c == ')')
        {
            while (operatorStack.top != -1 && operatorStack.items[operatorStack.top] != '(')
            {
                char op = popOperator(&operatorStack);
                double b = popOperand(&operandStack);
                double a = popOperand(&operandStack);
                switch (op)
                {
                    case '+': pushOperand(&operandStack, a + b); break;
                    case '-': pushOperand(&operandStack, a - b); break;
                    case 'x': pushOperand(&operandStack, a * b); break;
                    case '/': pushOperand(&operandStack, a / b); break;
                    case '^': pushOperand(&operandStack, pow(a, b)); break;
                }
            }
            if (operatorStack.top != -1)
            {
                popOperator(&operatorStack);
            }
        }

        else if (c == '+' || c == '-' || c == 'x' || c == '/' || c == '^')
        {
            while (operatorStack.top != -1 && precedence(c) <= precedence(operatorStack.items[operatorStack.top]))
            {
                char op = popOperator(&operatorStack);
                double b = popOperand(&operandStack);
                double a = popOperand(&operandStack);
                switch (op)
                {
                    case '+': pushOperand(&operandStack, a + b); break;
                    case '-': pushOperand(&operandStack, a - b); break;
                    case 'x': pushOperand(&operandStack, a * b); break;
                    case '/': pushOperand(&operandStack, a / b); break;
                    case '^': pushOperand(&operandStack, pow(a, b)); break;
                }
            }
            pushOperator(&operatorStack, c);
        }
    }

    while (operatorStack.top != -1)
    {
        char op = popOperator(&operatorStack);
        double b = popOperand(&operandStack);
        double a = popOperand(&operandStack);
        switch (op)
        {
            case '+': pushOperand(&operandStack, a + b); break;
            case '-': pushOperand(&operandStack, a - b); break;
            case 'x': pushOperand(&operandStack, a * b); break;
            case '/': pushOperand(&operandStack, a / b); break;
            case '^': pushOperand(&operandStack, pow(a, b)); break;
        }
    }

    char temp[50];
    sprintf(temp, "Answer: %.3f", popOperand(&operandStack));
    updateScreen(temp);
}

void updateScreen(char* writeString)
{
    ILI9163_drawStringF(5, 55, Font_11x18, RED, writeString);
    ILI9163_render();
}
