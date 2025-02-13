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
        else if (node->data() > value)
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
                BSTNode<T>* instead 
            }
        }
    }
    BSTNode<T> *findMinNode(BSTNode<T> *node); // 找子树最小节点

public:
    BinarySearchTree() : root(nullptr) {}
    // 析构函数需要释放内存
    ~BinarySearchTree()
    {
        clear();
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