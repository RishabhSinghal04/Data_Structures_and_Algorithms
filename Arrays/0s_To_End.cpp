// Move all 0s at the end of array

#include <iostream>
#include <conio.h>
#include <random>
#include <utility>
#include <vector>

void assign_random_integers(std::vector<int> &, const int &, const int &);

void zeros_to_end(std::vector<int> &);

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
    const int16_t MIN = -5, MAX = 5;

    cout << "Enter size of array: ";
    cin >> size_of_array;

    vector<int> integers(size_of_array, 0);
    assign_random_integers(integers, MIN, MAX);

    cout << integers << '\n';

    zeros_to_end(integers);
    cout << "\nAfter moving 0s to end:-\n"
         << integers << '\n';

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

void zeros_to_end(std::vector<int> &integers)
{
    uint32_t count = 0;

    for (size_t index = 0; index < integers.size(); ++index)
    {
        if (integers.at(index) != 0)
        {
            integers.at(count) = integers.at(index);
            ++count;
        }
    }

    while (count < integers.size())
    {
        integers.at(count) = 0;
        ++count;
    }
}