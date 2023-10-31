#pragma once

#include <stdexcept>
#include <optional>

template <typename T>
class Circular_Queue
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
    Node<T> *tail = nullptr;
    size_t size = 0ULL;

public:
    Circular_Queue()
        : tail{nullptr}, size{0ULL} {}

    ~Circular_Queue() { clear(); }

    bool empty() const { return size == 0ULL; }

    /* __Getters__ */
    size_t get_size() const { return size; }

    std::optional<T> front() const
    {
        return empty()
                   ? std::nullopt
                   : std::optional<T>(tail->next->data);
    }

    std::optional<T> back() const
    {
        return empty()
                   ? std::nullopt
                   : std::optional<T>(tail->data);
    }

    void enqueue(const T &data)
    {
        Node<T> *new_node = new Node<T>(data);

        if (empty())
        {
            tail = new_node;
            new_node->next = tail;
        }
        else
        {
            new_node->next = tail->next;
            tail->next = new_node;
            tail = new_node;
        }
        ++size;
    }

    void dequeue()
    {
        if (empty())
        {
            throw std::runtime_error("Underflow");
        }
        if (size == 1ULL)
        {
            return clear();
        }

        Node<T> *temp = tail->next;
        tail->next = temp->next;
        --size;
        temp = nullptr;
    }

private:
    void clear()
    {
        if (empty())
        {
            return;
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
};