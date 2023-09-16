
#include <iostream>
#include <conio.h>
#include <vector>

#include "display_and_set_numbers.h"

template <typename T>
void merge_sort(std::vector<T> &);

template <typename T>
void divide_array(std::vector<T> &, size_t, size_t);

template <typename T>
void merge(std::vector<T> &, size_t, size_t, size_t);

int main()
{
    using namespace std;

    const int MIN = -100, MAX = 100;
    size_t size = 0;

    cout << "Enter number of elements: ";
    cin >> size;
    try
    {
        vector<int> integers(size, 0);
        set_random_numbers(integers, MIN, MAX);

        cout << integers << '\n';

        merge_sort(integers);
        cout << "After sorting:-\n"
             << integers << '\n';
    }
    catch (exception &ex)
    {
        cout << "Exception Caught : " << ex.what() << '\n';
    }

    getch();
    return 0;
}

template <typename T>
void merge_sort(std::vector<T> &arr)
{
    if (arr.empty())
    {
        throw std::runtime_error("empty array");
    }
    else if (arr.size() == 1ULL)
    {
        return;
    }

    divide_array(arr, 0ULL, arr.size() - 1);
}

template <typename T>
void divide_array(std::vector<T> &arr, size_t low, size_t high)
{
    if (low < high)
    {
        size_t mid = (low + high) / 2ULL;

        divide_array(arr, low, mid);
        divide_array(arr, mid + 1, high);

        merge(arr, low, mid, high);
    }
}

template <typename T>
void merge(std::vector<T> &arr, size_t low, size_t mid, size_t high)
{
    size_t left = low, right = mid + 1;
    std::vector<T> temp;
    temp.reserve(arr.size());

    while (left <= mid && right <= high)
    {
        if (arr.at(left) <= arr.at(right))
        {
            temp.emplace_back(arr.at(left));
            ++left;
        }
        else
        {
            temp.emplace_back(arr.at(right));
            ++right;
        }
    }
    while (left <= mid)
    {
        temp.emplace_back(arr.at(left));
        ++left;
    }
    while (right <= high)
    {
        temp.emplace_back(arr.at(right));
        ++right;
    }

    for (size_t index = low; index <= high; ++index)
    {
        arr.at(index) = temp.at(index - low);
    }
}
