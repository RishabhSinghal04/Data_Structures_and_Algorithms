#pragma once

#include <iostream>
#include <array>

class Trie
{
    static const uint16_t NUM_OF_ALPHABETS = 26;

    struct Node
    {
        std::array<Node *, NUM_OF_ALPHABETS> children{nullptr};
        bool end_of_word = false;
    };

    Node *root = nullptr;

public:
    Trie() { root = new Node(); }

    ~Trie() { clear(root); }

    void insert(const std::string &word)
    {
        Node *current = root;
        for (const auto &character : word)
        {
            uint16_t index = character - 'a';
            if (current->children.at(index) == nullptr)
            {
                current->children.at(index) = new Node();
            }
            current = current->children.at(index);
        }
        current->end_of_word = true;
    }

    bool search(const std::string &word)
    {
        Node *current = root;
        for (const auto &character : word)
        {
            uint16_t index = character - 'a';
            if (current->children.at(index) == nullptr)
            {
                return false;
            }
            current = current->children.at(index);
        }
        return current->end_of_word;
    }

    void clear(Node *&node)
    {
        if (node == nullptr)
        {
            return;
        }

        for (size_t index = 0; index < NUM_OF_ALPHABETS; ++index)
        {
            clear(node->children[index]);
        }
        delete node;
        node = nullptr;
    }

    void display()
    {
        display(root, "");
    }

private:
    void display(Node *node, std::string st)
    {
        if (node->end_of_word)
        {
            std::cout << st << '\n';
        }

        for (uint16_t index = 0; index < NUM_OF_ALPHABETS; ++index)
        {
            if (node->children.at(index) != nullptr)
            {
                display(node->children.at(index), st + char('a' + index));
            }
        }
    }
};