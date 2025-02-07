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
int main()
{
    test1();
}