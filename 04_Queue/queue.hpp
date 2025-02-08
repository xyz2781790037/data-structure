#include <stdexcept> // 用于异常处理
#include <iostream>
using namespace std;
template <typename T>
class ArrayQueue
{
private:
    T *data;        // 存储元素的数组指针
    int capacity;   // 队列的当前容量
    int frontIndex; // 队首元素的索引
    int rearIndex;  // 队尾下一个可插入位置的索引
    int count;      // 当前元素数量

    // 私有方法：动态调整数组容量
    void resize(int newCapacity)
    {
        T *tmp = new T[newCapacity];
        for (int i = 0; i < count; i++)
        {
            tmp[i] = data[(frontIndex + i) % capacity];
        }
        capacity = newCapacity;
        delete[] data;
        data = tmp;
        frontIndex = 0;
        rearIndex = count;
    }

public:
    // 构造函数
    ArrayQueue(int initialCapacity = 10)
    {
        data = new T[initialCapacity];
        this->capacity = initialCapacity;
        frontIndex = rearIndex = 0;
        count = 0;
    }

    // 析构函数
    ~ArrayQueue()
    {
        delete[] data;
    }

    // 基础操作
    // 入队
    void enqueue(const T &element)
    {
        if (count == capacity)
        {
            resize(2 * capacity);
        }
        count++;
        data[rearIndex] = element;
        rearIndex = (rearIndex + 1) % capacity; // 保证 rearIndex 在有效范围内
    }
    // 出队
    T dequeue()
    {
        if (isEmpty())
        {
            throw out_of_range("queue is emtpy,dequeue is error");
        }
        T tmp = data[frontIndex];
        count--;
        frontIndex = (frontIndex + 1) % capacity; // 保证 frontIndex 在有效范围内
        return tmp;
    }
    // 查看队首元素
    T front() const
    {
        if (isEmpty())
        {
            throw out_of_range("queue is emtpy,front is error");
        }
        return data[frontIndex];
    }
    bool isEmpty() const
    {
        return count == 0;
    }
    int size() const
    {
        return count;
    }

    // 高级操作（可选）
    void clear()
    {
        delete[] data;
        data = new T[capacity]; // 重新分配原始大小的内存
        frontIndex = rearIndex = 0;
        count = 0;
    }
    // 获取当前容量
    int getCapacity() const
    {
        return capacity;
    }
    void print()
    {
        for (int i = frontIndex; i < rearIndex;i++)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }
    // 禁用拷贝和赋值（或实现深拷贝）
    ArrayQueue(const ArrayQueue &other)
    {
        this->frontIndex = other.frontIndex;
        this->rearIndex = other.rearIndex;
        this->count = other.count;
        this->data = new T[other.capacity];
        for (int i = this->frontIndex; i < (this->frontIndex + count); i++)
        {
            i %= other.capacity;
            this->data[i] = other.data[i];
        }
        this->capacity = other.capacity;
    }
    ArrayQueue &operator=(const ArrayQueue &other)
    {
        if (this != &other)
        {
            delete[] this->data;
            this->frontIndex = other.frontIndex;
            this->rearIndex = other.rearIndex;
            this->count = other.count;
            this->data = new T[other.capacity];
            for (int i = this->frontIndex; i < (this->frontIndex + count); i++)
            {
                i %= other.capacity;
                this->data[i] = other.data[i];
            }
            this->capacity = other.capacity;
        }
        return *this;
    }
};