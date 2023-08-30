
#include <iostream>
#include <conio.h>
#include <random>
#include <utility>
#include <vector>

template <typename T>
void assign_random_numbers(std::vector<T> &, const int16_t &, const int16_t &);

template <typename T>
T Min(const std::vector<T> &);

template <typename T>
T second_largest(const std::vector<T> &);

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

    cout << integers << '\n'
         << "Second Largest Number is " << second_largest(integers) << "\n\n"
         << fixed << floating_points << '\n'
         << "Second Largest Number is " << second_largest(floating_points);

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
T Min(const std::vector<T> &numbers)
{
    if (numbers.empty()) // Array is empty
    {
        return -1;
    }
    if (numbers.size() == 1) // Array has only one element
    {
        return numbers.at(1);
    }

    T min_num;
    if (numbers.size() % 2 == 0) // Even number of elements
    {
        min_num = (numbers.at(0) < numbers.at(1)) ? numbers.at(0) : numbers.at(1);
    }
    else // Odd number of elements
    {
        min_num = numbers.at(0);
    }

    for (const auto &number : numbers)
    {
        if (number < number + 1)
        {
            if (number < min_num)
            {
                min_num = number;
            }
        }
        if (number + 1 < number)
        {
            if (number + 1 < min_num)
            {
                min_num = number;
            }
        }
    }
    return min_num;
}

template <typename T>
T second_largest(const std::vector<T> &numbers)
{
    if (numbers.size() < 2)
    {
        return -1;
    }

    T largest_num = 0, second_largest_num = 0;

    if (numbers.at(0) > numbers.at(1))
    {
        largest_num = numbers.at(0);
        second_largest_num = numbers.at(1);
    }
    else
    {
        largest_num = numbers.at(1);
        second_largest_num = numbers.at(0);
    }

    for (size_t index = 2ULL; index < numbers.size(); ++index)
    {
        if (numbers.at(index) > largest_num)
        {
            second_largest_num = largest_num;
            largest_num = numbers.at(index);
        }

        if (numbers.at(index) > second_largest_num && numbers.at(index) != largest_num)
        {
            second_largest_num = numbers.at(index);
        }
    }
    return second_largest_num;
}