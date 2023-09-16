
#include <iostream>
#include <conio.h>
#include <vector>

#include "display_and_set_numbers.h"

template <typename T>
void selection_sort(std::vector<T> &vec)
{
    const size_t SIZE = vec.size();

    for (size_t i = 0ULL; i < SIZE; ++i)
    {
        T min_index = i;
        for (size_t j = i + 1; j < SIZE; ++j)
        {
            if (vec.at(j) < vec.at(min_index))
            {
                min_index = j;
            }
        }
        if (min_index != vec.at(i))
        {
            // std::cout << "Swap " << vec.at(i) << " and " << vec.at(min_index) << '\n';
            std::swap(vec.at(i), vec.at(min_index));
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

    selection_sort(integers);
    cout << "After sorting:-\n"
         << integers << '\n';

    getch();
    return 0;
}