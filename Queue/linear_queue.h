#pragma once

#include <stdexcept>

template <typename T>
class Queue
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
    Node<T> *tail = nullptr;
    size_t size = 0ULL;

public:
    Queue()
        : head{nullptr}, tail{nullptr}, size{0ULL} {}

    ~Queue() { clear(); }

    bool empty() const { return size == 0ULL; }

    /* __Getters__ */
    const T get_size() const { return size; }

    const T &front() const
    {
        return empty()
                   ? throw std::runtime_error("queue is empty")
                   : head->data;
    }

    const T &back() const
    {
        return (empty())
                   ? throw std::runtime_error("queue is empty")
                   : tail->data;
    }

    void enqueue(const T &data)
    {
        Node<T> *new_node = new Node<T>(data);

        if(tail != nullptr)
        {
            tail->next = new_node;
        }
        tail = new_node;

        if (head == nullptr)
        {
            head = tail;
        }
        ++size;
    }

    void dequeue()
    {
        if (empty())
        {
            throw std::runtime_error("Underflow");
        }
        else if (size == 1ULL)
        {
            clear();
            return;
        }

        Node<T> *temp = head->next;
        head = nullptr;
        head = temp;
        --size;
        temp = nullptr;
    }

private:
    void clear()
    {
        Node<T> *next = nullptr;
        while (head != nullptr)
        {
            next = head->next;
            head = nullptr;
            head = next;
        }
        tail = nullptr;
        size = 0ULL;
    }
};