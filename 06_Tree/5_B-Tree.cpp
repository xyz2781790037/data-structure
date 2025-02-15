template <typename T>
struct BTreeNode
{
    bool is_leaf;
    int n;                // 当前关键字数量
    T *keys;              // 关键字数组
    BTreeNode **children; // 子节点指针数组

    BTreeNode(int t, bool leaf) : is_leaf(leaf), n(0)
    {
        keys = new T[2 * t - 1];
        children = new BTreeNode *[2 * t];
    }

    ~BTreeNode()
    {
        delete[] keys;
        delete[] children;
    }
};

template <typename T>
class BTree
{
private:
    BTreeNode<T> *root;
    int degree; // 最小度数 (m)

    // 内部工具函数
    void splitChild(BTreeNode<T> *parent, int i);
    void insertNonFull(BTreeNode<T> *node, const T &key);
    void deleteKey(BTreeNode<T> *node, const T &key);
    void merge(BTreeNode<T> *node, int i);
    void borrowFromPrev(BTreeNode<T> *node, int i);
    void borrowFromNext(BTreeNode<T> *node, int i);
    void fill(BTreeNode<T> *node, int i);

public:
    BTree(int t) : root(nullptr), degree(t) {}
    ~BTree()
    {
        // 需要实现销毁树的逻辑
    }

    // 基本操作接口
    void insert(const T &key);
    void remove(const T &key);
    bool search(const T &key) const;
    void print() const;
};