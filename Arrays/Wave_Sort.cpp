/*
 * Rearrange elements in the form of wave.
 * {1, 2, 6, 10, 4, 7, 5}
 * OUTPUT:-
 * 2    10      7       6
 *   1      4       5
 */

#include <iostream>
#include <conio.h>
#include <random>
#include <utility>
#include <vector>

template <typename T>
void assign_random_numbers(std::vector<T> &, const int16_t &, const int16_t &);

template <typename T>
void wave_sort(std::vector<T> &);

template <typename T>
void display_elements_in_wave(std::vector<T> &);

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

    cout << integers << "\n\n";
    wave_sort(integers);
    display_elements_in_wave(integers);

    cout << "\n\n"
         << fixed << floating_points << "\n\n";
    wave_sort(floating_points);
    display_elements_in_wave(floating_points);

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
void wave_sort(std::vector<T> &numbers)
{
    if (numbers.empty() || numbers.size() == 1ULL)
    {
        return;
    }
    if (numbers.at(0) < numbers.at(1))
    {
        std::swap(numbers.at(0), numbers.at(1));
    }

    for (size_t index = 2; index < numbers.size() - 1; index += 2)
    {
        if (numbers.at(index) < numbers.at(index - 1))
        {
            std::swap(numbers.at(index), numbers.at(index - 1));
        }
        if (numbers.at(index) < numbers.at(index + 1))
        {
            std::swap(numbers.at(index), numbers.at(index + 1));
        }
    }
}

template <typename T>
void display_elements_in_wave(std::vector<T> &numbers)
{
    for (size_t index = 0; index < numbers.size(); index += 2)
    {
        std::cout << numbers.at(index) << "\t\t";
    }
    std::cout << '\n';
    for (size_t index = 1; index < numbers.size(); index += 2)
    {
        std::cout << '\t' << numbers.at(index) << '\t';
    }
}
