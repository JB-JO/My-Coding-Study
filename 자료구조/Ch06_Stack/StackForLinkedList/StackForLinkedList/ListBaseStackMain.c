#include <stdio.h>
#include <malloc.h>
#include "ListBaseStack.h"

int main(void)
{
	Stack stack;
	StackInit(&stack);

	SPush(&stack, 1); SPush(&stack, 2);
	SPush(&stack, 3); SPush(&stack, 4);
	SPush(&stack, 5);

	printf("%d\n", SPeek(&stack));

	while (!SIsEmpty(&stack))
		printf("%d ", SPop(&stack));

	return 0;
}