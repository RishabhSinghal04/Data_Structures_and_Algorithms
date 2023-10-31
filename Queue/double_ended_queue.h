#pragma once

#include <stdexcept>

template <typename T>
class Deque
{
    struct Node
    {
        T data;
        Node *next = nullptr;
        Node *prev = nullptr;

        Node()
            : Node({}, nullptr, nullptr) {}

        Node(const T &data)
            : Node(data, nullptr, nullptr) {}

        Node(const T &data, Node *prev, Node *next)
            : data{data}, prev{prev}, next{next} {}
    };

    Node *head = nullptr;
    Node *tail = nullptr;
    size_t size = 0ULL;

public:
    Deque() : head{nullptr}, tail{nullptr}, size{0ULL} {}

    ~Deque()
    {
        while (head != nullptr)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        size = 0ULL;
    }

    bool empty() const { return size == 0; }

    /* _Getters_ */
    size_t get_size() const { return size; }

    const T &front() const
    {
        return empty()
                   ? throw std::runtime_error("Deque is empty")
                   : head->data;
    }

    const T &back() const
    {
        return empty()
                   ? throw std::runtime_error("Deque is empty")
                   : tail->data;
    }

    void push_front(const T &data)
    {
        head = new Node(data, nullptr, head);

        (empty())
            ? tail = head
            : head->next->prev = head;

        ++size;
    }

    void push_back(const T &data)
    {
        tail = new Node(data, tail, nullptr);

        (empty())
            ? head = tail
            : tail->prev->next = tail;

        ++size;
    }

    T pop_front()
    {
        if (empty())
        {
            throw std::runtime_error("Deque is empty");
        }

        T data = std::move(head->data);
        Node *temp = head;

        if (size == 1ULL)
        {
            head = tail = nullptr;
        }
        else
        {
            head = head->next;
            head->prev = nullptr;
        }

        --size;
        temp = nullptr;
        return data;
    }

    T pop_back()
    {
        if (empty())
        {
            throw std::runtime_error("Deque is empty");
        }

        T data = std::move(tail->data);
        Node *temp = tail;

        if (size == 1ULL)
        {
            head = tail = nullptr;
        }
        else
        {
            tail = tail->prev;
            tail->next = nullptr;
        }

        --size;
        temp = nullptr;
        return data;
    }
};
