enum Color
{
    RED,
    BLACK
};

template <typename T>
struct RBTreeNode
{
    T key;
    Color color;
    RBTreeNode *left;
    RBTreeNode *right;
    RBTreeNode *parent;

    RBTreeNode(T k, Color c = RED,
               RBTreeNode *l = nullptr,
               RBTreeNode *r = nullptr,
               RBTreeNode *p = nullptr)
        : key(k), color(c), left(l), right(r), parent(p) {}
};

template <typename T>
class RedBlackTree
{
private:
    RBTreeNode<T> *root;
    RBTreeNode<T> *nil; // 哨兵节点

    // 内部工具函数
    void leftRotate(RBTreeNode<T> *x);
    void rightRotate(RBTreeNode<T> *y);
    void insertFixup(RBTreeNode<T> *z);
    void deleteFixup(RBTreeNode<T> *x);
    void transplant(RBTreeNode<T> *u, RBTreeNode<T> *v);
    RBTreeNode<T> *minimum(RBTreeNode<T> *node);

public:
    RedBlackTree()
    {
        nil = new RBTreeNode<T>(T(), BLACK);
        root = nil;
    }

    ~RedBlackTree()
    {
        // 需要实现销毁树的逻辑
    }

    // 基本操作接口
    void insert(const T &key);
    void remove(const T &key);
    RBTreeNode<T> *search(const T &key) const;
    void printInOrder() const;
};
