template <typename T>
class AVLTree : public BinaryTree<T>
{
protected:
    struct AVLNode : public Node
    {
        int height; // 节点高度
        AVLNode(const T &val) : Node(val), height(1) {}
    };

    // 重写基类函数以使用AVLNode
    AVLNode *insert(AVLNode *node, const T &value);
    AVLNode *remove(AVLNode *node, const T &value);

    // AVL核心操作
    int getHeight(AVLNode *node) const;
    int getBalanceFactor(AVLNode *node) const;
    AVLNode *rotateLeft(AVLNode *node);  // 左旋
    AVLNode *rotateRight(AVLNode *node); // 右旋
    AVLNode *rebalance(AVLNode *node);   // 平衡调整

public:
    // 重写基类接口（确保使用AVLNode）
    void insert(const T &value) override;
    bool remove(const T &value) override;
};