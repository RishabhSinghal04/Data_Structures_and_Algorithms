#pragma once

#include <iostream>
#include <iomanip>
#include <queue>

template <typename T>
struct Node
{
    T data;
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
class BinaryTree
{
    Node<T> *root = nullptr;
    const uint16_t GLOBALSPACE = 10;

public:
    BinaryTree() = default;

    ~BinaryTree()
    {
        clear(root);
    }

    bool empty() const { return root == nullptr; }

    Node<T> *&begin()
    {
        if (empty())
        {
            throw std::runtime_error("empty");
        }
        return root;
    }

    void set_root_data(const T &data) { root = new Node<T>(data); }

    void insert(const T &data)
    {
        if (root == nullptr)
        {
            root = new Node<T>(data);
            return;
        }

        std::queue<Node<T> *> q;
        q.emplace(root);

        while (!q.empty())
        {
            Node<T> *temp = q.front();
            q.pop();

            if (temp->left == nullptr)
            {
                temp->left = new Node<T>(data);
                break;
            }
            if (temp->right == nullptr)
            {
                temp->right = new Node<T>(data);
                break;
            }
            else
            {
                q.emplace(temp->left);
                q.emplace(temp->right);
            }
        }
    }

    void clear(Node<T> *&leaf)
    {
        if (leaf != nullptr)
        {
            return;
        }
        clear(leaf->left);
        clear(leaf->right);
        delete leaf;
        leaf = nullptr;
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
};