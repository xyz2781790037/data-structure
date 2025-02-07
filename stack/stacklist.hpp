#include <stdexcept> // 用于异常处理
#include <iostream>
using namespace std;
template <typename T>
class LinkedListStack
{
private:
    typedef struct Node
    {
        T data;
        Node *next;
        Node(const T &val, Node *nxt = nullptr) : data(val), next(nxt) {}
    }sn;

    Node *topNode;    // 栈顶节点指针
    int elementCount; // 元素计数器

public:
    // 构造函数
    LinkedListStack()
    {
        topNode = nullptr;
        elementCount = 0;
    }

    // 析构函数
    ~LinkedListStack()
    {
        while (topNode != nullptr)
        {
            Node *temp = topNode;
            topNode = topNode->next;
            delete temp;
        }
    }
    // 基础操作接口
    void push(const T &value)
    {
        sn*newnode = new Node(value,topNode);
        this->topNode = newnode;
        elementCount++;
    }
    void pop()
    {
        if(topNode == nullptr)
        {
            cout << "pop error!" << endl;
            return;
        }
        sn *cur = topNode;
        topNode = topNode->next;
        delete cur;
        elementCount--;
    }
    // 获取栈顶元素
    T top() const
    {
        if (topNode == nullptr)
        {
            cout << "top error!" << endl;
            return -1;
        }
        return topNode->data;
    }
    bool isEmpty() const
    {
        return elementCount == 0;
    }
    int size() const
    {
        return elementCount;
    }

    // 进阶功能（可选实现）
    // 清空栈
    void clear()
    {
        while(topNode != nullptr)
        {
            sn *tmp = topNode;
            topNode = topNode->next;
            delete tmp;
        }
        elementCount = 0;
    }
    // 拷贝构造函数
    LinkedListStack(const LinkedListStack &other)
    {
        topNode = nullptr;
        elementCount = 0;
        sn *cur = other.topNode;
        while(cur != nullptr)
        {
            this->push(cur->data);
            cur = cur->next;
        }
    }
    // 赋值运算符
    LinkedListStack &operator=(const LinkedListStack &other)
    {
        if(this != &other)
        {
            this->clear();
            this->elementCount = 0;
            sn *cur = other.topNode;
            while(cur != nullptr)
            {
                this->push(cur->data);
                cur = cur->next;
            }
        }
        return *this;
    }
};