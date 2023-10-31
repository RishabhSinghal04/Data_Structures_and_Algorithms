
#include <iostream>
#include <conio.h>
#include <vector>

#include "display_and_set_numbers.h"

template <typename T>
size_t linear_search(const std::vector<T> &vec, const T &key, size_t index = 0ULL)
{
    if (index == vec.size())
    {
        return index;
    }

    auto equal = []<typename V>(const V &first_value, const V &second_value)
    {
        const double PRECISION = 1e-2;
        return (std::is_floating_point_v<V>)
                   ? fabs(first_value - second_value) < PRECISION
                   : first_value == second_value;
    };

    return equal(vec.at(index), key)
               ? index
               : linear_search(vec, key, index + 1);
}

int main()
{
    using namespace std;

    vector<int> integers(11);
    vector<float> floating_points(10);

    set_random_numbers(integers, -10, 10);
    set_random_numbers(floating_points, -10, 10);

    cout << integers << '\n'
         << floating_points << '\n';

    int key_int;
    float key_float;

    cout << "Enter an integer to be searched : ";
    cin >> key_int;

    size_t index = linear_search(integers, key_int);

    index < integers.size()
        ? cout << key_int << " found at position " << index + 1 << '\n'
        : cout << key_int << " not found\n";

    cout << "Enter a floating point number to be searched : ";
    cin >> key_float;

    index = linear_search(floating_points, key_float);
    index < floating_points.size()
        ? cout << key_float << " found at position " << index + 1 << '\n'
        : cout << key_float << " not found\n";

    getch();
    return 0;
}