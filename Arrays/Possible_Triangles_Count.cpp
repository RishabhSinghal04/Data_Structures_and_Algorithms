// Count the number of possible triangles

#include <iostream>
#include <conio.h>
#include <algorithm>
#include <random>
#include <vector>

template <typename T>
void assign_random_numbers(std::vector<T> &, const uint16_t &, const uint16_t &);

template <typename T>
uint16_t possible_triangle_count(std::vector<T> &);

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

    const uint16_t MIN = 1, MAX = 10;
    uint16_t size_of_array = 0, triangle_count = 0;

    cout << "Enter size of array : ";
    cin >> size_of_array;

    vector<uint16_t> integers(size_of_array, 0);
    vector<double> floating_points(size_of_array, 0.0);

    assign_random_numbers(integers, MIN, MAX);
    cout << integers << '\n';

    triangle_count = possible_triangle_count(integers);
    cout << "Number of possible triangles is/are " << triangle_count << "\n\n";

    assign_random_numbers(floating_points, MIN, MAX);
    cout << floating_points << '\n';

    triangle_count = possible_triangle_count(floating_points);
    cout << "Number of possible triangles is/are " << triangle_count << '\n';

    getch();
    return 0;
}

template <typename T>
void assign_random_numbers(std::vector<T> &numbers, const uint16_t &MIN, const uint16_t &MAX)
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
uint16_t possible_triangle_count(std::vector<T> &numbers)
{
    if (numbers.size() < 3)
    {
        return 0;
    }

    std::stable_sort(numbers.begin(), numbers.end());
    std::cout << "After sorting:-\n" << numbers << '\n';

    uint16_t count = 0;

    for (size_t index = numbers.size() - 1; index >= 1; --index)
    {
        size_t left = 0ULL, right = index - 1;
        while (left < right)
        {
            if (numbers.at(left) + numbers.at(right) > numbers.at(index))
            {
                count += right - left;
                --right;
            }
            else
            {
                ++left;
            }
        }
    }
    return count;
}