#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
typedef int Dtdatatype;
typedef struct DlistNode
{
    Dtdatatype data;
    struct DlistNode *next;
    struct DlistNode *prev;
} ltnode;

void ListInit(ltnode **pphead);
void ListPushBack(ltnode **pphead, Dtdatatype x);