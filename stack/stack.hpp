#include <stdexcept> // 用于异常处理
#include <iostream>
using namespace std;
template <typename T>
class Stack
{
private:
    T *data;      // 存储元素的数组
    int topIndex; // 栈顶指针（当前栈顶元素索引）
    int capacity; // 当前栈的最大容量
    // 辅助函数：调整栈容量（可选实现）
    void resize(int newCapacity)
    {
        this->capacity = newCapacity;
        T *newdata = new T[this->capacity];
        for (int i = 0; i < topIndex; i++)
        {
            newdata[i] = data[i];
        }
        delete[] data;
        data = newdata;
    }

public:
    // 1. 构造函数
    Stack(int initialCapacity = 10)
    {
        topIndex = -1;
        this->capacity = initialCapacity;
        data = new T[this->capacity];
    }
    // 2. 析构函数
    ~Stack()
    {
        delete[] data;
    }

    // 3. 入栈操作
    void push(const T &element)
    {
        if (topIndex == capacity - 1)
        {
            resize(capacity * 2);
        }
        data[++topIndex] = element;
    }

    // 4. 出栈操作
    void pop()
    {
        if (topIndex >= 0)
        {
            topIndex--;
        }
    }

    // 5. 获取栈顶元素
    T &top()
    {
        return data[topIndex];
    }

    // 6. 检查栈是否为空
    bool isEmpty() const
    {
        return topIndex == -1;
    }

    // 7. 获取元素数量
    int size() const
    {
        return topIndex + 1;
    }

    // 可选：获取当前容量
    int getCapacity() const
    {
        return capacity;
    }

    // 可选：防止拷贝构造和赋值
    Stack(const Stack &other)
    {
        this->capacity = other.capacity;
        this->data = new T[this->capacity];
        this->topIndex = other.topIndex;
        for (int i = 0; i <= this->topIndex;i++)
        {
            this->data[i] = other.data[i];
        }
    }
    Stack &operator=(const Stack &other)
    {
        if (this != &other)
        {
            // 先分配新的内存
            T *newData = new T[other.capacity];

            // 复制栈中的元素
            for (int i = 0; i <= other.topIndex; ++i)
            {
                newData[i] = other.data[i];
            }

            // 释放当前对象的数据
            delete[] this->data;

            // 更新当前对象的成员变量
            this->data = newData;
            this->capacity = other.capacity;
            this->topIndex = other.topIndex;
        }
        return *this; // 返回当前对象的引用
        
    }
};