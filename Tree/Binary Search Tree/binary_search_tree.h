#pragma once

#include <iostream>
#include <iomanip>

template <typename T>
struct Node
{
    T data;
    size_t count = 0ULL;
    Node *left = nullptr;
    Node *right = nullptr;
    Node()
        : Node<T>({}, nullptr, nullptr) {}

    Node(const T &data)
        : Node<T>(data, nullptr, nullptr) {}

    Node(const T &data, Node<T> *left, Node<T> *right)
        : data{data}, left{left}, right{right} {}
};

template <typename T>
class BinarySearchTree
{
    Node<T> *root = nullptr;
    const uint16_t GLOBALSPACE = 10;

public:
    BinarySearchTree() = default;

    ~BinarySearchTree() { clear(root); }

    bool empty() const { return root == nullptr; }

    void set_root_data(const T &data) { root = new Node<T>(data); }
    void insert(const T &data) { insert(root, data); }

    Node<T> *&begin()
    {
        if (empty())
        {
            throw std::runtime_error("empty");
        }
        return root;
    }

    void clear(Node<T> *&leaf)
    {
        if (leaf == nullptr)
        {
            return;
        }
        clear(leaf->left);
        clear(leaf->right);
        delete leaf;
        leaf = nullptr;
    }

    void delete_node(const T &data)
    {
        if (empty())
        {
            throw std::runtime_error("empty");
        }
        delete_node(root, data);
    }

    void display(const Node<T> *root, uint16_t space)
    {
        if (empty())
        {
            return;
        }

        space += GLOBALSPACE;
        if (root->right != nullptr)
        {
            display(root->right, space);
        }

        std::cout << '\n'
                  << std::setw(space - GLOBALSPACE)
                  << root->data << '\n';

        if (root->left != nullptr)
        {
            display(root->left, space);
        }
    }

    void pre_order_traversal(const Node<T> *root)
    {
        if (root == nullptr)
        {
            return;
        }
        std::cout << root->data << "  ";
        pre_order_traversal(root->left);
        pre_order_traversal(root->right);
    }

    void post_order_traversal(const Node<T> *root)
    {
        if (root == nullptr)
        {
            return;
        }
        post_order_traversal(root->left);
        post_order_traversal(root->right);
        std::cout << root->data << "  ";
    }

    void in_order_traversal(const Node<T> *root)
    {
        if (root == nullptr)
        {
            return;
        }
        in_order_traversal(root->left);
        std::cout << root->data << "  ";
        in_order_traversal(root->right);
    }

private:
    void insert(Node<T> *&node, const T &data)
    {
        if (node == nullptr)
        {
            node = new Node<T>(data);
            return;
        }

        if (!empty() && data < node->data)
        {
            insert(node->left, data);
        }
        else if (!empty() && data > node->data)
        {
            insert(node->right, data);
        }
        else
        {
            ++node->count;
        }
    }

    Node<T> *delete_node(Node<T> *root, const T &key)
    {
        if (root == nullptr)
        {
            return root;
        }
        // Delete leaf node
        if (root->left == nullptr && root->right == nullptr)
        {
            delete root;
            return nullptr;
        }

        if (key < root->data)
        {
            root->left = delete_node(root->left, key);
        }
        else if (key > root->data)
        {
            root->right = delete_node(root->right, key);
        }
        else
        {
            Node<T> *temp = nullptr;

            // root has both children
            temp = in_order_predecessor(root->left);
            root->data = temp->data;
            root->left = delete_node(root->left, temp->data);
        }
        return root;
    }

    Node<T> *in_order_predecessor(Node<T> *root)
    {
        while (root->right != nullptr)
        {
            root = root->right;
        }
        return root;
    }
};