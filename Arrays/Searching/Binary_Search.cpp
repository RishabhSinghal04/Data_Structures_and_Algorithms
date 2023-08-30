
#include <iostream>
#include <conio.h>
#include <algorithm>
#include <random>
#include <ranges>
#include <utility>
#include <vector>

template <typename T>
void assign_random_numbers(std::vector<T> &, const int &, const int &);

/**
 * @brief A function to search a number in a sorted array
 * @tparam T Floating point numbers or integers
 * @param  & A sorted array of numbers
 * @param  & Number to be searched
 * @return index + 1 of the searched number if found, else 0
 */
template <typename T>
size_t binary_search(std::vector<T> &, const T &);

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

    stable_sort(integers.begin(), integers.end());
    cout << "\nAfter sorting:-\n"
         << integers << '\n';

    size_t position = binary_search(integers, search_element);
    position == 0
        ? cout << "\nSearch element not found\n\n"
        : cout << "\nSearch element found at position " << position << "\n\n";

    assign_random_numbers(floating_points, MIN, MAX);
    cout << fixed << floating_points << '\n';

    cout << "Enter a number to be searched: ";
    cin >> search_element_float;

    stable_sort(floating_points.begin(), floating_points.end());
    cout << "\nAfter sorting:-\n"
         << floating_points << '\n';

    size_t position_2 = binary_search(floating_points, search_element_float);
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
    std::ranges::generate(numbers, [&rd, &dist]()
                          { return dist(rd); });
}

template <typename T>
size_t binary_search(std::vector<T> &numbers, const T &search_element)
{
    if (!std::is_sorted(numbers.begin(), numbers.end()))
    {
        std::cerr << "\n***** UNSORTED *****\n";
        return 0ULL;
    }

    size_t lower_bound = 0ULL, upper_bound = numbers.size() - 1ULL;

    while (lower_bound < upper_bound)
    {
        size_t mid = (lower_bound + upper_bound) / 2ULL;

        if ((fabs(numbers.at(mid) - search_element) < 1e-2))
        {
            return mid + 1ULL;
        }
        else if (search_element < numbers.at(mid))
        {
            upper_bound = mid - 1ULL;
        }
        else
        {
            lower_bound = mid + 1ULL;
        }
    }
    return 0ULL;
}