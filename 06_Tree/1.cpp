#include <iostream>
using namespace std;

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

    RBTreeNode(T k, Color c = RED, RBTreeNode *l = nullptr, RBTreeNode *r = nullptr, RBTreeNode *p = nullptr)
        : key(k), color(c), left(l), right(r), parent(p) {}
};

template <typename T>
class RedBlackTree
{
private:
    RBTreeNode<T> *root;
    RBTreeNode<T> *nil;

    // 左旋转操作
    void leftRotate(RBTreeNode<T> *x)
    {
        RBTreeNode<T> *y = x->right;
        x->right = y->left;
        if (y->left != nil)
        {
            y->left->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == nil)
        {
            root = y;
        }
        else if (x == x->parent->left)
        {
            x->parent->left = y;
        }
        else
        {
            x->parent->right = y;
        }
        y->left = x;
        x->parent = y;
    }

    // 右旋转操作
    void rightRotate(RBTreeNode<T> *y)
    {
        RBTreeNode<T> *x = y->left;
        y->left = x->right;
        if (x->right != nil)
        {
            x->right->parent = y;
        }
        x->parent = y->parent;
        if (y->parent == nil)
        {
            root = x;
        }
        else if (y == y->parent->right)
        {
            y->parent->right = x;
        }
        else
        {
            y->parent->left = x;
        }
        x->right = y;
        y->parent = x;
    }

    // 插入修复操作
    void insertFixup(RBTreeNode<T> *z)
    {
        while (z != root && z->parent->color == RED)
        {
            if (z->parent == z->parent->parent->left)
            {
                RBTreeNode<T> *y = z->parent->parent->right;
                if (y->color == RED)
                {
                    z->parent->color = BLACK;
                    y->color = BLACK;
                    z->parent->parent->color = RED;
                    z = z->parent->parent;
                }
                else
                {
                    if (z == z->parent->right)
                    {
                        z = z->parent;
                        leftRotate(z);
                    }
                    z->parent->color = BLACK;
                    z->parent->parent->color = RED;
                    rightRotate(z->parent->parent);
                }
            }
            else
            {
                RBTreeNode<T> *y = z->parent->parent->left;
                if (y->color == RED)
                {
                    z->parent->color = BLACK;
                    y->color = BLACK;
                    z->parent->parent->color = RED;
                    z = z->parent->parent;
                }
                else
                {
                    if (z == z->parent->left)
                    {
                        z = z->parent;
                        rightRotate(z);
                    }
                    z->parent->color = BLACK;
                    z->parent->parent->color = RED;
                    leftRotate(z->parent->parent);
                }
            }
        }
        root->color = BLACK;
    }

    // 删除修复操作
    void deleteFixup(RBTreeNode<T> *x)
    {
        while (x != root && x->color == BLACK)
        {
            if (x == x->parent->left)
            {
                RBTreeNode<T> *w = x->parent->right;
                if (w->color == RED)
                {
                    w->color = BLACK;
                    x->parent->color = RED;
                    leftRotate(x->parent);
                    w = x->parent->right;
                }
                if (w->left->color == BLACK && w->right->color == BLACK)
                {
                    w->color = RED;
                    x = x->parent;
                }
                else
                {
                    if (w->right->color == BLACK)
                    {
                        w->left->color = BLACK;
                        w->color = RED;
                        rightRotate(w);
                        w = x->parent->right;
                    }
                    w->color = x->parent->color;
                    x->parent->color = BLACK;
                    w->right->color = BLACK;
                    leftRotate(x->parent);
                    x = root;
                }
            }
            else
            {
                RBTreeNode<T> *w = x->parent->left;
                if (w->color == RED)
                {
                    w->color = BLACK;
                    x->parent->color = RED;
                    rightRotate(x->parent);
                    w = x->parent->left;
                }
                if (w->right->color == BLACK && w->left->color == BLACK)
                {
                    w->color = RED;
                    x = x->parent;
                }
                else
                {
                    if (w->left->color == BLACK)
                    {
                        w->right->color = BLACK;
                        w->color = RED;
                        leftRotate(w);
                        w = x->parent->left;
                    }
                    w->color = x->parent->color;
                    x->parent->color = BLACK;
                    w->left->color = BLACK;
                    rightRotate(x->parent);
                    x = root;
                }
            }
        }
        x->color = BLACK;
    }

    // 替换节点
    void transplant(RBTreeNode<T> *u, RBTreeNode<T> *v)
    {
        if (u->parent == nil)
        {
            root = v;
        }
        else if (u == u->parent->left)
        {
            u->parent->left = v;
        }
        else
        {
            u->parent->right = v;
        }
        v->parent = u->parent;
    }

    // 查找最小节点
    RBTreeNode<T> *minimum(RBTreeNode<T> *node)
    {
        while (node->left != nil)
        {
            node = node->left;
        }
        return node;
    }

    // 查找节点
    RBTreeNode<T> *search(RBTreeNode<T> *node, const T &key) const
    {
        if (node == nil || node->key == key)
        {
            return node;
        }
        if (key < node->key)
        {
            return search(node->left, key);
        }
        else
        {
            return search(node->right, key);
        }
    }

    // 删除节点
    void deleteNode(RBTreeNode<T> *z)
    {
        RBTreeNode<T> *y = z;
        RBTreeNode<T> *x;
        Color yOriginalColor = y->color;

        if (z->left == nil)
        {
            x = z->right;
            transplant(z, z->right);
        }
        else if (z->right == nil)
        {
            x = z->left;
            transplant(z, z->left);
        }
        else
        {
            y = minimum(z->right);
            yOriginalColor = y->color;
            x = y->right;
            if (y->parent == z)
            {
                x->parent = y;
            }
            else
            {
                transplant(y, y->right);
                y->right = z->right;
                y->right->parent = y;
            }
            transplant(z, y);
            y->left = z->left;
            y->left->parent = y;
            y->color = z->color;
        }
        if (yOriginalColor == BLACK)
        {
            deleteFixup(x);
        }
    }

    // 插入节点
    RBTreeNode<T> *insertHelper(RBTreeNode<T> *node, const T &key)
    {
        if (node == nil)
        {
            return new RBTreeNode<T>(key);
        }

        if (key < node->key)
        {
            node->left = insertHelper(node->left, key);
            node->left->parent = node;
        }
        else if (key > node->key)
        {
            node->right = insertHelper(node->right, key);
            node->right->parent = node;
        }

        return node;
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
        RBTreeNode<T> *node = insertHelper(root, key);
        node->color = RED;
        insertFixup(node);
    }

    void remove(const T &key)
    {
        RBTreeNode<T> *z = search(root, key);
        if (z != nil)
        {
            deleteNode(z);
        }
    }

    RBTreeNode<T> *search(const T &key) const
    {
        return search(root, key);
    }

    void printInOrder() const
    {
        printInOrderHelper(root);
    }

    void printInOrderHelper(RBTreeNode<T> *node) const
    {
        if (node != nil)
        {
            printInOrderHelper(node->left);
            cout << node->key << " ";
            printInOrderHelper(node->right);
        }
    }
};

int main()
{
    RedBlackTree<int> tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(15);
    tree.insert(25);

    cout << "Red-Black Tree (inorder traversal): ";
    tree.printInOrder();
    cout << endl;

    tree.remove(20);
    cout << "After deleting 20 (inorder traversal): ";
    tree.printInOrder();
    cout << endl;

    RBTreeNode<int> *foundNode = tree.search(15);
    if (foundNode != nullptr)
    {
        cout << "Node found: " << foundNode->key << endl;
    }
    else
    {
        cout << "Node not found." << endl;
    }

    return 0;
}
