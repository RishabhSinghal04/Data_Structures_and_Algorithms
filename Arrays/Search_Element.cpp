/*
 * Given a sorted and rotated array
 * Find an element in log(n) time
 * Array = {12, 13, 14, 15, 16, 10, 11}
 */

#include <iostream>
#include <conio.h>
#include <algorithm>
#include <random>
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
size_t rotated_binary_search(const std::vector<T> &, const T &);

template <typename T>
size_t binary_search_(const std::vector<T> &, const T &, size_t, size_t);

template <typename T>
void rotate_left(std::vector<T> &, uint16_t);

template <typename T>
void rotate_right(std::vector<T> &, uint16_t);

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

    stable_sort(integers.begin(), integers.end());
    cout << "\nAfter sorting:-\n"
         << integers << '\n';
    rotate_left(integers, 2);
    cout << "\nAfter rotation to left by 2:-\n"
         << integers << '\n';

    cout << "Enter a number to searched: ";
    cin >> search_element;

    size_t position = rotated_binary_search(integers, search_element);
    position == 0
        ? cout << "\nSearch element not found\n\n"
        : cout << "\nSearch element found at position " << position << "\n\n";

    assign_random_numbers(floating_points, MIN, MAX);
    cout << fixed << floating_points << '\n';

    stable_sort(floating_points.begin(), floating_points.end());
    cout << "\nAfter sorting:-\n"
         << floating_points << '\n';
    rotate_right(floating_points, 2);
    cout << "\nAfter rotation to left by 2:-\n"
         << floating_points << '\n';

    cout << "Enter a number to be searched: ";
    cin >> search_element_float;

    size_t position_2 = rotated_binary_search(floating_points, search_element_float);
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
    for (auto &num : numbers)
    {
        num = dist(rd);
    }
}

template <typename T>
size_t rotated_binary_search(const std::vector<T> &numbers, const T &search_element)
{
    if (numbers.size() < 2)
    {
        return numbers.empty() ? 0ULL : 1ULL;
    }
    return binary_search_(numbers, search_element, 0, numbers.size() - 1);
}

template <typename T>
size_t binary_search_(const std::vector<T> &numbers, const T &search_num, size_t left, size_t right)
{
    if (left > right)
    {
        return 0ULL;
    }

    size_t mid = (left + right) / 2ULL;

    // Element Found
    if (fabs(numbers.at(mid) - search_num) < 1e-4)
    {
        return mid + 1ULL;
    }
    else if (fabs(numbers.at(left) - search_num) < 1e-4)
    {
        return left + 1ULL;
    }
    else if (fabs(numbers.at(right) - search_num) < 1e-4)
    {
        return right + 1ULL;
    }

    // Array from left to mid is sorted
    if (numbers.at(left) <= numbers.at(mid))
    {
        // Check if search number lies in this half
        if (numbers.at(left) <= search_num && numbers.at(mid) >= search_num)
        {
            return binary_search_(numbers, search_num, left, mid - 1);
        }
        // Check if search number lies in this second half array
        return binary_search_(numbers, search_num, mid + 1, right);
    }

    // If array from left to mid is not sorted, then array from mid to right must be sorted
    if (numbers.at(mid) <= search_num && numbers.at(right) >= search_num)
    {
        return binary_search_(numbers, search_num, mid + 1, right);
    }
    return binary_search_(numbers, search_num, left, mid - 1);
}

template <typename T>
void rotate_left(std::vector<T> &numbers, uint16_t num_of_shifts)
{
    num_of_shifts %= numbers.size();
    std::reverse(numbers.begin(), numbers.begin() + num_of_shifts);
    std::reverse(numbers.begin() + num_of_shifts, numbers.end());
    std::reverse(numbers.begin(), numbers.end());
}

template <typename T>
void rotate_right(std::vector<T> &numbers, uint16_t num_of_shifts)
{
    num_of_shifts %= numbers.size();
    uint16_t shift_count = 1;

    while (shift_count <= num_of_shifts)
    {
        T last_element = numbers.at(numbers.size() - 1);

        for (size_t index = numbers.size() - 1; index > 0; --index)
        {
            numbers.at(index) = numbers.at(index - 1);
        }

        numbers.at(0) = last_element;
        ++shift_count;
    }
}