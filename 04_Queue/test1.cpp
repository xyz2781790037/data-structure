#include "queue.hpp"
void test1()
{
    ArrayQueue<int> aq;
    aq.enqueue(10);
    aq.enqueue(20);
    aq.enqueue(30);
    aq.enqueue(40);
    aq.enqueue(50);
    aq.enqueue(60);
    cout << "size is : " << aq.size() << endl;
    cout << "element is : " << aq.front() << endl;
    aq.dequeue();
    aq.dequeue();
    aq.dequeue();
    cout << "size is : " << aq.size() << endl;
    cout << "element is : " << aq.front() << endl;
    cout << "capacity is : " << aq.getCapacity() << endl;
    cout << "empty is " << aq.isEmpty() << endl;
    aq.clear();
    cout << "size is : " << aq.size() << endl;
    cout << "empty is " << aq.isEmpty() << endl;
    cout << "element is : " << aq.front() << endl;
}
void test2()
{
    ArrayQueue<int> aq;
    aq.enqueue(10);
    aq.enqueue(20);
    aq.enqueue(30);
    aq.enqueue(40);
    aq.enqueue(50);
    aq.enqueue(60);
    aq.dequeue();
    aq.print();
    ArrayQueue<int> aq2(aq);
    aq2.print();
    aq2.dequeue();
    aq2.print();
    cout << "size is : " << aq2.size() << endl;
    cout << "element is : " << aq2.front() << endl;
    ArrayQueue<int> aq3;
    aq3 = aq2;
    aq3.print();
    aq3.dequeue();
    aq3.print();
    cout << "size is : " << aq3.size() << endl;
    cout << "element is : " << aq3.front() << endl;
}
int main()
{
    //test1();
    test2();
    return 0;
}