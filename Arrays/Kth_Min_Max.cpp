
#include <iostream>
#include <conio.h>
#include <algorithm>
#include <random>
#include <ranges>
#include <set>
#include <utility>

template <typename T>
void assign_random_numbers(std::set<T> &, const uint16_t &, const int &, const int &);

template <typename T>
void Kth_Min_Max(std::set<T> &, const uint16_t &, const uint16_t &);

template <typename T>
std::ostream &operator<<(std::ostream &out, const std::set<T> &numbers)
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

    int16_t size_int_set, size_float_set;
    uint16_t kth_min = 0, kth_max = 0;

    const int16_t MIN = -1000, MAX = 1000;

    set<int> integers;
    set<float> floating_points;

    cout << "Enter size of integer array : ";
    cin >> size_int_set;

    cout << "Enter size of floating point array : ";
    cin >> size_float_set;

    assign_random_numbers(integers, size_int_set, MIN, MAX);
    assign_random_numbers(floating_points, size_float_set, MIN, MAX);

    cout << integers << "\n\n";

    cout << "Enter kth minimum element : ";
    cin >> kth_min;

    cout << "Enter kth maximum element : ";
    cin >> kth_max;

    Kth_Min_Max(integers, kth_min, kth_max);

    cout << fixed << '\n'
         << floating_points << "\n\n";

    kth_max = 0;
    kth_min = 0;

    cout << "Enter kth minimum element : ";
    cin >> kth_min;

    cout << "Enter kth maximum element : ";
    cin >> kth_max;

    Kth_Min_Max(floating_points, kth_min, kth_max);

    getch();
    return 0;
}

template <typename T>
void Kth_Min_Max(std::set<T> &numbers, const uint16_t &kth_min, const uint16_t &kth_max)
{
    auto it_kth_min = numbers.cbegin();
    auto it_kth_max = numbers.crbegin();

    advance(it_kth_min, kth_min - 1);
    advance(it_kth_max, kth_max - 1);

    std::cout << "\nKth minimum element is " << *it_kth_min << '\n'
              << "Kth maximum element is " << *it_kth_max << '\n';
}

template <typename T>
void assign_random_numbers(std::set<T> &numbers, const uint16_t &SIZE, const int &MIN, const int &MAX)
{
    if (SIZE == 0 || MIN > MAX)
    {
        return;
    }

    std::random_device rd;

    using dist_t = std::conditional_t<std::is_floating_point_v<T>,
                                      std::uniform_real_distribution<>,
                                      std::uniform_int_distribution<>>;
    dist_t dist(MIN, MAX);
    std::generate_n(std::inserter(numbers, numbers.end()), SIZE, [&rd, &dist]()
                    { return dist(rd); });
}