/*
* Rearrange array such that even positioned elements are greater than odd positioned elements 
* A[i] >= A[i - 1] if 'i' is even
* A[i] <= A[i + 1] if 'i' is odd
* */

#include <iostream>
#include <conio.h>
#include <random>
#include <utility>
#include <vector>

template <typename T>
void assign_random_numbers(std::vector<T> &, const int16_t &, const int16_t &);

template <typename T>
void rearrange_array(std::vector<T> &);

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

    cout << integers << '\n';
    rearrange_array(integers);
    cout << integers << "\n\n";

    cout << fixed << floating_points << '\n';
    rearrange_array(floating_points);
    cout << floating_points << '\n';

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
void rearrange_array(std::vector<T> &numbers)
{
    if (numbers.size() < 2)
    {
        return;
    }
    auto it = numbers.begin() + 1;

    while (it < numbers.end())
    {
        if (*(it - 1) > *it)
        {
            std::swap(*(it - 1), *it);
        }
        it += 2;
    }
}