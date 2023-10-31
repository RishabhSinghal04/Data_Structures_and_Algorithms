
#include <iostream>
#include <conio.h>

#include "display_and_set_numbers.h"

template <typename T>
void reverse_array(std::vector<T> &elements, size_t index = 0ULL)
{
    if (index >= elements.size() / 2)
    {
        return;
    }

    std::swap(elements.at(index), elements.at(elements.size() - index - 1));
    reverse_array(elements, index + 1);
}

int main()
{
    using namespace std;

    vector<int> integers(10, 0);
    vector<float> floating_points(11, 0);

    set_random_numbers(integers, -10, 10);
    set_random_numbers(floating_points, -10, 10);

    cout << integers << '\n';
    reverse_array(integers, 0);
    cout << integers << '\n';

    cout << floating_points << '\n';
    reverse_array(floating_points, 2);
    cout << floating_points << '\n';

    getch();
    return 0;
}