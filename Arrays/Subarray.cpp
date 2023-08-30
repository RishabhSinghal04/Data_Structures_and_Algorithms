
#include <iostream>
#include <conio.h>
#include <random>
#include <utility>
#include <vector>

void assign_random_integers(std::vector<int> &, const int &, const int &);

void subarrays(const std::vector<int> &);

std::ostream &operator<<(std::ostream &out, const std::vector<int> integers)
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
    const int16_t MIN = -100, MAX = 100;

    cout << "Enter size of array: ";
    cin >> size_of_array;

    vector<int> integers(size_of_array, 0);
    assign_random_integers(integers, MIN, MAX);

    cout << integers << "\n\n";

    subarrays(integers);

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

void subarrays(const std::vector<int> &integers)
{
    for (uint32_t i = 0; i < integers.size(); ++i)
    {
        for (uint32_t j = i; j < integers.size(); ++j)
        {
            for (uint32_t k = i; k <= j; ++k)
            {
                std::cout << integers[k] << "  ";
            }
            std::cout << "\n\n";
        }
    }
}

/*
1, 2, 3, 4

start = 0
 1          -> 0 to 0
 1, 2       -> 0 to 1
 1, 2, 3    -> 0 to 2
 1, 2, 3, 4 -> 0 to 3

start = 1
 2          -> 1 to 1
 2, 3       -> 1 to 2
 2, 3, 4    -> 1 to 3

start = 2
 3          -> 2 to 2
 3, 4       -> 2 to 3

start = 3
 4          -> 3 to 3
*/