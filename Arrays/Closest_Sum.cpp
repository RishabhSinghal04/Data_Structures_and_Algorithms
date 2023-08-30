// Sum of two values closest to a given value

#include <iostream>
#include <conio.h>
#include <algorithm>
#include <random>
#include <vector>

void assign_random_integers(std::vector<int> &, const int &, const int &);

std::pair<size_t, size_t> closest_sum(std::vector<int> &, const int64_t &);

std::ostream &operator<<(std::ostream &out, const std::vector<int> integers)
{
    for (const auto &integer : integers)
    {
        out << integer << ", ";
    }
    out << "\b\b ";
    return out;
}

int main()
{
    using namespace std;

    uint16_t size_of_array = 0;
    const int16_t MIN = -10, MAX = 100;
    int given_value = 0;

    cout << "Enter size of array: ";
    cin >> size_of_array;

    pair<size_t, size_t> pair_sum;
    vector<int> integers(size_of_array, 0);

    assign_random_integers(integers, MIN, MAX);
    std::ranges::stable_sort(integers);

    cout << integers << '\n';

    cout << "Enter a number: ";
    cin >> given_value;

    pair_sum = closest_sum(integers, given_value);

    (pair_sum.first == 0 && pair_sum.second == 0)
        ? cout << "Array is empty or unsorted\n"
        : cout << "Sum of integers closest to " << given_value << " is ("
               << integers.at(pair_sum.first) << ", "
               << integers.at(pair_sum.second) << ")\n";

    getch();
    return 0;
}

void assign_random_integers(std::vector<int> &integers, const int &MIN, const int &MAX)
{
    std::random_device rd;
    std::uniform_int_distribution dist(MIN, MAX);

    for (auto &integer : integers)
    {
        integer = dist(rd);
    }
}

std::pair<size_t, size_t> closest_sum(std::vector<int> &integers, const int64_t &value_x)
{
    if (integers.size() < 2 || !std::ranges::is_sorted(integers))
    {
        return std::make_pair(0, 0);
    }

    int64_t sum = 0;
    uint32_t min_difference = UINT32_MAX;
    size_t start = 0ULL, end = integers.size() - 1, start_index = 0, end_index = 0;

    while (start < end)
    {
        sum = integers.at(start) + integers.at(end);

        if (abs(sum - value_x) < min_difference)
        {
            min_difference = abs(sum - value_x);
            start_index = start;
            end_index = end;
        }
        (sum > value_x) ? --end : ++start;
    }
    return std::make_pair(start_index, end_index);
}