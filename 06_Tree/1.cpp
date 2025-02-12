#include <queue>
#include <functional>

template <typename T>
class BinaryTree
{
protected:
    struct Node
    {
        T data;
        Node *left;
        Node *right;
        Node(const T &val) : data(val), left(nullptr), right(nullptr) {}
    };

    Node *root;

    // 递归清空子树
    void clear(Node *node)
    {
        if (!node)
            return;
        clear(node->left);
        clear(node->right);
        delete node;
    }

    // 查找节点
    Node *findNode(Node *node, const T &value) const
    {
        if (!node)
            return nullptr;
        if (node->data == value)
            return node;
        Node *leftResult = findNode(node->left, value);
        if (leftResult)
            return leftResult;
        return findNode(node->right, value);
    }

    // 查找父节点
    Node *findParent(Node *target) const
    {
        if (!root || root == target)
            return nullptr;
        std::queue<Node *> q;
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
    BinaryTree() : root(nullptr) {}
    virtual ~BinaryTree() { clear(root); }

    // 插入节点（按层级顺序插入）
    virtual void insert(const T &value)
    {
        if (!root)
        {
            root = new Node(value);
            return;
        }

        std::queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            Node *current = q.front();
            q.pop();

            if (!current->left)
            {
                current->left = new Node(value);
                return;
            }
            else
            {
                q.push(current->left);
            }

            if (!current->right)
            {
                current->right = new Node(value);
                return;
            }
            else
            {
                q.push(current->right);
            }
        }
    }

    // 删除节点及其子树
    virtual bool remove(const T &value)
    {
        Node *nodeToRemove = findNode(root, value);
        if (!nodeToRemove)
            return false;

        Node *parent = findParent(nodeToRemove);

        if (!parent)
        { // 删除根节点
            clear(root);
            root = nullptr;
        }
        else
        {
            if (parent->left == nodeToRemove)
            {
                parent->left = nullptr;
            }
            else
            {
                parent->right = nullptr;
            }
            clear(nodeToRemove);
        }
        return true;
    }

    // 查找存在性
    virtual bool contains(const T &value) const
    {
        return findNode(root, value) != nullptr;
    }

    // 遍历接口
    void preOrder(void (*visit)(const T &)) const
    {
        std::function<void(Node *)> traverse = [&](Node *node)
        {
            if (!node)
                return;
            visit(node->data);
            traverse(node->left);
            traverse(node->right);
        };
        traverse(root);
    }

    void inOrder(void (*visit)(const T &)) const
    {
        std::function<void(Node *)> traverse = [&](Node *node)
        {
            if (!node)
                return;
            traverse(node->left);
            visit(node->data);
            traverse(node->right);
        };
        traverse(root);
    }

    void postOrder(void (*visit)(const T &)) const
    {
        std::function<void(Node *)> traverse = [&](Node *node)
        {
            if (!node)
                return;
            traverse(node->left);
            traverse(node->right);
            visit(node->data);
        };
        traverse(root);
    }

    bool isEmpty() const { return root == nullptr; }
};