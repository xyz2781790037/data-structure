#include "Seqlist.h"

void ceshi(sl *ps)
{
    for (int i = 0; i < ps->size; i++)
    {
        printf("%d ", ps->a[i]);
    }
    printf("\n");
}
void SeqlistDestory(sl *ps)
{
    free(ps->a);
    ps->a = NULL;
    ps->size = ps->capacity = 0;
}
void SeqlistInit(sl *ps)
{
    ps->a = NULL;
    ps->size = ps->capacity = 0;
}
void SeqlistPushBack(sl *ps, Sldatatype x)
{
    // if (ps->size == ps->capacity)
    // {
    //     int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
    //     Sldatatype *tmp = (Sldatatype *)realloc(ps->a, newcapacity * sizeof(Sldatatype));
    //     if (tmp == NULL)
    //     {
    //         printf("error");
    //         exit(-1);
    //     }
    //     ps->a = tmp;
    //     ps->capacity = newcapacity;
    // }
    // ps->a[ps->size] = x;
    // ps->size++;
    SeqlistInsert(ps, ps->size, x);
}
void SeqlistPopBack(sl *ps)
{
    // 温柔方式
    // if (ps->size > 0)
    // {
    //     // ps->a[ps->size - 1] = 0;//万一它数据本身是0；
    //     ps->size--;
    // }
    // 暴力方式
    //  assert(ps->size > 0);
    //  ps->size--;
    SeqlistErase(ps, ps->size - 1);
}
void SeqlistCheckCapacity(sl *ps)
{
    if (ps->size == ps->capacity)
    {
        int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
        Sldatatype *tmp = (Sldatatype *)realloc(ps->a, newcapacity * sizeof(Sldatatype));
        if (tmp == NULL)
        {
            printf("error");
            exit(-1);
        }
        ps->a = tmp;
        ps->capacity = newcapacity;
    }
}
void SeqlistPushFront(sl *ps, Sldatatype x)
{
    // SeqlistCheckCapacity(ps);
    // int end = ps->size - 1;
    // while (end >= 0)
    // {
    //     ps->a[end + 1] = ps->a[end];
    //     end--;
    // }
    // ps->a[0] = x;
    // ps->size++;
    // 第二种方式
    SeqlistInsert(ps, 0, x);
}
void SeqlistPopFront(sl *ps)
{
    // assert(ps->size > 0);
    // int begin = 1;
    // while (begin < ps->size)
    // {
    //     ps->a[begin - 1] = ps->a[begin];
    //     ++begin;
    // }
    // ps->size--;
    SeqlistErase(ps, 0);
}

int SeqlistFind(sl *ps, Sldatatype x)
{
    for (int i = 0; i < ps->size; i++)
    {
        if (x == ps->a[i])
        {
            return i;
        }
    }
    return -1;
}
void SeqlistInsert(sl *ps, int pos, Sldatatype x)
{
    if (pos > ps->size || pos < 0)
    {
        printf("error pos");
        return;
    }
    SeqlistCheckCapacity(ps);
    int end = ps->size - 1;
    while (end >= pos)
    {
        ps->a[end + 1] = ps->a[end];
        end--;
    }
    ps->a[pos] = x;
    ps->size++;
}
void SeqlistErase(sl *ps, int pos)
{
    if (pos < 0 || pos > ps->size - 1)
    {
        printf("error pos");
        return;
    }
    int begin = pos + 1;
    while (begin < ps->size)
    {
        ps->a[begin - 1] = ps->a[begin];
        ++begin;
    }
    ps->size--;
}
//缺陷：1,空间不够需要增容，增容要符出代码
//2.避免频繁扩容，我们满了基本扩大2倍，可能导致一定的空间浪费。
//3.顺序表要求数据从开始位置连续存储，那么我们在头部或者中间位置插入删除数据就需要挪动数据，效率不高。
//需要扩容：原地扩容，异地扩容；