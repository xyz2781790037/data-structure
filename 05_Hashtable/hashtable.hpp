#include <stdexcept>
#include <iostream>
#include <functional> // 用于哈希函数
using namespace std;
template <typename K, typename V>
class HashMap
{
private:
    // 链表节点定义
    typedef struct Node
    {
        K key;
        V value;
        Node *next;
        Node(const K &k, const V &v, Node *n = nullptr) : key(k), value(v), next(n) {}
    } sn;

    // 哈希桶动态数组
    Node **buckets;      // 桶数组（指针数组）
    size_t bucketSize;   // 当前桶数量
    size_t elementCount; // 元素总数
    float maxLoadFactor; // 最大负载因子（默认0.75）

    // 私有方法
    size_t hashFunction(const K &key) const
    {
        return key % bucketSize;
    }
    void rehash(size_t newBucketSize)
    {
        sn **newbuckets = new sn *[newBucketSize]();
        size_t bsize = bucketSize;
        bucketSize = newBucketSize;
        for (int i = 0; i < bsize; i++)
        {
            sn *cur = buckets[i];
            while (cur)
            {
                size_t newkey = hashFunction(cur->key);
                sn *tmp = cur->next;
                cur->next = newbuckets[newkey];
                newbuckets[newkey] = cur;
                cur = tmp;
            }
            buckets[i] = nullptr;
        }
        delete[] buckets;
        buckets = newbuckets;
    }
public:
    // 构造函数
    explicit HashMap(size_t initialBucketSize = 10, float loadFactor = 0.75f)
    {
        maxLoadFactor = loadFactor;
        elementCount = 0;
        bucketSize = initialBucketSize;
        buckets = new sn *[bucketSize](); // () 保证初始化为nullptr
    }

    // 析构函数
    ~HashMap()
    {
        clear();
        delete[] buckets;
    }

    // 基础操作
    void insert(const K &key, const V &value)
    {
        if (((float)elementCount + 1) / bucketSize > maxLoadFactor)
        {
            rehash(bucketSize * 2);
        }
        size_t index = hashFunction(key);
        Node *curr = buckets[index];

        // 遍历链表查找键是否存在
        while (curr)
        {
            if (curr->key == key)
            {
                curr->value = value; // 更新值
                return;
            }
            curr = curr->next;
        }
        buckets[index] = new Node(key, value,buckets[index]);
        elementCount++;
    }
    // 删除
    bool remove(const K &key)
    {
        size_t index = hashFunction(key);
        Node *curr = buckets[index];
        Node *prev = nullptr;

        while (curr)
        {
            if (curr->key == key)
            {
                if (prev)
                {
                    prev->next = curr->next; // 中间节点
                }
                else
                {
                    buckets[index] = curr->next; // 头节点
                }
                delete curr;
                elementCount--;
                return true;
            }
            prev = curr;
            curr = curr->next;
        }
        return false;
    }
    // 存在性检查
    bool contains(const K &key) const
    {
        size_t index = hashFunction(key);
        sn *cur = buckets[index];
        while (cur)
        {
            if (cur->key == key)
            {
                return true;
            }
            cur = cur->next;
        }
        return false;
    }
    // 获取值指针（不存在返回nullptr）
    V *get(const K &key)
    {
        size_t index = hashFunction(key);
        sn *cur = buckets[index];
        while (cur)
        {
            if (cur->key == key)
                return &cur->value;
            cur = cur->next;
        }
        return nullptr; // 键不存在
    }

    // 工具方法
    size_t size() const { return elementCount; }
    bool empty() const { return elementCount == 0; }
    void clear()
    {
        for (int i = 0; i < bucketSize; i++)
        {
            sn *cur = buckets[i];
            while (cur)
            {
                sn *tmp = cur;
                cur = cur->next;
                delete tmp;
            }
            buckets[i] = nullptr;
        }
        elementCount = 0;
    }
    // 手动实现深拷贝
    HashMap(const HashMap &other)
    {
        bucketSize = other.bucketSize;
        elementCount = 0;
        maxLoadFactor = other.maxLoadFactor;
        buckets = new sn *[bucketSize]();
        for (size_t i = 0; i < other.bucketSize; i++)
        {
            sn *cur = other.buckets[i];
            sn *last = nullptr;

            // 遍历 'other' map 当前桶的链表
            while (cur)
            {
                sn *newNode = new sn(cur->key, cur->value);

                if (last)
                {
                    last->next = newNode; // 将前一个节点的 next 指向新的节点
                }
                else
                {
                    buckets[i] = newNode; // 该桶的第一个节点
                }

                last = newNode;  // 更新 last 指向新节点
                cur = cur->next; // 继续遍历下一个节点
                elementCount++;  // 更新元素数量
            }
        }
    }
    HashMap &operator=(const HashMap &other)
    {
        if(this == &other)
        {
            return *this;
        }
        this->clear();
        delete[] buckets;
        bucketSize = other.bucketSize;
        elementCount = other.elementCount;
        maxLoadFactor = other.maxLoadFactor;
        buckets = new sn *[bucketSize]();
        for (size_t i = 0; i < bucketSize;i++)
        {
            sn *cur = other.buckets[i];
            sn *last = nullptr;
            while(cur)
            {
                sn *newnode = new sn(cur->key, cur->value);
                if(last)
                {
                    last->next = newnode;
                }
                else
                {
                    buckets[i] = newnode;
                }
                last = newnode;
                cur = cur->next;
            }
        }
        return *this;
    }
};