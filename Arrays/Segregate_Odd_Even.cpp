
#include <iostream>
#include <conio.h>
#include <random>
#include <utility>
#include <vector>

void assign_random_integers(std::vector<uint16_t> &, const int &, const int &);
void segregate_odd_even(std::vector<uint16_t> &);

std::ostream &operator<<(std::ostream &out, const std::vector<uint16_t> integers)
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

    uint16_t size_of_array = 0;
    int16_t kth_sum = 0;
    const int16_t MIN = 1, MAX = 100;

    cout << "Enter size of array: ";
    cin >> size_of_array;

    vector<uint16_t> integers(size_of_array, 0);
    assign_random_integers(integers, MIN, MAX);

    cout << integers << '\n';

    segregate_odd_even(integers);

    cout << "After segregation of odd numbers to left and even numbers to right:-\n"
         << integers;

    getch();
    return 0;
}

void assign_random_integers(std::vector<uint16_t> &integers, const int &MIN, const int &MAX)
{
    std::random_device rd;
    std::uniform_int_distribution dist(MIN, MAX);

    for (auto &integer : integers)
    {
        integer = dist(rd);
    }
}

void segregate_odd_even(std::vector<uint16_t> &integers)
{
    auto left_it = integers.begin();
    auto right_it = integers.end() - 1;

    while (left_it < right_it)
    {
        // Traverse until an even number is found
        while (*left_it % 2 == 1 && left_it < right_it)
        {
            ++left_it;
        }
        // Traverse until an odd number is found
        while (*right_it % 2 == 0 && left_it < right_it)
        {
            --right_it;
        }
        std::swap(*left_it, *right_it);
    }
}

/*
1, 2, 3, 9, 5, 4, 8, 7, 10, 5
*left = 1, 2
*right = 5

1, 5, 3, 9, 5, 4, 8, 7, 10, 2
*left = 5, 3, 9, 5, 4
*right = 2, 10, 7

1, 5, 3, 9, 5, 7, 8, 4, 10, 2
*left = 7, 8
*right = 4, 8
*/