/*
 * Closest pair from two sorted arrays
 * A1 = [1, 4 ,5]
 * A2 = [10, 20, 30, 40]
 * X = 32
 * Output : 1 and 30
 */

#include <iostream>
#include <conio.h>
#include <algorithm>
#include <random>
#include <vector>

void assign_random_integers(std::vector<int> &, const int &, const int &);

std::pair<size_t, int64_t> closest_pair(std::vector<int> &, std::vector<int> &, const int64_t &);

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

    uint16_t size_of_array = 0, size_of_array_2;
    const int16_t MIN = -10, MAX = 100;
    int given_value = 0;

    cout << "Enter size of array: ";
    cin >> size_of_array;
    cout << "Enter size of another array: ";
    cin >> size_of_array_2;

    pair<size_t, int> pair_sum;
    vector<int> integers(size_of_array, 0);
    vector<int> integers_2(size_of_array_2, 0);

    assign_random_integers(integers, MIN, MAX);
    assign_random_integers(integers_2, MIN, MAX);

    std::ranges::stable_sort(integers);
    std::ranges::stable_sort(integers_2);

    cout << integers << '\n'
         << integers_2 << "\n\n";

    cout << "Enter a number: ";
    cin >> given_value;

    pair_sum = closest_pair(integers, integers_2, given_value);

    (pair_sum.first == 0 && pair_sum.second == -1)
        ? cout << "Arrays are empty or unsorted\n"
        : cout << "Closest pair from two sorted arrays to " << given_value << " is ("
               << integers.at(pair_sum.first) << ", "
               << integers_2.at(pair_sum.second) << ")\n";

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

std::pair<size_t, int64_t> closest_pair(std::vector<int> &integers,
                                        std::vector<int> &integers_2, const int64_t &value_x)
{
    if (integers.empty() || integers_2.empty() ||
        !std::ranges::is_sorted(integers) || !std::ranges::is_sorted(integers_2))
    {
        return std::make_pair(0, -1);
    }

    uint32_t min_difference = UINT32_MAX;
    int64_t end = integers_2.size() - 1, end_index = 0;
    size_t start = 0ULL, start_index = 0;
    const size_t SIZE_INT_1 = integers.size();

    while (start < SIZE_INT_1 && end >= 0)
    {
        if (abs(integers.at(start) + integers_2.at(end) - value_x) < min_difference)
        {
            min_difference = abs(integers.at(start) + integers_2.at(end) - value_x);
            start_index = start;
            end_index = end;
        }
        (integers.at(start) + integers_2.at(end) > value_x) ? --end
                                                            : ++start;
    }
    return std::make_pair(start_index, end_index);
}