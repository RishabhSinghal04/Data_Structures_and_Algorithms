
#include <iostream>
#include <conio.h>

#include "Binary_Tree.h"

int main()
{
    using namespace std;

    BinaryTree<int> bin_tree;

    bin_tree.insert(0);

    for (int i = 1; i <= 7; ++i)
    {
        bin_tree.insert(i);
        bin_tree.insert(-i);
    }

    bin_tree.display(bin_tree.begin(), 5);

    cout << "\nPre-Order Traversal:-\n";
    bin_tree.pre_order_traversal(bin_tree.begin());

    cout << "\nPost-Order Traversal:-\n";
    bin_tree.post_order_traversal(bin_tree.begin());

    cout << "\nIn-Order Traversal:-\n";
    bin_tree.in_order_traversal(bin_tree.begin());

    getch();
    return 0;
}
