// Find all triplets that sum to a given value

#include <iostream>
#include <conio.h>
#include <algorithm>
#include <random>
#include <tuple>
#include <vector>

void assign_random_integers(std::vector<int> &, const int &, const int &);

void triplet_sum(const std::vector<int> &, const int64_t &);

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

    uint16_t size_of_array = 0;
    const int16_t MIN = -5, MAX = 5;
    int given_sum = 0;

    cout << "Enter size of array: ";
    cin >> size_of_array;

    vector<int> integers(size_of_array, 0);

    assign_random_integers(integers, MIN, MAX);
    cout << integers << '\n';

    cout << "Enter given sum: ";
    cin >> given_sum;

    triplet_sum(integers, given_sum);

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

void triplet_sum(const std::vector<int> &integers, const int64_t &x_sum)
{
    if (integers.size() < 2)
    {
        return;
    }

    const size_t SIZE = integers.size();

    uint32_t start = 0ULL;
    int64_t sum = 0LL, end = 0ULL;
    std::vector<int> temp(SIZE);

    std::ranges::copy(integers, temp.begin());
    std::ranges::stable_sort(temp);

    std::cout << "\nAfter sorting:-\n";
    std::cout << temp << "\nTriplets are:-\n";

    for (size_t index = 0; index < SIZE - 2; ++index)
    {
        if (index > 0 && temp.at(index) == temp.at(index - 1))
        {
            continue;
        }
        start = index + 1;
        end = SIZE - 1;

        while (start < end)
        {
            sum = temp.at(index) + temp.at(start) + temp.at(end);

            if (sum == x_sum)
            {
                std::cout << temp.at(index) << ", "
                          << temp.at(start) << ", "
                          << temp.at(end) << '\n';
                ++start;
                --end;
                while (temp.at(start) == temp.at(start - 1) && start < end)
                {
                    ++start;
                }
                while (temp.at(end) == temp.at(end + 1) && start < end)
                {
                    --end;
                }
            }
            else
            {
                (sum < x_sum) ? ++start : --end;
            }
        }
    }
}