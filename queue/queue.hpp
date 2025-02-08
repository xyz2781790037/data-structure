#include <stdexcept> // 用于异常处理

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
    void resize(int newCapacity);

public:
    // 构造函数
    ArrayQueue(int initialCapacity = 10); // 默认初始容量为10

    // 析构函数
    ~ArrayQueue();

    // 基础操作
    void enqueue(const T &element); // 入队
    T dequeue();                    // 出队
    T front() const;                // 查看队首元素
    bool isEmpty() const;           // 判断队列是否为空
    int size() const;               // 获取元素数量

    // 高级操作（可选）
    void clear();            // 清空队列
    int getCapacity() const; // 获取当前容量

    // 禁用拷贝和赋值（或实现深拷贝）
    ArrayQueue(const ArrayQueue &) = delete;
    ArrayQueue &operator=(const ArrayQueue &) = delete;
};