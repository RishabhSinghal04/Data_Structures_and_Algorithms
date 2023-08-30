
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
size_t linear_search(std::vector<T> &, const T &);

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
    vector<float> floating_points(size_of_array, 0);

    assign_random_numbers(integers, MIN, MAX);
    cout << integers << '\n';

    cout << "Enter a number to be searched: ";
    cin >> search_element;

    size_t position = linear_search(integers, search_element);

    position == 0
        ? cout << "\nSearch element not found\n\n"
        : cout << "\nSearch element found at position " << position << "\n\n";

    assign_random_numbers(floating_points, MIN, MAX);
    cout << floating_points << '\n';

    cout << "Enter a number to be searched: ";
    cin >> search_element_float;

    size_t position_2 = linear_search(floating_points, search_element_float);

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
size_t linear_search(std::vector<T> &numbers, const T &search_element)
{
    for (size_t index = 0; index < numbers.size(); ++index)
    {
        if ((fabs(numbers.at(index) - search_element) < 1e-2))
        {
            return index + 1;
        }
    }
    return 0ULL;
}