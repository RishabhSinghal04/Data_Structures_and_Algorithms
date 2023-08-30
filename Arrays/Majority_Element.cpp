// An elemenet that appears more than N/2 times, where N is size of array

#include <iostream>
#include <conio.h>
#include <random>
#include <vector>

void assign_random_integers(std::vector<int> &, const int &, const int &);

int majority_element(std::vector<int> &);

std::ostream &operator<<(std::ostream &out, const std::vector<int> integers)
{
    std::string_view separator{};
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
    const int16_t MIN = -2, MAX = 2;
    int majority_element_int;

    cout << "Enter size of array: ";
    cin >> size_of_array;

    vector<int> integers(size_of_array, 0);
    assign_random_integers(integers, MIN, MAX);

    cout << integers << '\n';

    majority_element_int = majority_element(integers);

    (majority_element_int == INT_MIN)
        ? cout << "No majority element\n"
        : cout << "Mjority element is " << majority_element_int << '\n';

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

int majority_element(std::vector<int> &integers)
{
    if (integers.size() < 2)
    {
        return integers.empty() ? -1 : integers.front();
    }

    const size_t SIZE = integers.size();
    int element = integers.front();
    uint16_t count = 1;

    for (size_t index = 1; index < SIZE; ++index)
    {
        if (count == 0)
        {
            element = integers.at(index);
            count = 1;
        }
        else
        {
            element == integers.at(index)
                ? ++count
                : --count;
        }
    }
    count = 0;
    for (const auto &integer : integers)
    {
        if (element == integer)
        {
            ++count;
        }
    }
    return (count > SIZE / 2) ? element : INT_MIN;
}
/*
4, 5, 4, 9, 4, 4

        i = 1   2       3       4       5
        4==5    c==0    4==9    c==0    4==4
c = 1   0       1       0       1       2
e = 4           4               4
*/