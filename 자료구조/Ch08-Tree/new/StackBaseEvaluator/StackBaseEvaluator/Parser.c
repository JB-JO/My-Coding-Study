#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Parser.h"
#include "Stack.h"
#include "Tree.h"

int Priority(char op)
{
	if (op == '(')
		return 0;
	
	if (op == '+' || op == '-')
		return 1;

	if (op == '*' || op == '/')
		return 2;
	else
		return -1;
}

void InfixToPostfix(char* exp, char* postfix)
{
	char* token = strtok(exp, " ");

	while (token != NULL)
	{
		if (isdigit(token[0]))
		{
			strcat(postfix, token);
			strcat(postfix, " ");
		}
		else if (token[0] == '(')
		{
			Push('(');
		}
		else if (token[0] == ')')
		{
			while (!isEmpty() && Peek() != '(')
			{
				char op[2] = { Pop(), '\0' };
				strcat(postfix, op);
				strcat(postfix, " ");
			}
			Pop();
		}
		else
		{
			while (!isEmpty() && Priority(Peek()) >= Priority(token[0]))
			{
				char op[2] = { Pop(), '\0' };
				strcat(postfix, op);
				strcat(postfix, " ");
			}
			Push(token[0]);
		}
		token = strtok(NULL, " ");
	}
	while (!isEmpty())
	{
		char op[2] = { Pop(), '\0' };
		strcat(postfix, op);
		strcat(postfix, " ");
	}
}

Node* buildTree(char* exp)
{
	char* token = strtok(exp, " ");

	while (token != NULL)
	{
		if (isdigit(token[0]))
			Push(MakeNumNode(atoi(token)));
		else
		{
			Node* right = Pop();
			Node* left = Pop();

			Node* node = MakeOperatorNode(token[0]);
			node->left = left;
			node->right = right;

			Push(node);
		}
		token = strtok(NULL, " ");
	}

	return Pop();
}