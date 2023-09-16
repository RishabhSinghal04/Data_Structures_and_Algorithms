
#include <iostream>
#include <conio.h>
#include <vector>

#include "display_and_set_numbers.h"

template <typename T>
void insertion_sort(std::vector<T> &vec)
{
    const size_t SIZE = vec.size();

    for (size_t i = 0ULL; i < SIZE; ++i)
    {
        size_t j = i;
        while (j > 0ULL && vec.at(j) < vec.at(j - 1))
        {
            std::swap(vec.at(j), vec.at(j - 1));
            --j;
        }
    }
}

int main()
{
    using namespace std;

    const int MIN = -100, MAX = 100;
    uint16_t size = 0;

    cout << "Enter number of elements: ";
    cin >> size;

    vector<int> integers(size, 0);
    set_random_numbers(integers, MIN, MAX);

    cout << integers << '\n';

    insertion_sort(integers);
    cout << "After sorting:-\n"
         << integers << '\n';

    getch();
    return 0;
}