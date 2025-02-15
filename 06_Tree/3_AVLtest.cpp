#include "3_AVLTree.hpp"
void test1()
{
    AVLTree<int> tree;
    tree.insert(9);
    tree.insert(14);
    tree.insert(5);
    tree.insert(3);
    tree.insert(8);
    tree.insert(6);

    tree.printInOrder();
    tree.remove(6);
    tree.remove(5);
    tree.printInOrder(); // 输出：10 20 25 50
    cout << tree.contains(5) << endl;
}
int main()
{
    test1();
    return 0;
}