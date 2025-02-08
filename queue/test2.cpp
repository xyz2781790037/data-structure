#include "listqueue.hpp"
void test1()
{
    LinkedListQueue<int> llq;
    llq.enqueue(10);
    llq.enqueue(20);
    llq.enqueue(30);
    llq.enqueue(40);
    llq.enqueue(50);
    llq.enqueue(60);
    cout << "size is : " << llq.size() << endl;
    cout << "element is : " << llq.front() << endl;
    llq.dequeue();
    llq.dequeue();
    llq.dequeue();
    cout << "size is : " << llq.size() << endl;
    cout << "element is : " << llq.front() << endl;
    cout << "empty is " << llq.isEmpty() << endl;
    llq.clear();
    cout << "size is : " << llq.size() << endl;
    cout << "empty is " << llq.isEmpty() << endl;
    cout << "element is : " << llq.front() << endl;
    cout << "-----------------" << endl;
}
void test2()
{
    LinkedListQueue<int> llq;
    llq.enqueue(10);
    llq.enqueue(20);
    llq.enqueue(30);
    llq.enqueue(40);
    llq.enqueue(50);
    llq.enqueue(60);
    llq.dequeue();
    LinkedListQueue<int> llq2(llq);
    llq2.dequeue();
    cout << "size is : " << llq2.size() << endl;
    cout << "element is : " << llq2.front() << endl;
    LinkedListQueue<int> llq3;
    llq3 = llq2;
    llq3.dequeue();
    cout << "size is : " << llq3.size() << endl;
    cout << "element is : " << llq3.front() << endl;
}
int main()
{
    test1();
    test2();
    return 0;
}