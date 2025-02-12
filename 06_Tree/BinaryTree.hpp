#include <queue>
#include <functional>
#include <iostream>
using namespace std;
template <typename T>
class BinaryTree
{
protected:
    typedef struct Node
    {
        T data;
        Node *left;
        Node *right;
        Node(const T &val) : data(val), left(nullptr), right(nullptr) {}
    } sn;

    Node *root;
    Node *findNode(Node *node, const T &value) const
    {
        if (node == nullptr)
        {
            return nullptr;
        }
        if (node->data == value)
        {
            return node;
        }
        sn *leftresult = findNode(node->left, value);
        if (leftresult)
        {
            return leftresult;
        }
        else
        {
            return findNode(node->right, value);
        }
    }
    Node *findParent(Node *target) const
    {
        if (root == nullptr || root == target)
        {
            return nullptr;
        }
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            Node *current = q.front();
            q.pop();

            if (current->left)
            {
                if (current->left == target)
                    return current;
                q.push(current->left);
            }
            if (current->right)
            {
                if (current->right == target)
                    return current;
                q.push(current->right);
            }
        }
        return nullptr;
    }

public:
    // 构造函数/析构函数
    BinaryTree() : root(nullptr){}
    virtual ~BinaryTree() { clear(root); } // 需要递归释放节点内存

    // 基础操作
    // 插入（普通二叉树插入逻辑）
    virtual void insert(const T &value)
    {
        if (root == nullptr)
        {
            root = new Node(value);
            return;
        }
        queue<sn *> q;
        q.push(root);
        while (!q.empty())
        {
            sn *cur = q.front();
            q.pop();
            if (!cur->left)
            {
                cur->left = new sn(value);
                return;
            }
            else
            {
                q.push(cur->left);
            }
            if (!cur->right)
            {
                cur->right = new sn(value);
                return;
            }
            else
            {
                q.push(cur->right);
            }
        }
    }
    virtual bool remove(const T &value)
    {
        sn *deletenode = findNode(root, value);
        if (deletenode == nullptr)
        {
            return false;
        }
        sn *father = findParent(deletenode);
        if (father == nullptr)
        {
            clear(root);
            root = nullptr;
        }
        else
        {
            if (father->left == deletenode)
            {
                father->left = nullptr;
            }
            else
            {
                father->right = nullptr;
            }
            clear(deletenode);
        }
        return true;
    }
    // 查找
    virtual bool contains(const T &value) const
    {
        sn *node = findNode(root, value);
        if (node == nullptr)
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    // 遍历接口
    // 先序遍历
    void preOrder(void (*visit)(const T &),sn* node = root) const
    {
        if (node == nullptr)
        {
            return;
        }
        cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }
    // 中序遍历
    void inOrder(void (*visit)(const T &), sn *node = root) const
    {
        if (node == nullptr)
        {
            return;
        }
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }
    // 后序遍历
    void postOrder(void (*visit)(const T &), sn *node = root) const
    {
        if (node == nullptr)
        {
            return;
        }
        postOrder(node->left);
        cout << node->data << " ";
        postOrder(node->right);
    }
    // 工具函数
    bool isEmpty() const { return root == nullptr; }
    // 递归清空子树
    void clear(Node *node)
    {
        if (!node)
        {
            return;
        }
        clear(node->left);
        clear(node->right);
        delete node;
    }
};