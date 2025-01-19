#include "Dlist.h"

void ListInit(ltnode **pphead)
{
    *pphead = (ltnode *)malloc(sizeof(ltnode));
    (*pphead)->next = pphead;
    (*pphead)->prev = pphead;
}
void ListPushBack(ltnode **pphead, Dtdatatype x);