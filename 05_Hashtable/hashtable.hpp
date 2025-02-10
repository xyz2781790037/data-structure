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
        Node(const K &k, const V &v, Node *n = nullptr): key(k), value(v), next(n) {}
    }sn;

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
        for (int i = 0; i < bucketSize;i++)
        {
            sn *cur = buckets[i];
            while(cur)
            {
                
            }
        }
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
        if(elementCount / bucketSize > maxLoadFactor)
        {
            rehash(bucketSize * 2);
        }
    }
    // 删除
    bool remove(const K &key)
    {

    }
    bool contains(const K &key) const;         // 存在性检查
    V *get(const K &key);                      // 获取值指针（不存在返回nullptr）
    const V *get(const K &key) const;

    // 工具方法
    size_t size() const { return elementCount; }
    bool empty() const { return elementCount == 0; }
    void clear();

    // 禁用拷贝（或手动实现深拷贝）
    HashMap(const HashMap &) = delete;
    HashMap &operator=(const HashMap &) = delete;
};