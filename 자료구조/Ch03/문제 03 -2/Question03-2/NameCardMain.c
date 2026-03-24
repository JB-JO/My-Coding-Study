#include <stdio.h>
#include <malloc.h>
#include "NameCard.h"
#include "ArrayList.h"

int main(void) {
    List list;
    NameCard* pcard;
    ListInit(&list);

    pcard = MakeNameCard("노무현", "010-2008-0523");
    LInsert(&list, pcard);

    pcard = MakeNameCard("김대중", "010-1111-2222");
    LInsert(&list, pcard);

    pcard = MakeNameCard("문재인", "010-1234-5678");
    LInsert(&list, pcard);

    if (LFirst(&list, &pcard)) {
        if (!NameCompare(pcard, "노무현")) {
            ShowNameCardInfo(pcard);
        } 
        else 
        {
            while (LNext(&list, &pcard))
            {
                if (!NameCompare(pcard, "노무현")) 
                {
                    ShowNameCardInfo(pcard);
                    break;
                }
            }
        }
    }

    if (LFirst(&list, &pcard)) {
        if (!NameCompare(pcard, "문재인")) 
        {
            ChangePhoneNum(pcard, "010-8765-4321");
        }
        else {
            while(LNext(&list, &pcard))
            {
                if (!NameCompare(pcard, "문재인")) 
                {
                    ChangePhoneNum(pcard, "010-8765-4321");
                    break;
                }
            }
        }
    }

    if (LFirst(&list, &pcard)) {
        if (!NameCompare(pcard, "김대중")) {
            pcard = LRemove(&list);
            free(pcard);
        }
        else {
            while (LNext(&list, &pcard))
            {
                if (!NameCompare(pcard, "김대중")) {
                    pcard = LRemove(&list);
                    free(pcard);
                    break;
                }
            }
        }
    }

    printf("현재 데이터의 수: %d\n", LCount(&list));

    if (LFirst(&list, &pcard)) {
        ShowNameCardInfo(pcard);

        while (LNext(&list, &pcard)) {
            ShowNameCardInfo(pcard);
        }
    }

    return 0;

}