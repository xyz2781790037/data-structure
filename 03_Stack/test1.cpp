#include "stack.hpp"
void test1()
{
    Stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    cout << "size = " << st.size() << endl;
    cout << "top  = " << st.top() << endl;
    st.pop();
    cout << "size = " << st.size() << endl;
    cout << "top  = " << st.top() << endl;
    st.pop();
    st.pop();
    st.pop();
    cout << "now capacity = " << st.getCapacity() << endl;
    st.pop();
    cout << st.isEmpty();
}
void test2()
{
    Stack<int> st1;
    st1.push(10);
    st1.push(20);
    st1.push(30);
    st1.push(40);
    cout << "size = " << st1.size() << endl;
    cout << "top  = " << st1.top() << endl;
    Stack<int> st2;
    st2 = st1;
    cout << "size = " << st2.size() << endl;
    cout << "top  = " << st2.top() << endl;
}
int main()
{
    test1();
    test2();
}