
#include <iostream>
#include <conio.h>
#include <algorithm>
#include <cmath>

#include "display_and_set_numbers.h"

template <typename T>
size_t recursive_binary_search(const std::vector<T> &elements, const T &key,
                               size_t start, size_t end)
{
    if (start > end)
    {
        return elements.size();
    }

    auto equal = []<typename V>(const V &first_value, const V &second_value)
    {
        const double PRECISION = 1e-2;
        return (std::is_floating_point_v<V>)
                   ? fabs(first_value - second_value) < PRECISION
                   : first_value == second_value;
    };

    size_t mid = (start + end) / 2ULL;

    if (equal(elements.at(mid), key))
    {
        return mid;
    }
    else if (key < elements.at(mid))
    {
        return recursive_binary_search(elements, key, 0ULL, mid);
    }
    return recursive_binary_search(elements, key, mid + 1, elements.size() - 1);
}

template <typename T>
size_t binary_search(const std::vector<T> &elements, const T &key)
{
    if (elements.empty())
    {
        throw std::runtime_error("empty");
    }
    return recursive_binary_search(elements, key, 0ULL, elements.size() - 1);
}

int main()
{
    using namespace std;

    uint32_t size = 0;

    cout << "Enter number of elements: ";
    cin >> size;

    vector<int> integers(size, 0);
    int key;

    set_random_numbers(integers, -100, 100);
    std::ranges::stable_sort(integers);
    cout << integers << '\n';

    cout << "Enter search element : ";
    cin >> key;

    size_t position = binary_search(integers, key);

    position < integers.size()
        ? cout << key << " found at position " << position + 1 << '\n'
        : cout << key << " not found\n";

    vector<double> floating_points(size, 0);
    double second_key;

    set_random_numbers(floating_points, -100, 100);
    std::ranges::stable_sort(floating_points);
    cout << floating_points << '\n';

    cout << "Enter search element : ";
    cin >> second_key;

    position = binary_search(floating_points, second_key);

    position < floating_points.size()
        ? cout << second_key << " found at position " << position + 1 << '\n'
        : cout << second_key << " not found\n";

    getch();
    return 0;
}