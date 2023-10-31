
#include <iostream>
#include <conio.h>

#include "binary_search_tree.h"

int main()
{
    using namespace std;

    BinarySearchTree<int> bin_search_tree;

    try
    {
        bin_search_tree.insert(0);
        bin_search_tree.insert(4);
        bin_search_tree.insert(2);
        bin_search_tree.insert(2);
        bin_search_tree.insert(-9);
        bin_search_tree.insert(-2);
        bin_search_tree.insert(-15);
        bin_search_tree.insert(7);
        bin_search_tree.insert(7);

        bin_search_tree.display(bin_search_tree.begin(), 5);
        cout << '\n';

        cout << "Inorder Traversal : "; 
        bin_search_tree.in_order_traversal(bin_search_tree.begin());
        cout << '\n'; 
    }
    catch (exception &ex)
    {
        cout << "Exception Caught : " << ex.what() << '\n';
    }

    getch();
    return 0;
}