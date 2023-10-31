#pragma once

#include <cmath>
#include <functional>
#include <vector>

template <typename T, typename Compare = std::greater<T>>
class Heap
{
    std::vector<T> heap;
    Compare compare;

public:
    Heap() = default;
    Heap(const size_t &size) { heap.reserve(size); }
    Heap(const size_t &size, Compare compare = Compare())
        : compare{compare} { heap.reserve(size); }

    const size_t get_size() const { return heap.size(); }
    bool empty() { return heap.empty(); }

    T get_max()
    {
        static_assert(!std::is_same<Compare, std::less<T>>::value,
                      "Compare is std::less, use get_min() instead");

        if (empty())
        {
            throw std::runtime_error("empty");
        }
        return heap[0];
    }

    T get_min()
    {
        static_assert(!std::is_same<Compare, std::greater<T>>::value,
                      "Compare is std::greater, use get_max() instead");

        if (empty())
        {
            throw std::runtime_error("empty");
        }
        return heap[0];
    }

    void set_size(const size_t &size) { heap.reserve(size); }

    void insert(const T &data)
    {
        heap.emplace_back(data);
        size_t index = heap.size() - 1;
        heapify_up(index);
    }

    void clear()
    {
        empty()
            ? throw std::runtime_error("empty")
            : heap.clear();
    }

    void delete_key(const T &key)
    {
        if (empty())
        {
            throw std::runtime_error("empty");
        }

        auto equal = []<typename V>(const V &value, const V &key)
        {
            double PRECISION = 1e-2;
            return std::is_floating_point_v<V>
                       ? fabs(value - key) < PRECISION
                       : value == key;
        };

        for (size_t index = 0; index < get_size(); ++index)
        {
            if (equal(heap[index], key))
            {
                std::swap(heap[index], heap[get_size() - 1]);
                break;
            }
        }

        heap.pop_back();
        for (long long index = (get_size() - 2) / 2LL; index >= 0; --index)
        {
            heapify_down(index);
        }
    }

    void sort()
    {
        if (empty())
        {
            throw std::runtime_error("empty");
        }

        std::vector<T> temp;
        temp.reserve(get_size() + 1);

        for (long long index = (get_size() / 2) - 1; index >= 0; --index)
        {
            heapify_down(index);
        }

        for (long long index = get_size() - 1; index > 0; --index)
        {
            std::swap(heap[index], heap[0]);
            temp.emplace_back(heap[index]);
            heap.resize(index);
            heapify_down(0);
        }

        temp.emplace_back(heap[0]);
        heap = temp;
    }

    // __Operator Overloading__
    T &operator[](const size_t &index)
    {
        if (index >= heap.size())
        {
            throw std::out_of_range("index out of range");
        }
        return heap.at(index);
    }

    const T &operator[](const size_t &index) const
    {
        if (index >= heap.size())
        {
            throw std::out_of_range("index out of range");
        }
        return heap.at(index);
    }

private:
    size_t parent_index(const size_t &index)
    {
        return (index == 0ULL) ? 0ULL : (index - 1ULL) / 2ULL;
    }

    size_t left_child_index(const size_t &index)
    {
        return 2ULL * index + 1;
    }

    void heapify_up(const size_t &index)
    {
        size_t root_index = parent_index(index);
        if (index > 0ULL && compare(heap.at(index), heap.at(root_index)))
        {
            std::swap(heap.at(index), heap.at(root_index));
            heapify_up(root_index);
        }
    }

    void heapify_down(const size_t &index)
    {
        size_t largest = index;
        size_t left = left_child_index(index);
        size_t right = left_child_index(index) + 1;

        if (left < get_size() && compare(heap[left], heap[index]))
        {
            largest = left;
        }
        if (right < get_size() && compare(heap[right], heap[largest]))
        {
            largest = right;
        }

        if (largest != index)
        {
            std::swap(heap[largest], heap[index]);
            heapify_down(largest);
        }
    }
};