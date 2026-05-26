#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Parser.h"
#include "Tree.h"
#include "Stack.h"

int main(void)
{
	char infix[100] = "( 1 + 2 ) * ( 3 + 4 )";
	char postfix[200] = "";

	InfixToPostfix(infix, postfix);

	printf("Postfix: %s\n", postfix);

	Node* root = buildTree(postfix);

	printf("Result: %d\n", Evaluate(root));

	return 0;
}