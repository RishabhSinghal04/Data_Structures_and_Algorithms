#pragma once

#include <sstream>
#include <cmath>

namespace dll
{
    template <typename T>
    class Doubly_Linked_List
    {
        template <typename V>
        struct Node
        {
            V data{};
            Node<V> *next = nullptr, *prev = nullptr;

            Node()
                : Node({}) {}
            Node(const V &data)
                : data{data}, next{nullptr}, prev{nullptr} {}
        };
        Node<T> *head = nullptr, *tail = nullptr;
        size_t size = 0ULL;
        const std::string message_empty = "List is empty";

    public:
        Doubly_Linked_List()
            : head{nullptr}, tail{nullptr}, size{0ULL} {}

        ~Doubly_Linked_List() { clear(); }

        bool empty() const { return head == nullptr; }

        /* __Getters__ */
        const size_t get_size() const { return size; }

        const T get_head_data() const
        {
            if (empty())
            {
                throw ::std::runtime_error(message_empty);
            }
            return head->data;
        }

        const T get_tail_data() const
        {
            if (empty())
            {
                throw ::std::runtime_error(message_empty);
            }
            return tail->data;
        }

        /* _Add Nodes_ */
        void push(const T &data)
        {
            Node<T> *new_node = new Node<T>(data);
            new_node->next = head;

            empty()
                ? tail = new_node
                : head->prev = new_node;

            head = new_node;
            ++size;
        }

        void push_back(const T &data)
        {
            Node<T> *new_node = new Node<T>(data);
            new_node->prev = tail;

            empty()
                ? head = new_node
                : tail->next = new_node;

            tail = new_node;
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
            Node<T> *prev_node = head;

            for (size_t i = 1ULL; i < index; ++i)
            {
                prev_node = prev_node->next;
            }

            new_node->next = prev_node->next;
            prev_node->next->prev = new_node;
            new_node->prev = prev_node;
            prev_node->next = new_node;
            ++size;
        }

        /* _Delete Nodes_ */
        void clear()
        {
            Node<T> *current = head;
            while (current != NULL)
            {
                Node<T> *next = current->next;
                delete current;
                current = next;
            }
            size = 0ULL;
            head = nullptr;
            tail = nullptr;
        }

        void delete_first_element()
        {
            if (empty())
            {
                throw std::runtime_error(message_empty);
            }
            if (size < 2ULL)
            {
                return clear();
            }

            Node<T> *first_node = head;
            head = first_node->next;
            head->prev = nullptr;
            --size;
            free_memory(first_node);
        }

        void delete_last_element()
        {
            if (empty())
            {
                throw std::runtime_error(message_empty);
            }
            if (size < 2ULL)
            {
                return clear();
            }

            Node<T> *last_node = tail;
            tail = last_node->prev;
            tail->next = nullptr;
            --size;
            free_memory(last_node);
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
            if (index == size - 1)
            {
                return delete_last_element();
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
                return throw ::std::runtime_error(message_empty);
            }

            auto equal = []<typename V>(const V &data, const V &key) -> bool
            {
                const float PRECISION = 1e-2;
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
            if (prev_node->next == tail)
            {
                return delete_last_element();
            }
            delete_next_node(prev_node);
        }

        void display() const
        {
            std::ostringstream oss;
            Node<T> *current = head;
            while (current != nullptr)
            {
                oss << current->data << " <-> ";
                current = current->next;
            }
            // Remove the last arrow
            std::cout << oss.str().substr(0, oss.str().length() - 5);
        }

        void reverse_display()
        {
            std::ostringstream oss;
            Node<T> *current = tail;
            while (current != nullptr)
            {
                oss << current->data << " <-> ";
                current = current->prev;
            }
            // Remove the last arrow
            std::cout << oss.str().substr(0, oss.str().length() - 5);
        }

    private:
        void delete_next_node(Node<T> *prev_node)
        {
            Node<T> *next_node = prev_node->next;
            prev_node->next = next_node->next;
            next_node->next->prev = prev_node;
            --size;
            free_memory(next_node);
        }

        void free_memory(Node<T> *node)
        {
            delete node;
            node = nullptr;
        }
    };
}