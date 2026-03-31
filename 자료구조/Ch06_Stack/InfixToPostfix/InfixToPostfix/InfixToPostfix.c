#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "ListBaseStack.h"

int GetOpPrec(char op)
{
	switch(op)
	{
	case '*':
	case '/':
		return 5;
	case '+':
	case '-':
		return 3;
	case '(':
		return 1;
	}
	return -1;
}

int WhoPrecOp(char op1, char op2)
{
	int op1Prec = GetOpPrec(op1);
	int op2Prec = GetOpPrec(op2);

	if (op1Prec > op2Prec)
		return 1;
	else if (op1Prec < op2Prec)
		return -1;
	else
		return 0;
}

void ConvToRPNExp(char exp[])
{
	Stack stack;
	int expLen = strlen(exp);
	char* convExp = (char*)malloc(expLen + 1); /* 변환된 수식을 담을 공간 마련  = 동적할당 */

	int i, idx = 0;
	char tok, popOp;

	memset(convExp, 0, sizeof(char) * expLen + 1); /* 마련한 공간을 0으로 초기화 */
	StackInit(&stack);

	for (i = 0; i < expLen; i++)
	{
		tok = exp[i];
		if (isdigit(tok))
		{
			convExp[idx++] = tok;
		}
		else
		{
			switch (tok)
			{
			case '(' : /* 여는 소괄호 라면, */
				SPush(&stack, tok); /* 스택에 쌓는다. */
				break;
			case ')': /* 닫는 소괄호라면, */
				while (1) /* 반복해서, */
				{
					popOp = SPop(&stack); /* 스택에서 연산자를 꺼내어, */
					if (popOp == '(') /* 연산자 (을 만날 때까지, */
						break;
					convExp[idx++] = popOp; /* 배열 convExp에 저장한다. */
				}
				break;

			case '+': case '-':
			case '*': case '/':
				while (!SIsEmpty(&stack) && WhoPrecOp(SPeek(&stack), tok) >= 0)
					convExp[idx++] = SPop(&stack);
				SPush(&stack, tok);
				break;
			}
		}
	}

	while (!SIsEmpty(&stack))
		convExp[idx++] = SPop(&stack); /* 스택에 남아 있는 모든 연산자를  이동시키는 반복문 */

	strcpy(exp, convExp); /* 변환된 수식을 반환 */
	free(convExp);
}