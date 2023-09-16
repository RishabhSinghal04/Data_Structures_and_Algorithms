
#include <iostream>
#include <conio.h>
#include <vector>

#include "display_and_set_numbers.h"

template <typename T>
void quick_sort(std::vector<T> &);

template <typename T>
void divide_array(std::vector<T> &, int64_t, int64_t);

template <typename T>
int64_t partition(std::vector<T> &, int64_t, int64_t);

int main()
{
    using namespace std;

    const int MIN = -100, MAX = 100;
    int16_t size = 0;

    cout << "Enter number of elements: ";
    cin >> size;
    try
    {
        vector<float> integers(size, 0);
        set_random_numbers(integers, MIN, MAX);

        cout << integers << '\n';

        quick_sort(integers);
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
void quick_sort(std::vector<T> &arr)
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
void divide_array(std::vector<T> &arr, int64_t low, int64_t high)
{
    if (low < high)
    {
        int64_t partition_index = partition(arr, low, high);
        divide_array(arr, low, partition_index - 1);
        divide_array(arr, partition_index + 1, high);
    }
}

template <typename T>
int64_t partition(std::vector<T> &arr, int64_t low, int64_t high)
{
    T pivot = arr.at(low);
    int64_t start = 0ULL, end = high;
    // Move elements smaller than pivot to left and move elements greater than pivot to right
    while (start < end)
    {
        while (arr.at(start) <= pivot && start < high)
        {
            ++start;
        }
        while (arr.at(end) > pivot && end > low)
        {
            --end;
        }

        if (start < end)
        {
            std::swap(arr.at(start), arr.at(end));
        }
    }
    std::swap(arr.at(low), arr.at(end));
    return end;
}