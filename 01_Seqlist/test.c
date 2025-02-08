#include "Seqlist.h"

void TestSeqlist1()
{
    sl Sl;
    SeqlistInit(&Sl);
    SeqlistPushBack(&Sl, 1);
    SeqlistPushBack(&Sl, 2);
    SeqlistPushBack(&Sl, 3);
    SeqlistPushBack(&Sl, 4);
    SeqlistPushBack(&Sl, 5);

    SeqlistPopBack(&Sl);
    SeqlistPopBack(&Sl);
    SeqlistPopBack(&Sl);
    SeqlistPopBack(&Sl);
    // 不要越界
    ceshi(&Sl);
    SeqlistDestory(&Sl);
}
void TestSeqlist2()
{
    sl Sl;
    SeqlistInit(&Sl);
    SeqlistPushBack(&Sl, 1);
    SeqlistPushBack(&Sl, 2);
    SeqlistPushBack(&Sl, 3);
    SeqlistPushBack(&Sl, 4);
    SeqlistPushBack(&Sl, 5);

    SeqlistPushFront(&Sl, 10);
    SeqlistPushFront(&Sl, 30);
    SeqlistPushFront(&Sl, 50);

    SeqlistPopFront(&Sl);
    SeqlistPopFront(&Sl);
    ceshi(&Sl);
    SeqlistDestory(&Sl);
}
void TestSeqlist3()
{
    sl Sl;
    SeqlistInit(&Sl);
    SeqlistPushBack(&Sl, 1);
    SeqlistPushBack(&Sl, 2);
    SeqlistPushBack(&Sl, 3);
    SeqlistPushBack(&Sl, 4);
    SeqlistPushBack(&Sl, 5);
    ceshi(&Sl);

    SeqlistPushFront(&Sl, 1);
    SeqlistPushFront(&Sl, 2);
    SeqlistPushFront(&Sl, 3);
    SeqlistPushFront(&Sl, 4);
    ceshi(&Sl);

    SeqlistErase(&Sl, 1);
    ceshi(&Sl);
    SeqlistPopBack(&Sl);
    SeqlistPopFront(&Sl);

    int pos = SeqlistFind(&Sl, 3);
    if(pos != -1)
    {
        SeqlistErase(&Sl, pos);
    }
    ceshi(&Sl);
    SeqlistDestory(&Sl);
}

int main()
{
    // TestSeqlist1();
    // TestSeqlist2();
    TestSeqlist3();
    return 0;
}