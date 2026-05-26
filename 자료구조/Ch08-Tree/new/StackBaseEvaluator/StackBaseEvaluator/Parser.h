#pragma once
#ifndef __PARSER_H__
#define __PARSER_H__

#include "Tree.h"

void InfixToPostfix(char* exp, char* postfix);
Node* buildTree(char* exp);

#endif // !__PARSER_H__
