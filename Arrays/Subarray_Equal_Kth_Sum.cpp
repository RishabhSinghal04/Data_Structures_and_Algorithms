
#include <iostream>
#include <conio.h>
#include <random>
#include <utility>
#include <vector>

void assign_random_integers(std::vector<int> &, const int &, const int &);

void subarray_equal_kth_sum(std::vector<int> &, const int16_t &);

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
    int16_t kth_sum = 0;
    const int16_t MIN = 1, MAX = 10;

    cout << "Enter size of array: ";
    cin >> size_of_array;

    vector<int> integers(size_of_array, 0);
    assign_random_integers(integers, MIN, MAX);

    cout << integers << '\n';

    cout << "\nEnter kth sum : ";
    cin >> kth_sum;

    subarray_equal_kth_sum(integers, kth_sum);

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

void subarray_equal_kth_sum(std::vector<int> &integers, const int16_t &kth_sum)
{
    if (kth_sum == 0)
    {
        return;
    }

    int16_t sum_subarray = 0;
    bool is_sum_equal = false;
    auto it = integers.begin();
    auto left_it = integers.begin();

    while (it != integers.end())
    {
        if (sum_subarray == kth_sum)
        {
            is_sum_equal = true;
            break;
        }
        while (sum_subarray > kth_sum && left_it <= it)
        {
            sum_subarray -= *left_it;
            ++left_it;
        }
        if (sum_subarray < kth_sum)
        {
            sum_subarray += *it;
            ++it;
        }
    }

    if (is_sum_equal)
    {
        std::string_view separator{};
        std::cout << "\n== Equal ==\n";

        while (left_it < it)
        {
            std::cout << std::exchange(separator, ", ") << *left_it;
            ++left_it;
        }
    }
    else
    {
        std::cout << "\n-- Not Equal --\n";
    }
}