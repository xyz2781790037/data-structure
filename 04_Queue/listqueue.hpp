#include <stdexcept> // 用于异常处理
#include <iostream>
using namespace std;
template <typename T>
class LinkedListQueue
{
private:
    typedef struct Node
    {
        T data;
        Node *next;
        Node(const T &val, Node *nxt = nullptr) : data(val), next(nxt) {}
    } sn;

    Node *frontPtr;   // 队头指针（负责出队）
    Node *rearPtr;    // 队尾指针（负责入队）
    int elementCount; // 元素计数器

public:
    // 构造函数
    LinkedListQueue()
    {
        frontPtr = nullptr;
        rearPtr = nullptr;
        elementCount = 0;
    }

    // 析构函数
    ~LinkedListQueue()
    {
        while (frontPtr != nullptr)
        {
            sn *cur = frontPtr;
            frontPtr = frontPtr->next;
            delete cur;
        }
    }

    // 基础操作接口
    // 入队（添加到队尾）
    void enqueue(const T &value)
    {
        sn *newnode = new Node(value);
        if (isEmpty())
        {
            frontPtr = newnode;
            rearPtr = newnode;
        }
        else
        {
            rearPtr->next = newnode;
            rearPtr = rearPtr->next;
        }
        elementCount++;
    }
    // 出队（从队头移除）
    void dequeue()
    {
        if(isEmpty())
        {
            cout << "dequeue is error" << endl;
            return;
        }
        sn *tmp = frontPtr;
        frontPtr = frontPtr->next;
        delete tmp;
        elementCount--;
    }
    // 获取队头元素
    T front() const
    {
        if (isEmpty())
        {
            return -1;
        }
        return frontPtr->data;
    }
    // 获取队尾元素
    T back() const
    {
        if (isEmpty())
        {
            return -1;
        }
        return rearPtr->data;
    }
    bool isEmpty() const
    {
        return elementCount == 0;
    }
    // 获取元素数量
    int size() const
    {
        return elementCount;
    }

    // 进阶功能（可选实现）// 清空队列
    void clear()
    {
        while (frontPtr != nullptr)
        {
            sn *cur = frontPtr;
            frontPtr = frontPtr->next;
            delete cur;
        }
        elementCount = 0;
    }
    // 拷贝构造函数
    LinkedListQueue(const LinkedListQueue &other)
    {
        frontPtr = nullptr;
        rearPtr = nullptr;
        this->elementCount = 0;
        sn *cur = other.frontPtr;
        while (cur != nullptr)
        {
            this->enqueue(cur->data);
            cur = cur->next;
        }
    }
    // 赋值运算符
    LinkedListQueue &operator=(const LinkedListQueue &other)
    {
        if (this != &other)
        {
            this->clear();
            this->elementCount = 0;
            sn *cur = other.frontPtr;
            this->frontPtr = nullptr;
            this->rearPtr = nullptr;
            while (cur != nullptr)
            {
                this->enqueue(cur->data);
                cur = cur->next;
            }
        }
        return *this;
    }
};