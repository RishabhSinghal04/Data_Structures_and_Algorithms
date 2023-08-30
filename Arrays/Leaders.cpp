/*
 * An element is a leader in an array if all the elements of it's right are smaller than it.
 * Rightmost element is always the leader.
 * {1, 2, 6, 10, 4, 7, 5}
 * Leaders are 10, 7 and 5.
 */

#include <iostream>
#include <conio.h>
#include <random>
#include <utility>
#include <vector>

template <typename T>
void assign_random_numbers(std::vector<T> &, const int16_t &, const int16_t &);

template <typename T>
void display_leaders(const std::vector<T> &);

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

    int16_t size_int_array, size_float_array;

    cout << "Enter size of integer array : ";
    cin >> size_int_array;

    cout << "Enter size of floating point array : ";
    cin >> size_float_array;

    const int16_t MIN = -1000, MAX = 1000;

    vector<int> integers(size_int_array, 0);
    vector<float> floating_points(size_float_array, 0.0F);

    assign_random_numbers(integers, MIN, MAX);
    assign_random_numbers(floating_points, MIN, MAX);

    cout << integers << "\n\nLeader are ";
    display_leaders(integers);

    cout << "\n\n"
         << fixed << floating_points << "\n\nLeaders are ";
    display_leaders(floating_points);

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
                                      std::uniform_real_distribution<>,
                                      std::uniform_int_distribution<>>;
    dist_t dist(MIN, MAX);

    for (auto &number : numbers)
    {
        number = dist(rd);
    }
}

template <typename T>
void display_leaders(const std::vector<T> &numbers)
{
    T max_num = numbers.back();
    std::string_view separator{};

    std::cout << std::exchange(separator, ", ") << max_num;

    for (size_t index = numbers.size() - 2; index > 0; --index)
    {
        if (numbers.at(index) > max_num)
        {
            max_num = numbers.at(index);
            std::cout << std::exchange(separator, ", ") << max_num;
        }
    }
}