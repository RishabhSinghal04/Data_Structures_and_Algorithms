#pragma once

#include <iostream>
#include <cmath>

namespace cll
{
    template <typename T>
    class Circular_Linked_List
    {
        template <typename V>
        struct Node
        {
            T data;
            Node<V> *next = nullptr;

            Node()
                : Node({}) {}
            Node(const V &data)
                : data{data}, next{nullptr} {}
        };
        Node<T> *tail = nullptr;
        size_t size = 0ULL;
        const std::string message_empty{"List is empty"};

    public:
        Circular_Linked_List()
            : tail{nullptr}, size{0ULL} {}

        ~Circular_Linked_List() { clear(); }

        const bool empty() const { return tail == nullptr; }

        /* __Getters__ */
        const size_t get_size() const { return size; }

        const T get_head_data() const
        {
            if (empty())
            {
                throw std::runtime_error(message_empty);
            }
            return tail->next->data;
        }
        const T get_tail_data() const
        {
            if (empty())
            {
                throw std::runtime_error(message_empty);
            }
            return tail->data;
        }

        /* _Add Nodes_ */
        void push(const T &data)
        {
            Node<T> *new_node = new Node<T>(data);

            if (empty())
            {
                tail = new_node;
                new_node->next = tail;
                ++size;
                return;
            }
            insert_node(tail, new_node);
        }

        void push_back(const T &data)
        {
            if (empty())
            {
                return push(data);
            }

            Node<T> *new_node = new Node<T>(data);
            insert_node(tail, new_node);
            tail = new_node;
        }

        void insert_at(const size_t &index, const T &data)
        {
            if (empty())
            {
                throw std::runtime_error(message_empty);
            }
            if (index > size)
            {
                throw std::runtime_error("Out of Bounds");
            }
            if (index == 0ULL)
            {
                return push(data);
            }
            if (index == size)
            {
                return push_back(data);
            }

            Node<T> *new_node = new Node<T>(data);
            Node<T> *prev_node = tail->next;

            // Find the node before the insertion point
            for (size_t i = 1ULL; i < index; ++i)
            {
                prev_node = prev_node->next;
            }
            insert_node(prev_node, new_node);
        }

        /* _Delete Nodes_ */
        void clear()
        {
            if (empty())
            {
                throw std::runtime_error(message_empty);
            }

            Node<T> *head = tail->next;
            Node<T> *next = nullptr;

            do
            {
                next = head->next;
                head = nullptr;
                head = next;
            } while (head != tail->next);

            tail = nullptr;
            size = 0ULL;
        }

        void delete_first_element()
        {
            if (size < 2ULL)
            {
                return clear();
            }
            delete_next_node(tail);
        }

        void delete_last_element()
        {
            if (size < 2ULL)
            {
                return clear();
            }

            Node<T> *second_last_node = tail->next;

            while (second_last_node->next != tail)
            {
                second_last_node = second_last_node->next;
            }

            delete_next_node(second_last_node);
            tail = second_last_node;
        }

        void delete_at(const size_t &index)
        {
            if (empty())
            {
                throw std::runtime_error(message_empty);
            }
            if (index >= size)
            {
                throw std::runtime_error("Out of Bounds");
            }
            if (index == 0ULL)
            {
                return delete_first_element();
            }
            if (index == size - 1ULL)
            {
                return delete_last_element();
            }

            Node<T> *prev_node = tail->next;

            for (size_t i = 1ULL; i < index; ++i)
            {
                prev_node = prev_node->next;
            }
            delete_next_node(prev_node);
        }

        void delete_element(const T &key)
        {
            if (empty())
            {
                throw std::runtime_error(message_empty);
            }

            auto equal = []<typename V>(const V &data, const V &key) -> bool
            {
                const double PRECISION = 1e-2;
                return (std::is_floating_point_v<V>)
                           ? fabs(data - key) < PRECISION
                           : data == key;
            };

            if (tail->next != nullptr && equal(tail->next->data, key))
            {
                return delete_first_element();
            }

            Node<T> *prev_node = tail->next;

            while (prev_node->next != tail && !equal(prev_node->next->data, key))
            {
                prev_node = prev_node->next;
            }

            // Return if element not found
            if (prev_node->next == tail->next)
            {
                return;
            }
            if (prev_node->next == tail)
            {
                tail = prev_node;
            }
            delete_next_node(prev_node);
        }

        void display() const
        {
            if (empty())
            {
                throw std::runtime_error(message_empty);
            }

            Node<T> *current = tail->next;
            do
            {
                std::cout << current->data << "-> ";
                current = current->next;
            } while (current != tail->next);

            std::cout << current->data << "....";
        }

    private:
        void insert_node(Node<T> *prev_node, Node<T> *new_node)
        {
            new_node->next = prev_node->next;
            prev_node->next = new_node;
            ++size;
        }

        void delete_next_node(Node<T> *prev_node)
        {
            Node<T> *node = prev_node->next;
            prev_node->next = node->next;
            --size;
            free_memory(node);
        }

        void free_memory(Node<T> *node)
        {
            delete node;
            node = nullptr;
        }
    };
}