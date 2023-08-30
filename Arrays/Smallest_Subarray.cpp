/*
 * Smallest subarray with sum greater than a given value
 * A = [11, 4, 45, 6, 0, 19]
 * Given Value = 51
 * Length of subarray is 3 [4, 45, 6]
 */

#include <iostream>
#include <conio.h>
#include <random>
#include <vector>

template <typename T>
void assign_random_numbers(std::vector<T> &, const uint16_t &, const uint16_t &);

template <typename T>
std::pair<size_t, size_t> smallest_subarray(const std::vector<T> &, const T &);

template <typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> &price)
{
    std::string_view separator{};
    for (const auto &num : price)
    {
        out << num << ", ";
    }
    out << "\b\b ";
    return out;
}

int main()
{
    using namespace std;

    const uint16_t MIN = 0, MAX = 100;
    uint16_t size_of_array = 0;

    int val_int;
    double val_float;

    cout << "Enter size of array : ";
    cin >> size_of_array;

    vector<int> integers(size_of_array, 0);
    vector<double> floating_points(size_of_array, 0.0);
    pair<size_t, size_t> indexes;

    auto print_array = []<typename T>(const T &arr, const size_t &start, const size_t &end)
    {
        if (arr.empty() || end > arr.size() || start > end)
        {
            return;
        }
        for (size_t index = start; index < end; ++index)
        {
            cout << arr.at(index) << ", ";
        }
        cout << "\b\b ";
    };

    assign_random_numbers(integers, MIN, MAX);
    cout << integers << '\n';

    cout << "Enter an integer : ";
    cin >> val_int;

    indexes = smallest_subarray(integers, val_int);
    cout << "\nLength of smallest subarray with sum greater than " << val_int << " is "
         << indexes.second << '\n';
    print_array(integers, indexes.first, indexes.second + indexes.first);
    cout << "\n\n";

    assign_random_numbers(floating_points, MIN, MAX);
    cout << floating_points << '\n';

    cout << "Enter a floating point number : ";
    cin >> val_float;

    indexes = smallest_subarray(floating_points, val_float);
    cout << "\nLength of smallest subarray with sum greater than " << val_float << " is "
         << indexes.second << '\n';
    print_array(floating_points, indexes.first, indexes.second + indexes.first);
    cout << '\n';

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
std::pair<size_t, size_t> smallest_subarray(const std::vector<T> &numbers,
                                            const T &value)
{
    if (numbers.empty())
    {
        return std::make_pair(0, 0);
    }

    const size_t SIZE = numbers.size();
    size_t start = 0, end = 0, min_length = SIZE, begin = 0;
    T sum = 0;

    while (end < SIZE)
    {
        while (sum <= value && end < SIZE)
        {
            sum += numbers.at(end);
            ++end;
        }
        while (sum > value && start < SIZE)
        {
            sum -= numbers.at(start);
            ++start;
        }
        if (end - start + 1 < min_length)
        {
            min_length = end - start + 1;
            begin = start - 1;
        }
    }
    return std::make_pair(begin, min_length);
}