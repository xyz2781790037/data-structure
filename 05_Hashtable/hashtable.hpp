#include <stdexcept>
#include <functional> // 用于哈希函数

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
        sn **newbuckets = new sn *[newBucketSize];
        bucketSize = newBucketSize;
        for (int i = 0; i < bucketSize; i++)
        {
            sn *cur = buckets[i];
            while (cur)
            {
                size_t newkey = hashFunction(cur->key);
                newbuckets[newkey] = new sn(cur->key, cur->next);
                sn *tmp = cur;
                cur = cur->next;
                delete tmp;
            }
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
        buckets = new sn *[bucketSize];
    }

    // 析构函数
    ~HashMap();

    // 基础操作
    void insert(const K &key, const V &value)
    {
        size_t index = hashFunction(key);
        elementCount++;
        sn *newnode = new Node(key, value);
        newnode->next = buckets[index];
        buckets[index] = newnode;
        if ((float)elementCount / bucketSize > maxLoadFactor)
        {
            rehash(bucketSize * 2);
        }
    }
    // 删除
    bool remove(const K &key)
    {
        size_t index = hashFunction(key);
        elementCount--;
        delete buckets[index];
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

    const V *get(const K &key) const;

    // 工具方法
    size_t size() const { return elementCount; }
    bool empty() const { return elementCount == 0; }
    void clear();

    // 禁用拷贝（或手动实现深拷贝）
    HashMap(const HashMap &) = delete;
    HashMap &operator=(const HashMap &) = delete;
};