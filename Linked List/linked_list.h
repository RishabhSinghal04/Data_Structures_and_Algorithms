#pragma once

#include <iostream>

namespace ll
{
    template <typename T>
    struct Node
    {
        T data;
        Node<T> *next{};

        Node()
            : Node({}) {}
        Node(const T &data)
            : data{data}, next{nullptr} {}
    };

    template <typename T>
    class Linked_List
    {
        Node<T> *head;

    public:
        Linked_List()
            : head{NULL} {}

        ~Linked_List()
        {
            Node<T> *next{};
            while (head != NULL)
            {
                next = head->next;
                delete head;
                head = next;
            }
            std::cout << "\nEXIT\n";
        }

        // Getter
        Node<T> *get_head() const
        {
            return head;
        }

        // Add a new node to the front of the list
        void push(const T &data)
        {
            Node<T> *new_node = new Node<T>(data);
            new_node->next = head;
            head = new_node;
        }

        // Add a new node to the back of the list
        void push_back(const T &data)
        {
            Node<T> *new_node = new Node<T>(data);
            Node<T> *last_node = head;
            new_node->next = NULL;

            // If list is empty, add new node at the front
            if (head == NULL)
            {
                head = new_node;
                return;
            }

            // Get last node and add new node at last
            while (last_node->next != nullptr)
            {
                last_node = last_node->next;
            }
            last_node->next = new_node;
        }

        // Add a new node in between
        void insert_after(Node<T> *previous_node, const T &data)
        {
            if (previous_node == NULL)
            {
                std::cerr << "\nGiven previous node cannot be null\n";
                return;
            }

            Node<T> *new_node = new Node<T>();
            new_node->data = data;
            new_node->next = previous_node->next;
            previous_node->next = new_node;
        }

        // Add a new node at given index
        void insert_at(const size &index, const T &data)
        {
        }

        void delete_first_node()
        {
            if (head == NULL)
            {
                return;
            }

            Node<T> *first_node = head;
            head = first_node->next;
            delete first_node;
        }

        void delete_last_node()
        {
            if (head == NULL)
            {
                return;
            }

            Node<T> *second_last_node = head;
            Node<T> *last_node = head->next;

            while (last_node->next != nullptr)
            {
                second_last_node = second_last_node->next;
                last_node = last_node->next;
            }
            second_last_node->next = nullptr;
            delete last_node;
        }

        void delete_after(Node<T> *previous_node)
        {
            if (previous_node == NULL)
            {
                std::cerr << "\nGiven previous node cannot be null\n";
                return;
            }

            Node<T> *next_node = previous_node->next;
            previous_node->next = next_node->next;
            delete next_node;
        }

        void delete_at(const size_t &index)
        {
            if (head == NULL)
            {
                return;
            }

            Node<T> *temp = head->next;
            Node<T> *previous_node = head;

            for (size_t i = 0; i < index - 1; ++i)
            {
                temp = temp->next;
                previous_node = previous_node->next;
            }
            previous_node->next = temp->next;
            delete temp;
        }

        // Delete first node with the given key
        void delete_node(const T &key)
        {
            Node<T> *temp = head;
            Node<T> *previous_node = NULL;

            if (temp != NULL && temp->data == key)
            {
                head = temp->next;
                temp = NULL;
                return;
            }

            while (temp != NULL && temp->data != key)
            {
                previous_node = temp;
                temp = temp->next;
            }

            if (temp == NULL)
            {
                return;
            }

            previous_node->next = temp->next;
            delete temp;
        }

        void display()
        {
            Node<T> *current = head;
            while (current != NULL)
            {
                std::cout << current->data << "-> ";
                current = current->next;
            }
            std::cout << "\b\b\b  \b\b";
            delete current;
        }
    };
}