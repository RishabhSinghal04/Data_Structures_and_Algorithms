
#include <iostream>
#include <conio.h>
#include <algorithm>
#include <array>
#include <random>
#include <utility>

template <size_t N>
void assign_random_integers(std::array<int, N> &, const int &, const int &);

template <size_t N>
void rotate_left(std::array<int, N> &, uint16_t);

template <size_t N>
void rotate_right(std::array<int, N> &, uint16_t);

template <size_t N>
std::ostream &operator<<(std::ostream &out, const std::array<int, N> integers)
{
    std::string_view separator{};
    for (const auto &integer : integers)
    {
        out << std::exchange(separator, ", ") << integer;
    }
    return out;
}

int main()
{
    using namespace std;

    const uint16_t size_of_array = 10;
    const int16_t MIN = -100, MAX = 100;
    uint16_t num_of_shifts = 0;
    array<int, size_of_array> integers{};

    assign_random_integers(integers, MIN, MAX);
    cout << integers << '\n';

    cout << "Enter number of shifts: ";
    cin >> num_of_shifts;

    rotate_left(integers, num_of_shifts);
    cout << "\nArray of integers after left rotation is:-\n"
         << integers << "\n\n";

    assign_random_integers(integers, MIN, MAX);
    cout << integers << '\n';

    num_of_shifts = 0;
    cout << "Enter number of shifts: ";
    cin >> num_of_shifts;

    rotate_right(integers, num_of_shifts);
    cout << "\nArray of integers after right rotation is:-\n"
         << integers << "\n\n";

    getch();
    return 0;
}

template <size_t N>
void assign_random_integers(std::array<int, N> &integers, const int &MIN, const int &MAX)
{
    std::random_device rd;
    std::uniform_int_distribution dist(MIN, MAX);

    for (auto &integer : integers)
    {
        integer = dist(rd);
    }
}

template <size_t N>
void rotate_left(std::array<int, N> &integers, uint16_t num_of_shifts)
{
    num_of_shifts %= integers.size();
    std::reverse(integers.begin(), integers.begin() + num_of_shifts);
    std::reverse(integers.begin() + num_of_shifts, integers.end());
    std::reverse(integers.begin(), integers.end());
}
/*
 * 1, 2, 3, 4, 5
 * Number of shifts = 2        1, 2 and 3, 4, 5
 * Reverse 1, 2 and 3, 4, 5 -> 2, 1 and 5, 4, 3
 * Reverse 2, 1, 5, 4, 3    -> {3, 4, 5, 1, 2}
 * Rotation (left):-
 * 2, 3, 4, 5, 1
 * 3, 4, 5, 1, 2
 */

template <size_t N>
void rotate_right(std::array<int, N> &integers, uint16_t num_of_shifts)
{
    num_of_shifts %= integers.size();
    uint16_t shift_count = 1;

    while (shift_count <= num_of_shifts)
    {
        int last_element = integers.at(integers.size() - 1);

        for (size_t index = integers.size() - 1; index > 0; --index)
        {
            integers.at(index) = integers.at(index - 1);
        }

        integers.at(0) = last_element;
        ++shift_count;
    }
}
/*
 * 1, 2, 3, 4, 5
 * Rotation:-
 * 5, 1, 2, 3, 4
 * 4, 5, 1, 2, 3
 */