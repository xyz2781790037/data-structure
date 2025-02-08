#include "Slist.h"

void TestSlist1()
{
    Sltnode *plist = NULL;
    SlistPushBack(&plist, 1);
    SlistPushBack(&plist, 2);
    SlistPushBack(&plist, 3);
    SlistPushBack(&plist, 4);

    SlistPrint(plist);

    SlistPushFront(&plist, 10);
    SlistPushFront(&plist, 20);
    SlistPushFront(&plist, 30);
    SlistPushFront(&plist, 40);

    SlistPrint(plist);
}
void TestSlist2()
{
    Sltnode *plist = NULL;
    SlistPushFront(&plist, 10);
    SlistPushFront(&plist, 20);
    SlistPushFront(&plist, 30);
    SlistPushFront(&plist, 40);
    SlistPushFront(&plist, 50);
    SlistPushFront(&plist, 60);
    SlistPushFront(&plist, 70);
    SlistPushFront(&plist, 80);
    SlistPrint(plist);

    SlistPopBack(&plist);
    SlistPopBack(&plist);
    SlistPopBack(&plist);
    SlistPopBack(&plist);
    SlistPopBack(&plist);
    SlistPrint(plist);

    SlistPopFront(&plist);
    SlistPopFront(&plist);
    SlistPopFront(&plist);
    SlistPopFront(&plist);
    SlistPrint(plist);
}
void TestSlist3()
{
    Sltnode *plist = NULL;
    SlistPushFront(&plist, 10);
    SlistPushFront(&plist, 20);
    SlistPushFront(&plist, 30);
    SlistPushFront(&plist, 40);
    SlistPushFront(&plist, 20);
    SlistPushFront(&plist, 20);
    SlistPrint(plist);

    // find
    Sltnode *pos = SlistFind(plist, 20);
    int i = 1;
    while (pos)
    {
        printf("第%d个pos节点:%p->%d\n", i++, pos, pos->data);
        pos = SlistFind(pos->next, 20);
    }
    // 修改作用
    Sltnode *posx = SlistFind(plist, 30);
    if (posx)
    {
        posx->data = 3;
    }
    SlistPrint(plist);
}
void TestSlist4()
{
    Sltnode *plist = NULL;
    SlistPushFront(&plist, 10);
    SlistPushFront(&plist, 20);
    SlistPushFront(&plist, 30);
    SlistPushFront(&plist, 40);
    SlistPushFront(&plist, 50);
    SlistPushFront(&plist, 60);
    SlistPrint(plist);

    Sltnode *pos = SlistFind(plist, 40);
    if (pos)
    {
        SlistInsert(&plist, pos, 4);
    }
    Sltnode *pos1 = SlistFind(plist, 60);
    if (pos1)
    {
        SlistInsert(&plist, pos1, 6);
    }
    SlistPrint(plist);
}
int main()
{
    // TestSlist1();
    // TestSlist2();
    // TestSlist3();
    TestSlist4();
    return 0;
}