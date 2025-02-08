#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
typedef int Sldatatype;
typedef struct SlistNode
{
    Sldatatype data;
    struct SlistNode *next;
} Sltnode;

void SlistPrint(Sltnode *phead);
Sltnode *Buylistnode(Sldatatype x);
void SlistPushBack(Sltnode **pphead, Sldatatype x);
void SlistPushFront(Sltnode **pphead, Sldatatype x); // 头插
void SlistPopBack(Sltnode **pphead);
void SlistPopFront(Sltnode **pphead);//头删
Sltnode *SlistFind(Sltnode *phead, Sldatatype x);
void SlistInsert(Sltnode **phead, Sltnode *pos, Sldatatype x);//在pos位置之前插入一个节点
void SlistInsertAfter(Sltnode **phead, Sltnode *pos, Sldatatype x);
void SlistEase(Sltnode **pphead, Sltnode *pos);
void SlistDestroy(Sltnode **pphead);
//单链表更多的是更复杂数据解构的子结构