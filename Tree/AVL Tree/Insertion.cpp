
#include <iostream>
#include <conio.h>

#include "avl_tree.h"

int main()
{
    using namespace std;

    AVLTree<int> avl_tree;

    for (int index = 1; index <= 5; ++index)
    {
        avl_tree.insert(index);
    }

    avl_tree.display(avl_tree.begin(), 5);
    avl_tree.clear(avl_tree.begin());
    cout << "\n\n";

    for (int index = 10; index >= 5; --index)
    {
        avl_tree.insert(index);
    }

    avl_tree.display(avl_tree.begin(), 5);
    cout << "\n\n";

    getch();
    return 0;
}
/*
         10
        9
      8
    7
  6
5
________________
         10
       9
     7
  6     8
5
________________
        10
     7
  6     9
5     8
________________
     7
  6     10
5     9
    8
________________
       7
   6       9
5       8    10
 */