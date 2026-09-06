#pragma once
#ifndef __PERSON_TABLE_H__
#define __PERSON_TABLE_H__

#define STR_LEN    100

typedef struct _person
{
	int ssn;
	char name[STR_LEN];
	char addr[STR_LEN];
} Person;

int GetSSN(Person* p);
void ShowPerInfo(Person* p);
Person* MakePersonData(int ssn, char* name, char* addr);

#endif // !__PERSON_TABLE_H__
