#pragma once

#include <iostream>
#include <concepts>
#include <random>
#include <vector>

template <typename CH>
concept CHAR = (std::is_same_v<CH, char> || std::is_same_v<CH, const char>);

template <typename B>
concept BOOL = std::is_same_v<B, bool>;

template <typename N>
concept Numeric = (std::is_arithmetic_v<N> && !(CHAR<N> || BOOL<N>));

template <typename I>
concept Integer = (Numeric<I> && (!std::is_floating_point_v<I>));

template <Numeric N, Integer I>
void set_random_numbers(std::vector<N> &numbers, const I &MIN, const I &MAX)
{
    if (numbers.empty())
    {
        throw std::runtime_error("empty");
    }
    else if (MIN > MAX)
    {
        throw std::runtime_error("range : MIN is greater than MAX");
    }

    std::random_device rd;
    using dist_t = std::conditional_t<std::is_floating_point_v<N>,
                                      std::uniform_real_distribution<>,
                                      std::uniform_int_distribution<>>;
    dist_t dist(MIN, MAX);

    for (auto &num : numbers)
    {
        num = dist(rd);
    }
}

template <typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> &vec)
{
    for (const auto &element : vec)
    {
        out << element << ", ";
    }
    out << "\b\b \b";

    return out;
}

template <typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<std::pair<T, T>> &vec)
{
    for (const auto &element : vec)
    {
        out << "(" << element.first << ", " << element.second << "), ";
    }
    out << "\b\b \b";

    return out;
}