#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX    100

char stack[MAX];
int top = -1;

void push(char c)
{
	stack[++top] = c;
}

char pop()
{
	return stack[top--];
}

char peek()
{
	return stack[top];
}

int isEmpty()
{
	return top == -1;
}

int priotity(char op)
{
	if (op == '(')
		return 0;
	if (op == '+' || op == '-')
		return 1;
	if (op == '*' || op == '/')
		return 2;
	return -1;
}

void InfixToPostfix(char* exp)
{
	char* token = strtok(exp, " ");

	while (token != NULL)
	{
		if (isdigit(token[0])) // 피연산자.
		{
			printf("%s ", token);
		}

		else if (token[0] == '(') // 여는 괄호
			push('(');

		else if (token[0] == ')') //닫는 괄호
		{
			while (!isEmpty() && peek() != '(')
				printf("%c ", pop());

			pop(); // 여는 괄호 제거
		}
		else // 연산자
		{
			while (!isEmpty() && priotity(peek()) >= priotity(token[0])) // 스택이 NULL이아니고, 연산자 우선순위가 token[0]보다 높을때 까지만 반복.
				printf("%c ",pop());

			push(token[0]);
		}

		token = strtok(NULL, " ");
	}

	while (!isEmpty())
		printf("%c ", pop());
} 

int main(void)
{
	char exp[] = "( 1 + 2 ) * ( 3 + 4 )";

	InfixToPostfix(exp);

	return 0;
}