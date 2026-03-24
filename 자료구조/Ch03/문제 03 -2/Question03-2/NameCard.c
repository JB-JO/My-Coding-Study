#include <stdio.h>
#include "NameCard.h"
#include <malloc.h>
#include <string.h>

NameCard* MakeNameCard(char* name, char* phone) {
	NameCard* NewCard = (NameCard*)malloc(sizeof(NameCard));
	strcpy(NewCard->name, name);
	strcpy(NewCard->phone, phone);
	return NewCard;
}

void ShowNameCardInfo(NameCard* pcard) {
	printf("[이름]: %s\n", pcard->name);
	printf("[번호]: %s\n\n", pcard->phone);
}

int NameCompare(NameCard* pcard, char* name) {
	return strcmp(pcard->name, name);
}

void ChangePhoneNum(NameCard* pcard, char* phone) {
	strcpy(pcard->phone, phone);
}
