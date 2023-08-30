/*
 * Reorder an array according to given indexes
 * Giver two integer arrays of same size
 * Array = {50, 40, 70, 60, 90}
 * Index = { 3,  0,  4,  1,  2}
 * Output: {40, 60, 90, 50, 70}
 * Indexes:  0,  1,  2,  3,  4
 */

#include <iostream>
#include <conio.h>
#include <algorithm>
#include <random>
#include <unordered_set>
#include <vector>

template <typename T>
void assign_random_integers(std::unordered_set<T> &, const uint16_t &, const int &, const int &);
template <typename T>
void assign_random_integers(std::vector<T> &, const int &, const int &);

// Positive Integers Only
template <typename T, typename U>
void reorder(std::vector<T> &, std::unordered_set<U> &);

template <typename T, typename U>
void reorder_using_extra_space(std::vector<T> &, std::unordered_set<U> &);

template <template <typename...> class U, typename T>
std::ostream &operator<<(std::ostream &out, const U<T> integers)
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

    uint16_t size_of_array;
    const int32_t MIN = -10, MAX = 10;

    unordered_set<uint16_t> indexes;

    cout << "Enter size of arrays: ";
    cin >> size_of_array;

    vector<int> integers(size_of_array, 0), integers_2(size_of_array, 0);

    assign_random_integers(integers, MIN, MAX);
    assign_random_integers(indexes, size_of_array, 0, size_of_array - 1);

    cout << "Integers : " << integers << '\n';
    cout << " Indexes : " << indexes << '\n';

    reorder_using_extra_space(integers, indexes);

    cout << "\nAfter reordering (using extra space):-\n"
         << integers << "\n\n";

    indexes.clear();

    assign_random_integers(integers_2, 0, MAX);
    assign_random_integers(indexes, size_of_array, 0, size_of_array - 1);

    cout << "Integers : " << integers_2 << '\n';
    cout << " Indexes : " << indexes << '\n';

    reorder(integers_2, indexes);

    cout << "\nAfter reordering:-\n"
         << integers_2 << '\n';

    getch();
    return 0;
}

template <typename T>
void assign_random_integers(std::unordered_set<T> &integers, const uint16_t &SIZE, const int &MIN, const int &MAX)
{
    if (SIZE == 0 || MIN > MAX)
    {
        return;
    }

    std::random_device rd;
    std::uniform_int_distribution<T> dist(MIN, MAX);
    while (integers.size() < SIZE)
    {
        integers.insert(dist(rd));
    }
}

template <typename T>
void assign_random_integers(std::vector<T> &integers, const int &MIN, const int &MAX)
{
    if (integers.empty() || MIN > MAX)
    {
        return;
    }

    std::random_device rd;
    std::uniform_int_distribution<T> dist(MIN, MAX);
    for (auto &integer : integers)
    {
        integer = dist(rd);
    }
}

template <typename T, typename U>
void reorder(std::vector<T> &integers, std::unordered_set<U> &indexes)
{
    auto index_it = indexes.begin();
    T max_int = *(std::ranges::max_element(integers)) + 1;

    for (size_t index = 0; index < integers.size() && index_it != indexes.end(); ++index)
    {
        integers[*index_it] = integers[*index_it] % max_int +
                              (integers[index] % max_int) * max_int;
        ++index_it;
    }

    for (auto &integer : integers)
    {
        integer /= max_int;
    }
}

template <typename T, typename U>
void reorder_using_extra_space(std::vector<T> &integers, std::unordered_set<U> &indexes)
{
    std::vector<T> temp(integers.size());
    auto int_it = integers.begin();
    auto index_it = indexes.begin();

    for (; index_it != indexes.end() && int_it != integers.end(); ++index_it, ++int_it)
    {
        temp[*index_it] = *int_it;
    }

    integers.clear();
    for (const auto &integer : temp)
    {
        integers.emplace_back(integer);
    }
}