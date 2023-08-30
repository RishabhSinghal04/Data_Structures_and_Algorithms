
#include <iostream>
#include <conio.h>
#include <algorithm>
#include <random>
#include <utility>
#include <vector>

template <typename T>
void assign_random_numbers(std::vector<T> &, const int &, const int &);

template <typename T>
int64_t kth_largest_sum(const std::vector<T> &, const uint16_t &);

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

    cout << "Enter Kth largest sum : ";
    cin >> kth_sum;

    cout << "The kth(" << kth_sum << ") largest sum is "
         << kth_largest_sum(integers, kth_sum) << '\n';

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
int64_t kth_largest_sum(const std::vector<T> &numbers, const uint16_t &kth_sum)
{
    if (numbers.empty() || kth_sum == 0)
    {
        return INT64_MIN;
    }

    const size_t SIZE = numbers.size();
    std::vector<T> prefix_sum(SIZE + 1, 0);
    std::vector<T> subarray_sums;
    subarray_sums.reserve(prefix_sum.size() * 2);

    for (size_t index = 1; index <= SIZE; ++index)
    {
        prefix_sum.at(index) = prefix_sum.at(index - 1) + numbers.at(index - 1);
    }

    // Subtracting Prefix Sums
    for (size_t i = 0; i <= SIZE; ++i)
    {
        for (size_t j = i + 1; j <= SIZE; ++j)
        {
            subarray_sums.emplace_back(prefix_sum.at(j) - prefix_sum.at(i));
        }
    }

    std::stable_sort(subarray_sums.begin(), subarray_sums.end(), std::greater<>());
    std::cout << '[' << subarray_sums << "] ";

    return subarray_sums.at(kth_sum - 1);
}