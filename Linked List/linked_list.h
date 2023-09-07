#pragma once

#include <sstream>
#include <cmath>

namespace ll
{
    template <typename T>
    class Linked_List
    {
        template <typename V>
        struct Node
        {
            V data;
            Node<V> *next = nullptr;

            Node()
                : Node({}) {}
            Node(const V &data)
                : data{data}, next{nullptr} {}
        };
        Node<T> *head = nullptr;
        size_t size = 0ULL;
        const std::string message_empty{"List is Empty"};

    public:
        Linked_List()
            : head{nullptr}, size{0ULL} {}

        ~Linked_List() { clear(); }

        bool empty() const { return head == nullptr; }

        /* __Getters__ */
        const T get_size() const { return size; }

        const T get_head_data() const
        {
            if (empty())
            {
                throw std::runtime_error(message_empty);
            }
            return head->data;
        }

        /* _Add Nodes_ */
        void push(const T &data)
        {
            Node<T> *new_node = new Node<T>(data);
            new_node->next = head;
            head = new_node;
            ++size;
        }

        void push_back(const T &data)
        {
            if (empty())
            {
                return push(data);
            }

            Node<T> *new_node = new Node<T>(data);
            Node<T> *last_node = head;
            new_node->next = nullptr;

            while (last_node->next != nullptr)
            {
                last_node = last_node->next;
            }
            last_node->next = new_node;
            ++size;
        }

        void insert_at(const size_t &index, const T &data)
        {
            if (empty())
            {
                throw std::runtime_error(message_empty);
            }
            if (index > size)
            {
                throw std::runtime_error("Out of Range");
            }
            if (index == 0ULL)
            {
                return push(data);
            }
            if (index == size)
            {
                return push_back(data);
            }

            Node<T> *node = new Node<T>(data);
            Node<T> *prev_node = head;

            for (size_t i = 1ULL; i < index; ++i)
            {
                prev_node = prev_node->next;
            }

            node->next = prev_node->next;
            prev_node->next = node;
            ++size;
        }

        /* _Delete Nodes_ */
        void clear()
        {
            while (head != nullptr && head->next != nullptr)
            {
                delete_next_node(head);
            }
            if (head != nullptr)
            {
                free_memory(head);
                head = nullptr;
            }
            size = 0ULL;
        }

        void delete_first_element()
        {
            if (empty())
            {
                throw std::runtime_error(message_empty);
            }

            Node<T> *first_node = head;
            head = first_node->next;
            --size;
            free_memory(first_node);
        }

        void delete_last_element()
        {
            if (size < 2ULL)
            {
                return delete_first_element();
            }

            Node<T> *second_last_node = head;

            while (second_last_node->next->next != nullptr)
            {
                second_last_node = second_last_node->next;
            }
            delete_next_node(second_last_node);
        }

        void delete_at(const size_t &index)
        {
            if (empty())
            {
                throw std::runtime_error(message_empty);
            }
            if (index == 0ULL)
            {
                return delete_first_element();
            }

            Node<T> *prev_node = head;

            for (size_t i = 1; i < index; ++i)
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

            auto equal = []<typename V>(const V &data, const V &key)
            {
                const double PRECISION = 1e-2;
                return (std::is_floating_point_v<V>)
                           ? fabs(data - key) < PRECISION
                           : data == key;
            };

            if (equal(head->data, key))
            {
                return delete_first_element();
            }

            Node<T> *prev_node = head;

            while (prev_node->next != nullptr && !equal(prev_node->next->data, key))
            {
                prev_node = prev_node->next;
            }

            if (prev_node->next == nullptr)
            {
                return;
            }
            delete_next_node(prev_node);
        }

        void display()
        {
            std::ostringstream oss;
            Node<T> *current = head;
            while (current != nullptr)
            {
                oss << current->data << "-> ";
                current = current->next;
            }
            // Remove the last arrow
            std::cout << oss.str().substr(0, oss.str().length() - 3);
        }

    private:
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