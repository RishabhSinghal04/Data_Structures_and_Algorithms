
#include <iostream>
#include <conio.h>
#include <algorithm>
#include <random>
#include <utility>
#include <vector>

template <typename T>
void assign_random_numbers(std::vector<T> &, const int &, const int &);

/**
 * @brief A function to search a number in an array
 * @tparam T Floating point numbers or integers
 * @param  & An array of numbers
 * @param  & Number to be searched
 * @return index + 1 of the searched number if found, else 0
 */
template <typename T>
size_t sentinel_linear_search(std::vector<T> &, const T &);

template <typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> &numbers)
{
    std::string_view separator{};
    for (const auto &number : numbers)
    {
        out << std::exchange(separator, ", ") << number;
    }
    return out;
}

int main()
{
    using namespace std;

    const int16_t MIN = -100, MAX = 100;
    uint16_t size_of_array;
    int search_element;
    float search_element_float;

    cout << "Enter size of array: ";
    cin >> size_of_array;

    vector<int> integers(size_of_array, 0);
    vector<float> floating_points(size_of_array, 0.0F);

    assign_random_numbers(integers, MIN, MAX);
    cout << integers << '\n';

    cout << "Enter a number to searched: ";
    cin >> search_element;

    size_t index = sentinel_linear_search(integers, search_element);

    index == 0
        ? cout << "\nSearch element not found\n\n"
        : cout << "\nSearch element found at position " << index << "\n\n";

    assign_random_numbers(floating_points, MIN, MAX);
    cout << fixed << floating_points << '\n';

    cout << "Enter a number to be searched: ";
    cin >> search_element_float;

    size_t position_2 = sentinel_linear_search(floating_points, search_element_float);

    position_2 == 0
        ? cout << "\nSearch element not found\n"
        : cout << "\nSearch element found at position " << position_2 << '\n';

    getch();
    return 0;
}

template <typename T>
void assign_random_numbers(std::vector<T> &numbers, const int &MIN, const int &MAX)
{
    if (numbers.empty() || MIN > MAX)
    {
        return;
    }

    std::random_device rd;

    using dist_t = std::conditional_t<std::is_floating_point_v<T>,
                                      std::uniform_real_distribution<>,
                                      std::uniform_int_distribution<>>;
    dist_t dist(MIN, MAX);
    for (auto &number : numbers)
    {
        number = dist(rd);
    }
}

template <typename T>
size_t sentinel_linear_search(std::vector<T> &numbers, const T &search_element)
{
    size_t index = 0ULL;
    const double precision = 1e-2;
    const T last_element = numbers.at(numbers.size() - 1); // Copy last element

    numbers.at(numbers.size() - 1) = search_element; // assign search_element at the end

    // Iterate till the end of array
    while (!(fabs(numbers.at(index) - search_element) < precision))
    {
        ++index;
    }
    numbers.at(numbers.size() - 1) = last_element;

    // "index" is less than index of last_element OR search_element equal to last_element
    return (index < numbers.size() - 1 || fabs(last_element - search_element) < precision)
               ? index + 1
               : 0ULL;
}