#include <iostream>
#include <algorithm>
using namespace std;
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
        if (!node)
            return 0;
        int high1 = height(node->left);
        int high2 = height(node->right);
        return high1 - high2;
    }
    // 更新节点高度
    void updateHeight(AVLNode<T> *node)
    {
        if (node)
        {
            node->height = 1 + std::max(height(node->left), height(node->right));
        }
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
        if (!node)
            return node;

        int bf = balanceFactor(node);

        // 左子树高
        if (bf > 1)
        {
            if (balanceFactor(node->left) >= 0)
            { // LL
                return rightRotate(node);
            }
            else
            { // LR
                node->left = leftRotate(node->left);
                return rightRotate(node);
            }
        }

        // 右子树高
        if (bf < -1)
        {
            if (balanceFactor(node->right) <= 0)
            { // RR
                return leftRotate(node);
            }
            else
            { // RL
                node->right = rightRotate(node->right);
                return leftRotate(node);
            }
        }
        return node;
    }

    // 插入/删除辅助函数
    AVLNode<T> *insertHelper(AVLNode<T> *node, T key)
    {
        if (node == nullptr)
        {
            return new AVLNode<T>(key);
        }
        if (node->key > key)
        {
            node->left = insertHelper(node->left, key);
        }
        else if (node->key < key)
        {
            node->right = insertHelper(node->right, key);
        }
        else
        {
            return node;
        }
        updateHeight(node);
        return rebalance(node);
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
        if (!node)
            return nullptr;
        if (node->key == key)
        {
            if (!node->left && !node->right)
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
                AVLNode<T> *temp = findMinNode(node->right);
                node->key = temp->key;
                node->right = deleteHelper(node->right, temp->key);
            }
        }
        else if (node->key > key)
        {
            node->left = deleteHelper(node->left, key);
        }
        else
        {
            node->right = deleteHelper(node->right, key);
        }
        if (!node)
        {
            return nullptr;
        }
        updateHeight(node);
        return rebalance(node);
    }
    // 内存管理
    void clear(AVLNode<T> *node)
    {
        if (node == nullptr)
        {
            return;
        }
        clear(node->right);
        clear(node->left);
        delete node;
    }
    AVLNode<T> *containsHelp(AVLNode<T> *node, T &key)
    {
        if (node == nullptr)
        {
            return nullptr;
        }
        if (node->key == key)
        {
            return node;
        }
        else if (node->key > key)
        {
            return containsHelp(node->left, key);
        }
        else
        {
            return containsHelp(node->right, key);
        }
    }
    void print(AVLNode<T> *node)
    {
        if (node)
        {
            print(node->left);
            cout << node->key << " ";
            print(node->right);
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
    }
    // 删除键
    void remove(T key)
    {
        root = deleteHelper(root, key);
    }
    // 查找键是否存在
    bool contains(T key)
    {
        return containsHelp(root, key) != nullptr;
    }
    // 中序遍历打印（测试用）
    void printInOrder()
    {
        if (root == nullptr)
        {
            return;
        }
        print(root);
        cout << endl;
    }
    void rootprint()
    {
        cout << root->key << "   ";
        cout << root->left->key << endl;
    }
};