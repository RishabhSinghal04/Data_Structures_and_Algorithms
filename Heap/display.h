#pragma once

#include <iostream>
#include <cmath>

#include "heap.h"

template <typename T, typename Compare = std::greater<T>>
std::ostream &operator<<(std::ostream &out, const Heap<T, Compare> &heap)
{
    const size_t SIZE = heap.get_size();
    int64_t level = floor(log2(SIZE));
    size_t gap = 0ULL;

    for (size_t index = 0ULL; index < SIZE; ++index)
    {
        if (index == static_cast<size_t>(pow(2, floor(log2(index + 1)))) - 1)
        {
            gap = static_cast<size_t>(pow(2, level)) - 1;
            out << "\n\n";
            --level;
        }
        out << std::string(gap, ' ') << heap[index];
        gap = pow(2, level + 2) - 1;
    }
    return out;
}
/*

1:             0

2:      1             2

3:   3     4      5      6

4:  7  8  9 10  11 12  13 14

 */