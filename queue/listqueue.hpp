#include <stdexcept> // 用于异常处理

template <typename T>
class LinkedListQueue
{
private:
    struct Node
    {
        T data;
        Node *next;
        Node(const T &val, Node *nxt = nullptr)
            : data(val), next(nxt) {}
    };

    Node *frontPtr;   // 队头指针（负责出队）
    Node *rearPtr;    // 队尾指针（负责入队）
    int elementCount; // 元素计数器

public:
    // 构造函数
    LinkedListQueue();

    // 析构函数
    ~LinkedListQueue();

    // 基础操作接口
    void enqueue(const T &value); // 入队（添加到队尾）
    void dequeue();               // 出队（从队头移除）
    T front() const;              // 获取队头元素
    T back() const;               // 获取队尾元素
    bool isEmpty() const;         // 判断队列是否为空
    int size() const;             // 获取元素数量

    // 进阶功能（可选实现）
    void clear();                                             // 清空队列
    LinkedListQueue(const LinkedListQueue &other);            // 拷贝构造函数
    LinkedListQueue &operator=(const LinkedListQueue &other); // 赋值运算符
};