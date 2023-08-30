// Pair equal to given sum

#include <iostream>
#include <conio.h>
#include <algorithm>
#include <random>
#include <vector>

void assign_random_integers(std::vector<int> &, const int &, const int &);

std::pair<size_t, size_t> sum_pair(std::vector<int> &, const int64_t &);

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
    int given_sum = 0;

    cout << "Enter size of array: ";
    cin >> size_of_array;

    pair<size_t, size_t> pair_sum;
    vector<int> integers(size_of_array, 0);

    assign_random_integers(integers, MIN, MAX);
    std::ranges::stable_sort(integers);

    cout << integers << '\n';

    cout << "Enter given sum: ";
    cin >> given_sum;

    pair_sum = sum_pair(integers, given_sum);

    (pair_sum.first == 0 && pair_sum.second == 0)
        ? cout << "No pair is equal to " << given_sum << '\n'
        : cout << "Pair equal to " << given_sum << " is ("
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

std::pair<size_t, size_t> sum_pair(std::vector<int> &integers, const int64_t &x_sum)
{
    if (integers.size() < 2 || !std::ranges::is_sorted(integers))
    {
        return std::make_pair(0, 0);
    }

    int64_t sum = 0;
    size_t start = 0ULL, end = integers.size() - 1;

    while (start < end)
    {
        sum = integers.at(start) + integers.at(end);

        if (sum == x_sum)
        {
            return std::make_pair(start, end);
        }
        else
        {
            (sum < x_sum) ? ++start : --end;
        }
    }
    return std::make_pair(0, 0);
}