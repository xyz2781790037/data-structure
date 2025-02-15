#include <iostream>
#include <queue>
using namespace std;
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
    BSTNode<T> *insertHelper(BSTNode<T> *node, T value)
    {
        if (node == nullptr)
        {
            return new BSTNode(value);
        }
        else if (node->data > value)
        {
            node->left = insertHelper(node->left, value);
        }
        else
        {
            node->right = insertHelper(node->right, value);
        }
    }
    BSTNode<T> *removeHelper(BSTNode<T> *node, T value)
    {
        if (value < node->data)
        {
            node->left = removeHelper(node->left, value);
        }
        else if (value > node->data)
        {
            node->right = removeHelper(node->right, value);
        }
        else
        {
            if (!node->left && !node->right)
            {
                delete node;
                return nullptr;
            }
            else if (!node->left || !node->right)
            {
                BSTNode<T> *son = node->left ? node->left : node->right;
                delete node;
                return son;
            }
            else
            {
                BSTNode<T> *instead = findMinNode(node->right);
                node->data = instead->data;
                node->right = removeHelper(node->right, instead->data); // 递归删除最小节点
            }
        }
    }
    // 找子树最小节点
    BSTNode<T> *findMinNode(BSTNode<T> *node)
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
    void clear(BSTNode<T> *node)
    {
        if (node == nullptr)
        {
            return;
        }
        clear(node->left);
        clear(node->right);
        delete node;
    }
    BSTNode<T> *helpcontain(BSTNode<T> *node, T &value)
    {
        if (node == nullptr)
        {
            return nullptr;
        }
        if (node->data == value)
        {
            return node;
        }
        else if (node->data > value)
        {
            return helpcontain(node->left, value);
        }
        else
        {
            return helpcontain(node->right, value);
        }
    }
    int heighthelp(BSTNode<T> *node) const
    {
        if (node == nullptr)
            return 0;
        return 1 + max(heighthelp(node->left), heighthelp(node->right));
    }
    int sizeHelp(BSTNode<T> *node) const
    {
        if (node == nullptr)
            return 0;
        return 1 + sizeHelper(node->left) + sizeHelper(node->right);
    }

public:
    BinarySearchTree() : root(nullptr) {}
    // 析构函数需要释放内存
    ~BinarySearchTree()
    {
        clear(root);
    }
    // 基本操作
    // 插入新值
    void insert(T value)
    {
        root = insertHelper(root, value);
    }
    // 删除值（需处理三种情况）
    void remove(T value)
    {
        root = remove(root, value);
    }
    // 是否包含值
    bool contains(T value)
    {
        BSTNode<T> *cur = helpcontain(root, value);
        if (cur)
        {
            return true;
        }
        return false;
    }

    // 遍历
    // 中序遍历（结果有序）
    void traverseInOrder(BSTNode<T> *node = root)
    {
        if (node == nullptr)
        {
            return;
        }
        traverseInOrder(node->left);
        cout << node->data << " ";
        traverseInOrder(node->right);
    }
    void traversePreOrder(BSTNode<T> *node = root)
    {
        if (node == nullptr)
        {
            return;
        }
        cout << node->data << " ";
        traversePreOrder(node->left);
        traversePreOrder(node->right);
    }
    void traversePostOrder(BSTNode<T> *node = root)
    {
        if (node == nullptr)
        {
            return;
        }
        traversePostOrder(node->left);
        traversePostOrder(node->right);
        cout << node->data << " ";
    }
    // 层序遍历
    void traverseLevelOrder()
    {
        if (root == nullptr)
            return;
        queue<BSTNode<T> *> q;
        q.push(root);
        while(!q.empty())
        {
            BSTNode<T> *cur = q.front();
            q.pop();
            cout << cur->data << " ";
            if(cur->left)
            {
                q.push(cur->left);
            }
            if(cur->right)
            {
                q.push((cur->right));
            }
        }
    }

    // 工具函数
    T findMin()
    {
        BSTNode<T> *node = root;
        if (node == nullptr)
        {
            cout << "root is error" << endl;
        }
        while (node->left)
        {
            node = node->left;
        }
        return node->data;
    }
    // 最大值（最右节点）
    T findMax()
    {
        BSTNode<T> *node = root;
        if (node == nullptr)
        {
            cout << "root is error" << endl;
        }
        while (node->right)
        {
            node = node->right;
        }
        return node->data;
    }
    // 树的高度
    int height(int count = 0)
    {
        return heighthelp(root);
    }
    // 节点总数
    int size(int count = 0, BSTNode<T> *node = root)
    {
        return sizeHelp(root);
    }
    bool isEmpty()
    {
        return root == nullptr;
    }
};