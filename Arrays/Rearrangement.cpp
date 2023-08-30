/*
 * Given an array of length N, ranging from 0 to N - 1
 * Rearrange the array such that array[index] = index
 * If element is not present then assign -1 at that index
 * Array = {-1, -1, 6, 1, 9, 3, 2, -1, 4, -1}
 * Output: {-1, 1, 2, 3, 4, -1, 6, -1, -1, 9}
 * Indexes:  0  1  2  3  4   5  6   7   8  9
 */

#include <iostream>
#include <conio.h>
#include <array>
#include <utility>

template <size_t N>
void rearrange_array(std::array<int, N> &);

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
    array<int, size_of_array> integers{-1, -1, 6, 1, 9, 3, 2, -1, 4, -1};

    cout << integers << '\n';
    rearrange_array(integers);

    cout << "\nAfter rearrangement:-\n"
         << integers;

    getch();
    return 0;
}

template <size_t N>
void rearrange_array(std::array<int, N> &integers)
{
    size_t count = 0ULL;
    for (size_t index = 0; index < integers.size(); ++index)
    {
        if (integers.at(index) >= 0 && integers.at(index) != index)
        {
            std::swap(integers.at(index), integers.at(integers.at(index)));
        }
    }
}
