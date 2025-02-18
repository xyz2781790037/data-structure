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

    RBTreeNode(T k, Color c = RED, RBTreeNode *l = nullptr, RBTreeNode *r = nullptr, RBTreeNode *p = nullptr) : key(k), color(c), left(l), right(r), parent(p) {}
};
template <typename T>
class RedBlackTree
{
private:
    RBTreeNode<T> *root;
    RBTreeNode<T> *nil;

    // 内部工具函数
    void leftRotate(RBTreeNode<T> *x)
    {
        RBTreeNode<T> *tmp = nullptr;
        tmp = x->right->left;
        RBTreeNode<T> *tmp2 = x->right;
        x->right = nullptr;
        tmp2->left = x;
        x = tmp2;
        x->left->right = tmp;
    }
    void rightRotate(RBTreeNode<T> *y)
    {
        RBTreeNode<T> *tmp = nullptr;
        tmp = x->right->left;
        RBTreeNode<T> *tmp2 = x->right;
        x->right = nullptr;
        tmp2->left = x;
        x = tmp2;
        x->left->right = tmp;
    }
    // 插入修复操作
    void insertFixup(RBTreeNode<T> *z)
    {
        while(z != root && z->parent->color == RED)
        {
            if()
            {

            }
        }
        root->color = BLACK;
    }
    // 删除修复操作
    void deleteFixup(RBTreeNode<T> *x);
    void transplant(RBTreeNode<T> *u, RBTreeNode<T> *v);
    RBTreeNode<T> *insertHelper(RBTreeNode<T> *node, T key)
    {
        if(node == nullptr)
        {
            RBTreeNode<T> *node2 = new RBTreeNode(key);
            insertFixup(node2);
            return node2;
        }
        if(node->key > key)
        {
            node->parent = node;
            return insertHelper(node->left, key);
        }
        else if(node->key < key)
        {
            node->parent = node;
            return insertHelper(node->right, key);
        }
        else
        {
            return node;
        }
    }

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
    void insert(const T &key)
    {
        root = insertHelper(root, key);
    }
    void remove(const T &key);
    RBTreeNode<T> *search(const T &key) const;
    void printInOrder() const;
    RBTreeNode<T> *minimum(RBTreeNode<T> *node);
};