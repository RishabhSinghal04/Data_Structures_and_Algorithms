
#include <iostream>
#include <conio.h>
#include <vector>

#include "display_and_set_numbers.h"

template <typename T>
void Bubble_Sort(std::vector<T> &vec)
{
    const size_t SIZE = vec.size();

    for (size_t i = 0ULL; i < SIZE; ++i)
    {
        bool sorted = true;
        for (size_t j = 0ULL; j < SIZE - i - 1; ++j)
        {
            if (vec.at(j) > vec.at(j + 1))
            {
                std::swap(vec.at(j), vec.at(j + 1));
                sorted = false;
            }
        }
        if (sorted)
        {
            return;
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

    vector<float> floating_points(size, 0.0F);
    set_random_numbers(floating_points, MIN, MAX);

    cout << floating_points << '\n';

    Bubble_Sort(floating_points);
    cout << "After sorting:-\n"
         << floating_points << '\n';

    getch();
    return 0;
}