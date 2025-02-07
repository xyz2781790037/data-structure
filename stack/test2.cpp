#include "stacklist.hpp"
void test1()
{
    LinkedListStack<int> lls;
    lls.push(10);
    lls.push(20);
    lls.push(30);
    lls.push(40);
    lls.push(50);
    lls.push(60);
    cout << "lls size : " << lls.size() << endl;
    cout << "lls data : " << lls.top() << endl;
    lls.pop();
    lls.pop();
    cout << "lls size : " << lls.size() << endl;
    cout << "lls data : " << lls.top() << endl;
    cout << "------------" << endl;
    lls.pop();
    lls.pop();
    lls.pop();
    lls.pop();
    lls.pop();
    cout << "empty " << lls.isEmpty() << endl;
    cout << lls.top() << endl;
}
void test2()
{
    LinkedListStack<int> lls1;
    LinkedListStack<int> lls2;
    lls1.push(10);
    lls1.push(20);
    lls1.push(30);
    lls1.push(40);
    lls1.push(50);
    lls1.push(60);
    lls2 = lls1;
    cout << "lls size : " << lls2.size() << endl;
    cout << "lls data : " << lls2.top() << endl;
}
int main()
{
    test1();
    test2();
}