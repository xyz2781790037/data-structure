#include <vector>
#include <list>
#include <stdexcept>
#include <functional> // 用于 std::hash
#include <iostream>
using namespace std;
template <typename K, typename V>
class HashMap
{
private:
    // 键值对节点
    struct KeyValuePair
    {
        K key;
        V value;
        KeyValuePair(const K &k, const V &v) : key(k), value(v) {}
    };

    // 哈希桶（链表实现）
    std::vector<std::list<KeyValuePair>> buckets;

    size_t elementCount; // 当前元素数量
    float maxLoadFactor; // 最大负载因子（默认0.75）

    // 私有方法
    size_t hashFunction(const K &key) const; // 哈希函数
    void rehash(size_t newCapacity);         // 重新哈希扩容

public:
    // 构造函数
    HashMap(size_t initialCapacity = 10, float loadFactor = 0.75f);

    // 基础操作
    void insert(const K &key, const V &value); // 插入键值对
    bool erase(const K &key);                  // 删除键值对
    bool contains(const K &key) const;         // 判断键是否存在
    V &operator[](const K &key);               // 通过键访问值（不存在则插入默认值）
    V &at(const K &key);                       // 安全访问值（不存在则抛异常）
    const V &at(const K &key) const;

    // 工具方法
    size_t size() const; // 元素数量
    bool empty() const;  // 是否为空
    void clear();        // 清空哈希表

    // 禁用拷贝（或实现深拷贝）
    HashMap(const HashMap &) = delete;
    HashMap &operator=(const HashMap &) = delete;
};