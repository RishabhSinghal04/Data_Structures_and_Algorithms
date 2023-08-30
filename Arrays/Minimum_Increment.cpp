/*
 * Minimum increment by K operations to make all elements equal
 * Number of operations needed to make all elements of array equal
 * (where a single element can increment an element by K)
 * If not possible return -1
 */

#include <iostream>
#include <conio.h>
#include <algorithm>
#include <random>
#include <vector>

void assign_random_integers(std::vector<uint16_t> &, const uint16_t &, const uint16_t &);

int minimum_increment(const std::vector<uint16_t> &, const uint16_t &);

std::ostream &operator<<(std::ostream &out, const std::vector<uint16_t> integers)
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

    const int16_t MIN = 0, MAX = 20;
    uint16_t size_of_array = 0;
    uint16_t k = 0;
    int num_of_operations = 0;

    cout << "Enter size of array: ";
    cin >> size_of_array;

    vector<uint16_t> integers(size_of_array, 0);

    assign_random_integers(integers, MIN, MAX);
    cout << integers << '\n';

    cout << "\nEnter value of K: ";
    cin >> k;

    num_of_operations = minimum_increment(integers, k);

    (num_of_operations == -1)
        ? cout << "No Operation\n"
        : cout << "Number of operations needed to make all array elements equal are "
               << num_of_operations << '\n';

    k = 3;
    vector<uint16_t> integers_2{4, 7, 19, 16};
    cout << "\n"
         << integers_2 << "\nK = " << k << '\n';

    num_of_operations = minimum_increment(integers_2, k);
    (num_of_operations == -1)
        ? cout << "No Operation\n"
        : cout << "Number of operations needed to make all array elements equal are "
               << num_of_operations << '\n';

    vector<uint16_t> integers_3{4, 4, 4, 4};
    cout << "\n"
         << integers_3 << "\nK = " << k << '\n';

    num_of_operations = minimum_increment(integers_3, k);
    (num_of_operations == -1)
        ? cout << "No Operation\n"
        : cout << "Number of operations needed to make all array elements equal are "
               << num_of_operations << '\n';

    vector<uint16_t> integers_4{4, 2, 6, 8};
    cout << "\n"
         << integers_4 << "\nK = " << k << '\n';

    num_of_operations = minimum_increment(integers_4, k);
    (num_of_operations == -1)
        ? cout << "No Operation\n"
        : cout << "Number of operations needed to make all array elements equal are "
               << num_of_operations << '\n';

    getch();
    return 0;
}

void assign_random_integers(std::vector<uint16_t> &integers, const uint16_t &MIN, const uint16_t &MAX)
{
    std::random_device rd;
    std::uniform_int_distribution dist(MIN, MAX);

    for (auto &integer : integers)
    {
        integer = dist(rd);
    }
}

int minimum_increment(const std::vector<uint16_t> &integers, const uint16_t &k)
{
    if (integers.size() < 2)
    {
        return -1;
    }

    uint16_t max_element = *(std::max_element(integers.begin(), integers.end()));
    uint16_t num_of_operations = 0;

    for (size_t index = 0; index < integers.size() - 1; ++index)
    {
        if (abs(integers.at(index + 1) - integers.at(index)) % k != 0)
        {
            return -1;
        }
        else if ((max_element - integers.at(index)) % k == 0)
        {
            num_of_operations += (max_element - integers.at(index)) / k;
        }
    }
    return num_of_operations + (max_element - integers.back()) / k;
}