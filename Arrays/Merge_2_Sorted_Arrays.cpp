/*
 * Merge two sorted arrays with O(1) extra space
 * A1 = [1, 5, 9, 10, 15, 20]
 * A2 = [2, 3, 8, 13]
 * Output :-
 * A1 = [1, 2, 3, 5, 8, 9]
 * A2 = [10, 15, 20]
 */

#include <iostream>
#include <conio.h>
#include <algorithm>
#include <random>
#include <vector>

void assign_random_integers(std::vector<int> &, const int &, const int &);

void merge_arrays(std::vector<int> &, std::vector<int> &);

std::ostream &operator<<(std::ostream &out, const std::vector<int> integers)
{
    std::string_view separator{};
    for (const auto &integer : integers)
    {
        out << integer << ", ";
    }
    std::cout << "\b\b ";
    return out;
}

int main()
{
    using namespace std;

    uint16_t size_of_array = 0, size_of_array_2 = 0;
    const int16_t MIN = -10, MAX = 100;

    cout << "Enter size of array: ";
    cin >> size_of_array;
    cout << "Enter size of another array: ";
    cin >> size_of_array_2;

    vector<int> integers(size_of_array, 0);
    vector<int> integers_2(size_of_array_2, 0);

    assign_random_integers(integers, MIN, MAX);
    assign_random_integers(integers_2, MIN, MAX);

    stable_sort(integers.begin(), integers.end());
    stable_sort(integers_2.begin(), integers_2.end());

    cout << integers << "\n\n"
         << integers_2 << '\n';

    merge_arrays(integers, integers_2);
    cout << "\nAfter merging:-\n"
         << integers << "\n\n"
         << integers_2 << '\n';

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

void merge_arrays(std::vector<int> &integers, std::vector<int> &integers_2)
{
    if (!std::ranges::is_sorted(integers) || !std::ranges::is_sorted(integers_2))
    {
        return;
    }

    const auto last_index = integers_2.end();
    const auto first_index = integers.begin();

    if (*(last_index - 1) <= *first_index)
    {
        return;
    }

    auto start = integers_2.begin();
    auto end = integers.end() - 1;
    bool swaped = false;

    while (*start < *end && start < last_index && end >= first_index)
    {
        std::swap(*start, *end);
        swaped = true;
        ++start;
        --end;
    }
    if (swaped)
    {
        std::stable_sort(integers.begin(), integers.end());
        std::stable_sort(integers_2.begin(), integers_2.end());
    }
}