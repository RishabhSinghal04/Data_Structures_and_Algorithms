/*
 * Given a sorted and rotated array
 * Find an element in log(n) time
 * Array = {12, 13, 14, 15, 16, 10, 11}
 */

#include <iostream>
#include <conio.h>
#include <algorithm>
#include <random>
#include <vector>

template <typename T>
void assign_random_numbers(std::vector<T> &, const int &, const int &);

template <typename T>
void rotate_sorted_array(std::vector<T> &, uint16_t);

template <typename T>
size_t rotation_count(const std::vector<T> &);

template <typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> &numbers)
{
    std::string_view separator{};
    for (const auto &number : numbers)
    {
        out << number << ", ";
    }
    out << "\b\b ";
    return out;
}

int main()
{
    using namespace std;

    const int16_t MIN = -100, MAX = 100;
    uint16_t size_of_array;

    cout << "Enter size of array: ";
    cin >> size_of_array;

    vector<int> integers(size_of_array, 0);
    vector<float> floating_points(size_of_array, 0.0F);

    random_device rd;
    uniform_int_distribution<uint16_t> dist(0, size_of_array);

    assign_random_numbers(integers, MIN, MAX);
    assign_random_numbers(floating_points, MIN, MAX);

    cout << integers << '\n';

    cout << "\nAfter sorting:-\n";
    stable_sort(integers.begin(), integers.end());
    cout << integers << '\n';

    rotate_sorted_array(integers, dist(rd));

    cout << "\nAfter sorting and rotating "
         << rotation_count(integers) << " times:-\n"
         << integers << "\n\n";

    cout << fixed << floating_points << '\n';

    cout << "\nAfter sorting:-\n";
    stable_sort(floating_points.begin(), floating_points.end());
    cout << floating_points << '\n';

    rotate_sorted_array(floating_points, dist(rd));

    cout << "\nAfter sorting and rotating "
         << rotation_count(floating_points) << " times:-\n"
         << floating_points << '\n';

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
void rotate_sorted_array(std::vector<T> &numbers, uint16_t num_of_shifts)
{
    if (!std::is_sorted(numbers.begin(), numbers.end()))
    {
        std::cout << "\n----- Unsorted -----\n";
        return;
    }

    num_of_shifts %= numbers.size();
    std::reverse(numbers.begin(), numbers.begin() + num_of_shifts);
    std::reverse(numbers.begin() + num_of_shifts, numbers.end());
    std::reverse(numbers.begin(), numbers.end());
}

template <typename T>
size_t rotation_count(const std::vector<T> &numbers)
{
    const size_t SIZE = numbers.size();
    size_t left = 0ULL, right = SIZE - 1ULL;

    // Array is sorted and either rotated 0 or SIZE times
    if (numbers.at(left) < numbers.at(right))
    {
        return 0ULL;
    }

    while (left <= right)
    {
        size_t mid = (left + right) / 2ULL;
        T next_element = numbers.at((mid + 1) % SIZE);
        T previous_element = numbers.at((mid - 1 + SIZE) % SIZE);

        if (numbers.at(mid) <= next_element && numbers.at(mid) <= previous_element)
        {
            return mid;
        }
        else if (numbers.at(left) <= numbers.at(mid))
        {
            left = mid + 1;
        }
        else if (numbers.at(right) >= numbers.at(mid))
        {
            right = mid - 1;
        }
    }
    return 0ULL;
}