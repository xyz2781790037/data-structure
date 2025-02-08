#include "Slist.h"

void SlistPrint(Sltnode *phead)
{
    Sltnode *cur = phead;
    while (cur != NULL)
    {
        printf("%d->", cur->data);
        cur = cur->next; // next是存储下一个data的地址的指针
    }
    printf("NULL\n");
}
Sltnode *Buylistnode(Sldatatype x)
{
    Sltnode *newnode = (Sltnode *)malloc(sizeof(Sltnode));
    if (newnode == NULL)
    {
        printf("malloc fail\n");
        exit(-1);
    }
    newnode->data = x;
    newnode->next = NULL;
    return newnode;
}
void SlistPushBack(Sltnode **pphead, Sldatatype x)
{

    if (*pphead == NULL)
    {
        Sltnode *newnode = Buylistnode(x);
        *pphead = newnode;
    }
    else
    {
        Sltnode *tail = *pphead;
        // 找到尾节点
        while (tail->next != NULL)
        {
            tail = tail->next;
        }
        Sltnode *newnode = (Sltnode *)malloc(sizeof(Sltnode)); // newnode是原最后一个节点，现在开辟内存；
        newnode->data = x;
        newnode->next = NULL;

        tail->next = newnode; // newnode->text是最后一个地址，NULL；
    }
}
void SlistPushFront(Sltnode **pphead, Sldatatype x)
{
    Sltnode *newnode = Buylistnode(x);
    newnode->next = *pphead;
    *pphead = newnode;
}
void SlistPopBack(Sltnode **pphead)
{
    if (*pphead == NULL)
    {
        return;
    }
    // assert(*pphead != NULL);
    // 暴力方法
    if ((*pphead)->next == NULL)
    {
        free(*pphead);
        *pphead = NULL;
    }
    else
    {
        Sltnode *prev = NULL;
        Sltnode *tail = *pphead;
        while (tail->next != NULL)
        {
            prev = tail;
            tail = tail->next;
        }
        free(tail);
        tail = NULL;
        prev->next = NULL;

        // 第二种表达方式
        //  Sltnode *tail = *pphead;
        //  while(tail->next->next)
        //  {
        //      tail = tail->next;
        //  }
        //  free(tail->next);
        //  tail->next = NULL;
    }
}
void SlistPopFront(Sltnode **pphead)
{
    if (*pphead == NULL)
    {
        return;
    }
    Sltnode *head = *pphead;
    head = head->next;
    *pphead = NULL; // 让本节点为空
    *pphead = head; // 指向下一个节点
}
Sltnode *SlistFind(Sltnode *phead, Sldatatype x)
{
    Sltnode *findnode = phead;
    while (findnode)
    {
        if (findnode->data == x)
        {
            return findnode;
        }
        else
        {
            findnode = findnode->next;
        }
    }
    return NULL;
}
void SlistInsert(Sltnode **pphead, Sltnode *pos, Sldatatype x)
{
    Sltnode *newnode = Buylistnode(x);
    if (*pphead != pos)
    {
        // 不能实现头插
        Sltnode *prev = *pphead;
        while (prev->next != pos)
        {
            prev = prev->next;
        }
        newnode->next = pos;
        prev->next = newnode;
    }
    else
    {
        newnode->next = *pphead;
        *pphead = newnode;
    }
}
void SlistEase(Sltnode **pphead, Sltnode *pos)
{
    
}