#pragma once
#ifndef __STACK_H__
#define __STACK_H__

#include "Tree.h"

#define MAX    100

void Push(Node* node);
Node* Pop();
Node* Peek();
int isEmpty();

#endif // !__STACK_H__
