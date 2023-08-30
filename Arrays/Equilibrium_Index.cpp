// An index such that sum of elements at lower indexes = sum of elements at higher indexes

#include <iostream>
#include <conio.h>
#include <random>
#include <vector>

void assign_random_integers(std::vector<int> &, const int &, const int &);

uint64_t Equilibrium_Index(const std::vector<int> &);

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

    const int16_t MIN = -10, MAX = 10;
    uint16_t size_of_array = 0;
    size_t equilibrium_index = 0ULL;

    cout << "Enter size of array: ";
    cin >> size_of_array;

    vector<int> integers(size_of_array, 0);

    assign_random_integers(integers, MIN, MAX);
    cout << integers << '\n';

    equilibrium_index = Equilibrium_Index(integers);

    (equilibrium_index == 0ULL)
        ? cout << "No Equilibrium Index\n"
        : cout << "Equilibrium Index is " << equilibrium_index << '\n';

    vector<int> integers_2{-7, 1, 5, 2, -4, 3, 0};
    cout << '\n'
         << integers_2 << '\n';

    equilibrium_index = Equilibrium_Index(integers_2);

    (equilibrium_index == 0ULL)
        ? cout << "No Equilibrium Index\n"
        : cout << "Equilibrium Index is " << equilibrium_index << '\n';

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

uint64_t Equilibrium_Index(const std::vector<int> &integers)
{
    if (integers.size() < 2)
    {
        return 0ULL;
    }

    const size_t SIZE = integers.size();
    size_t pivot = 0ULL;
    int sum_left = 0, sum_right = 0;

    for (const auto &element : integers)
    {
        sum_right += element;
    }

    while (pivot < SIZE - 1ULL)
    {
        ++pivot;
        sum_left += integers.at(pivot - 1);
        sum_right -= integers.at(pivot);

        if (sum_left == sum_right)
        {
            return pivot + 1ULL;
        }
    }
    return 0ULL;
}