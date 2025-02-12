template <typename T>
class BSTNode
{
public:
    T data;
    BSTNode<T> *left;
    BSTNode<T> *right;
    explicit BSTNode(T val) : data(val), left(nullptr), right(nullptr) {}
};

template <typename T>
class BinarySearchTree
{
private:
    BSTNode<T> *root;

    // 辅助函数（推荐使用递归）
    BSTNode<T> *insertHelper(BSTNode<T> *node, T value);
    BSTNode<T> *removeHelper(BSTNode<T> *node, T value);
    BSTNode<T> *findMinNode(BSTNode<T> *node); // 找子树最小节点

public:
    BinarySearchTree() : root(nullptr) {}
    // 析构函数需要释放内存
    ~BinarySearchTree()
    {
        clear()
    }

    // 基本操作
    void insert(T value);   // 插入新值
    void remove(T value);   // 删除值（需处理三种情况）
    bool contains(T value); // 是否包含值

    // 遍历
    void traverseInOrder(); // 中序遍历（结果有序）
    void traversePreOrder();
    void traversePostOrder();
    void traverseLevelOrder(); // 层序遍历

    // 工具函数
    T findMin();  // 最小值（最左节点）
    T findMax();  // 最大值（最右节点）
    int height(); // 树的高度
    int size();   // 节点总数
    bool isEmpty();
};