/*
 * Largest Sum Contiguous Subarray
 * A = {-2, -3, 4, -1, -2, 1, 5, -3}
 * Maximum contiguous subarray sum is 7
 * (4 - 1 - 2 + 1 + 5 = 7)
 */

#include <iostream>
#include <conio.h>
#include <random>
#include <vector>

template <typename T>
void assign_random_numbers(std::vector<T> &, const int &, const int &);

template <typename T>
int64_t largest_sum_contiguous_subarray(const std::vector<T> &);

template <typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> &numbers)
{
    for (const auto &num : numbers)
    {
        out << num << ", ";
    }
    out << "\b\b ";
    return out;
}

int main()
{
    using namespace std;

    const int16_t MIN = -10, MAX = 10;
    uint16_t int_array_size, kth_sum;

    cout << "Enter size of integer array: ";
    cin >> int_array_size;

    std::vector<int> integers(int_array_size, 0);

    assign_random_numbers(integers, MIN, MAX);
    cout << integers << '\n';

    cout << largest_sum_contiguous_subarray(integers) << " is the maximum sum" << '\n';

    getch();
    return 0;
}

template <typename T>
void assign_random_numbers(std::vector<T> &numbers, const int &MIN, const int &MAX)
{
    if (numbers.empty() || MIN > MAX)
    {
        return;
    }

    std::random_device rd;
    std::uniform_int_distribution<T> dist(MIN, MAX);

    for (auto &num : numbers)
    {
        num = dist(rd);
    }
}

template <typename T>
int64_t largest_sum_contiguous_subarray(const std::vector<T> &numbers)
{
    int64_t max_sum = INT64_MIN;

    if (numbers.empty())
    {
        return max_sum;
    }

    int64_t sum = 0LL;
    size_t start = 0ULL, end = 0ULL, temp = 0ULL;

    // Calculate max sum of contiguous subarray
    for (size_t index = 0; index < numbers.size(); ++index)
    {
        sum += numbers.at(index);

        if (sum < 0)
        {
            sum = 0LL;
            temp = index + 1;
        }
        else if (sum > max_sum)
        {
            max_sum = sum;
            start = temp;
            end = index;
        }
    }
    // Print subarray with max sum
    std::cout << "Subarray with the maximum sum is ";
    for (size_t index = start; index <= end; ++index)
    {
        std::cout << numbers.at(index) << ", ";
    }
    std::cout << "\b\b " << '\n';

    return (max_sum < 0LL) ? 0LL : max_sum;
}