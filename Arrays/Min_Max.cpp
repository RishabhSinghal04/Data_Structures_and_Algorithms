
#include <iostream>
#include <conio.h>
#include <random>
#include <utility>
#include <vector>

template <typename T>
void assign_random_numbers(std::vector<T> &, const int16_t &, const int16_t &);

template <typename T>
std::pair<T, T> min_max(const std::vector<T> &);

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

    pair<int, int> min_max_integer;
    pair<float, float> min_max_floating_point;
    vector<int> integers(size_int_array, 0);
    vector<float> floating_points(size_float_array, 0.0F);

    assign_random_numbers(integers, MIN, MAX);
    assign_random_numbers(floating_points, MIN, MAX);

    min_max_integer = min_max(integers);
    min_max_floating_point = min_max(floating_points);

    cout << integers << '\n'
         << "Smallest Number is " << min_max_integer.first
         << "\nLargest Number is " << min_max_integer.second << '\n';

    cout << fixed << floating_points << '\n'
         << "Smallest Number is " << min_max_floating_point.first
         << "\nLargest Number is " << min_max_floating_point.second;

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
std::pair<T, T> min_max(const std::vector<T> &numbers)
{
    if (numbers.size() < 2)
    {
        return std::make_pair(0, 0);
    }

    T min_num, max_num;
    size_t index = 0ULL;

    if (numbers.size() % 2 == 0) // Even number of elements
    {
        if (numbers.at(0) < numbers.at(1))
        {
            min_num = numbers.at(0);
            max_num = numbers.at(1);
        }
        else
        {
            min_num = numbers.at(1);
            max_num = numbers.at(0);
        }
        index += 2;
    }
    else // Odd number of elements
    {
        min_num = numbers.front();
        max_num = numbers.front();
        ++index;
    }

    while (index < numbers.size() - 1)
    {
        if (numbers.at(index) < numbers.at(index + 1))
        {
            if (numbers.at(index) < min_num)
            {
                min_num = numbers.at(index);
            }
            if (numbers.at(index + 1) > max_num)
            {
                max_num = numbers.at(index + 1);
            }
        }
        else
        {
            if (numbers.at(index + 1) < min_num)
            {
                min_num = numbers.at(index + 1);
            }
            if (numbers.at(index) > max_num)
            {
                max_num = numbers.at(index);
            }
        }
        index += 2;
    }
    return std::make_pair(min_num, max_num);
}