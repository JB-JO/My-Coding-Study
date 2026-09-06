#pragma once
#ifndef __SLOT_H__
#define __SLOT_H__

#include "PersonTable.h"

typedef int Key;
typedef Person* Value;

enum SlotSatus {EMPTY, DELETED, INUSE};

typedef struct _slot
{
	Key key;
	Value value;
	enum SlotSatus status;
} Slot;

#endif // !__SLOT_H__