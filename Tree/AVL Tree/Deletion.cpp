
#include <iostream>
#include <conio.h>

#include "avl_tree.h"

int main()
{
    using namespace std;

    AVLTree<int> avl_tree;

    for (int index = 10; index >= 5; --index)
    {
        avl_tree.insert(index);
    }

    avl_tree.display(avl_tree.begin(), 5);
    cout << "\n\n\n\n";

    avl_tree.delete_value(9);
    avl_tree.delete_value(7);

    avl_tree.display(avl_tree.begin(), 5);
    cout << "\n\n";

    getch();
    return 0;
}