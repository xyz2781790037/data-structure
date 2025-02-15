template <typename T>
struct AVLNode
{
    T key;
    AVLNode *left;
    AVLNode *right;
    int height; // 节点高度

    AVLNode(T k) : key(k), left(nullptr), right(nullptr), height(1) {}
};
template <typename T>
class AVLTree
{
private:
    AVLNode<T> *root;

    // 基本辅助函数
    // 获取节点高度
    int height(AVLNode<T> *node)
    {
        return node ? node->height : 0;
    }
    // 计算平衡因子
    int balanceFactor(AVLNode<T> *node)
    {
        int high1 = height(node->left);
        int high2 = height(node->right);
        return high1 - high2;
    }
    // 更新节点高度
    void updateHeight(AVLNode<T> *node)
    {
        node->height = 1 + std::max(height(node->left), height(node->right));
    }

    // 旋转操作
    // 右旋
    AVLNode<T> *rightRotate(AVLNode<T> *y)
    {
        AVLNode<T> *tmp = nullptr;
        tmp = y->left->right;
        AVLNode<T> *tmp2 = y->left;
        y->left = nullptr;
        tmp2->right = y;
        y = tmp2;
        y->right->left = tmp;
        return y;
    }
    // 左旋
    AVLNode<T> *leftRotate(AVLNode<T> *x)
    {
        AVLNode<T> *tmp = nullptr;
        tmp = x->right->left;
        AVLNode<T> *tmp2 = x->right;
        x->right = nullptr;
        tmp2->left = x;
        x = tmp2;
        x->left->right = tmp;
        return x;
    }
    // 重新平衡节点
    AVLNode<T> *rebalance(AVLNode<T> *node)
    {
        if (balanceFactor(node) == 2)
        {
            if (balanceFactor(node->left) == 1)
            {
                node = rightRotate(node);
            }
            else
            {
                node->left = leftRotate(node->left);
                node = rightRotate(node);
            }
        }
        else if (balanceFactor(node) == -2)
        {
            if (balanceFactor(node->right) == -1)
            {
                node = leftRotate(node);
            }
            else
            {
                node->right = rightRotate(node->right);
                node = leftRotate(node);
            }
        }
        return node;
    }

    // 插入/删除辅助函数
    AVLNode<T> *insertHelper(AVLNode<T> *node, T key)
    {
        if (node == nullptr)
        {
            return new AVLNode(key);
        }
        else if (node->key > value)
        {
            node->left = insertHelper(node->left, key);
        }
        else
        {
            node->right = insertHelper(node->right, key);
        }
    }
    // 找子树最小节点
    AVLNode<T> *findMinNode(AVLNode<T> *node)
    {
        if (!node->left)
        {
            return node;
        }
        else
        {
            return findMinNode(node->left);
        }
    }
    AVLNode<T> *deleteHelper(AVLNode<T> *node, T key)
    {
        if (node->key == key)
        {
            if(!node->left && !node->right)
            {
                delete node;
                return nullptr;
            }
            else if (!node->left || !node->right)
            {
                AVLNode<T> *son = node->left ? node->left : node->right;
                delete node;
                return son;
            }
            else
            {
                BSTNode<T> *instead = findMinNode(node->right);
            }
        }
        else if(node->key > key)
        {
            node->left = deleteHelper(node->left, key);
        }
        else
        {
            node->right = deleteHelper(node->right, key);
        }
    }
    // 内存管理
    void clear(AVLNode<T> *node)
    {
        if(node ==nullptr)
        {
            return;
        }
        clear(node->right);
        clear(node->left);
        delete node;
    }
    AVLNode<T>* containsHelp(AVLNode<T>* node,T& key)
    {
        if(node == nullptr)
        {
            return nullptr;
        }
        if(node->key == key)
        {
            return node;
        }
        else if(node->key > key)
        {
            return containsHelp(node->left, key);
        }
        else
        {
            return containsHelp(node->right, key);
        }
    }

public:
    AVLTree() : root(nullptr) {}
    ~AVLTree() { clear(root); }

    // 对外接口
    // 插入键
    void insert(T key)
    {
        root = insertHelper(root, key);
        root = balanceFactor(root);
    }
    // 删除键
    void remove(T key)
    {
        root = deleteHelper(root, key);
    }
    // 查找键是否存在
    bool contains(T key)
    {
        return containsHelp(root,key) != nullptr
    }
    // 中序遍历打印（测试用）
    void printInOrder(AVLNode<T> *node = root)
    {
        if(node == nullptr)
        {
            return;
        }
        printInOrder(node->left);
        cout << node->key << " ";
        printInOrder(node->right);
    }
    void printTree();     // 可选：可视化打印树结构（较复杂）
};