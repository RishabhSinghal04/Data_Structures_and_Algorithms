#pragma once

#include <iostream>
#include <iomanip>

template <typename T>
struct Node
{
    T data;
    size_t height = 0ULL;
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
class AVLTree
{
    Node<T> *root = nullptr;
    const uint16_t GLOBALSPACE = 10;

public:
    AVLTree() = default;

    ~AVLTree() { clear(root); }

    bool empty() const { return root == nullptr; }

    void set_root_data(const T &data) { root = new Node<T>(data); }
    void insert(const T &data) { root = insert(root, data); }

    size_t get_height(Node<T> *node) const { return node == nullptr
                                                        ? 0ULL
                                                        : node->height; }

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

    void delete_value(const T &data)
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
    Node<T> *insert(Node<T> *node, const T &data)
    {
        if (node == nullptr)
        {
            node = new Node<T>(data);
            node->height = 1ULL;
            return node;
        }
        if (!empty() && data < node->data)
        {
            node->left = insert(node->left, data);
        }
        else if (!empty() && data > node->data)
        {
            node->right = insert(node->right, data);
        }
        else
        {
            return node;
        }

        update_height(node);
        node = rebalance(node, data);

        return node;
    }

    Node<T> *delete_node(Node<T> *node, const T &key)
    {
        if (node == nullptr)
        {
            return node;
        }
        // Delete leaf node
        if (node->left == nullptr && node->right == nullptr)
        {
            delete node;
            return nullptr;
        }

        if (key < node->data)
        {
            node->left = delete_node(node->left, key);
        }
        else if (key > node->data)
        {
            node->right = delete_node(node->right, key);
        }
        else
        {
            Node<T> *temp = nullptr;

            // node has both children
            temp = in_order_predecessor(node->left);
            node->data = temp->data;
            node->left = delete_node(node->left, temp->data);
        }

        update_height(node);
        node = rebalance(node, key);

        return node;
    }

    Node<T> *in_order_predecessor(Node<T> *root)
    {
        while (root->right != nullptr)
        {
            root = root->right;
        }
        return root;
    }

    void update_height(Node<T> *&node)
    {
        node->height = 1 + std::max(get_height(node->left), get_height(node->right));
    }

    Node<T> *rebalance(Node<T> *&node, const T &data)
    {
        int balance_factor = get_balance_factor(node);

        if (balance_factor > 1 && data < node->left->data)
        {
            return right_rotate(node);
        }
        else if (balance_factor < -1 && data > node->right->data)
        {
            return left_rotate(node);
        }
        else if (balance_factor > 1 && data > node->left->data)
        {
            node->left = left_rotate(node->left);
            return right_rotate(node);
        }
        else if (balance_factor < -1 && data < node->right->data)
        {
            node->right = right_rotate(node->right);
            return left_rotate(node);
        }
        return node;
    }

    int get_balance_factor(Node<T> *node)
    {
        if (empty())
        {
            return 0;
        }
        return get_height(node->left) - get_height(node->right);
    }

    Node<T> *right_rotate(Node<T> *y)
    {
        Node<T> *x = y->left;
        Node<T> *t2 = x->right;

        x->right = y;
        y->left = t2;

        y->height = std::max(get_height(y->left), get_height(y->right)) + 1;
        x->height = std::max(get_height(x->left), get_height(x->right)) + 1;

        return x;
    }

    Node<T> *left_rotate(Node<T> *x)
    {
        Node<T> *y = x->right;
        Node<T> *t2 = y->left;

        y->left = x;
        x->right = t2;

        x->height = std::max(get_height(x->left), get_height(x->right)) + 1;
        y->height = std::max(get_height(y->left), get_height(y->right)) + 1;

        return y;
    }
};