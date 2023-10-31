
#include <iostream>
#include <conio.h>

#include "Binary_Tree.h"

template <typename T>
size_t height_of_binary_tree(Node<T> *root)
{
    if (root == nullptr)
    {
        return 0;
    }

    size_t left_tree_height = height_of_binary_tree(root->left);
    size_t right_tree_height = height_of_binary_tree(root->right);

    return std::max(left_tree_height, right_tree_height) + 1ULL;
}

int main()
{
    using namespace std;

    BinaryTree<int> bin_tree;

    for (int i = -2; i <= 5; ++i)
    {
        bin_tree.insert(i);
    }

    bin_tree.display(bin_tree.begin(), 5);
    cout << '\n';

    cout << "Height of binary tree is " << height_of_binary_tree(bin_tree.begin());

    getch();
    return 0;
}