
#include <iostream>
#include <conio.h>
#include <random>
#include <utility>
#include <vector>

void assign_random_integers(std::vector<int> &, const int &, const int &);

void shift_negative_numbers_left(std::vector<int> &);
void shift_negative_numbers_right(std::vector<int> &);

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

    cout << integers << '\n';

    shift_negative_numbers_left(integers);
    cout << "\nAfter shifting negative numbers towards left:-\n " << integers << '\n';

    assign_random_integers(integers, MIN, MAX);
    cout << '\n'
         << integers << '\n';

    shift_negative_numbers_right(integers);
    cout << "\nAfter shifting negative numbers towards right:-\n " << integers << '\n';

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

void shift_negative_numbers_left(std::vector<int> &integers)
{
    auto it_left = integers.begin();
    auto it = it_left;

    while (it < integers.end())
    {
        if (*it < 0)
        {
            std::swap(*it_left, *it);
            ++it_left;
        }
        ++it;
    }
}

void shift_negative_numbers_right(std::vector<int> &integers)
{
    auto it_left = integers.begin();
    auto it = it_left;

    while (it < integers.end())
    {
        if (*it >= 0)
        {
            std::swap(*it_left, *it);
            ++it_left;
        }
        ++it;
    }
}