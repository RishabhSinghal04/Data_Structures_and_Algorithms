/*
 * Given a sorted array of length N.
 * Rearrange the array in maximum and minimum form using two pointers technique.
 * Array = {1,2,3,4,5,6,7}
 * Output: {7,1,6,2,5,3,4}
 */

#include <iostream>
#include <conio.h>
#include <algorithm>
#include <random>
#include <vector>

template <typename T>
void assign_random_numbers(std::vector<T> &, const int16_t &, const int16_t &);

template <typename T>
void rearrange_array(std::vector<T> &);

template <typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> &numbers)
{
    std::string_view separator{};
    for (const auto &num : numbers)
    {
        out << num << ", ";
    }
    out << "\b\b ";
    return out;
}

int main()
{
    using namespace std;

    const int MIN = -10, MAX = 10;

    uint16_t size_of_array = 0;
    cout << "Enter size of array : ";
    cin >> size_of_array;

    vector<int> integers(size_of_array, 0);
    vector<double> floating_points(size_of_array, 0.0);

    assign_random_numbers(integers, MIN, MAX);
    cout << integers << '\n';

    stable_sort(integers.begin(), integers.end());
    cout << "After sorting :-\n"
         << integers << '\n';

    rearrange_array(integers);
    cout << "After rearrangement:-\n"
         << integers << "\n\n";

    assign_random_numbers(floating_points, MIN, MAX);
    cout << floating_points << '\n';

    stable_sort(floating_points.begin(), floating_points.end());
    cout << "After sorting :-\n"
         << floating_points << '\n';

    rearrange_array(floating_points);
    cout << "After rearrangement:-\n"
         << floating_points << '\n';

    getch();
    return 0;
}

template <typename T>
void assign_random_numbers(std::vector<T> &numbers, const int16_t &MIN, const int16_t &MAX)
{
    if (numbers.empty() || MIN > MAX)
    {
        return;
    }

    std::random_device rd;
    using dist_t = std::conditional_t<std::is_floating_point_v<T>,
                                      std::uniform_real_distribution<T>,
                                      std::uniform_int_distribution<T>>;
    dist_t dist(MIN, MAX);

    for (auto &number : numbers)
    {
        number = dist(rd);
    }
}

template <typename T>
void rearrange_array(std::vector<T> &numbers)
{
    if (!std::is_sorted(numbers.begin(), numbers.end()) | numbers.size() < 2)
    {
        return;
    }

    size_t left = 0ULL, right = numbers.size() - 1ULL;
    std::vector<T> temp(numbers.size(), 0);

    for (size_t index = 0; index < temp.size(); ++index)
    {
        temp.at(index) = (index % 2 == 0)
                             ? numbers.at(right--)
                             : numbers.at(left++);
    }
    
    numbers.clear();
    for (const auto &element : temp)
    {
        numbers.emplace_back(element);
    }
}