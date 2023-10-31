#pragma once

#include <vector>

namespace stk
{
    template <typename T>
    class Stack
    {
        size_t max_size = 10ULL;
        std::vector<T> elements{};

    public:
        Stack() = default;
        Stack(const size_t &max_size) : max_size{max_size} {}

        /* _Getters_ */
        const T &top() const { return elements.back(); }
        size_t get_size() const { return elements.size(); }

        /* _Setter_ */
        void set_size(const size_t &max_size) { this->max_size = max_size; }

        bool empty() const { return elements.empty(); }
        bool full() const { return elements.size() == max_size; }

        void push(const T &element)
        {
            if (full())
            {
                throw std::runtime_error("Overflow");
            }

            elements.emplace_back(element);
        }

        void pop()
        {
            if (empty())
            {
                throw std::runtime_error("Underflow");
            }
            elements.erase(elements.begin() + elements.size() - 1);
        }
    };
}