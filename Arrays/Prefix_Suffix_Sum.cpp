
#include <iostream>
#include <conio.h>
#include <random>
#include <utility>
#include <vector>

template <typename T>
void assign_random_numbers(std::vector<T> &, const int &, const int &);

void assign_random_ranges(std::vector<std::pair<uint16_t, uint16_t>> &,
                          const uint16_t &, const uint16_t &);

template <typename T>
std::vector<T> prefix_sum(const std::vector<T> &);

template <typename T>
std::vector<T> suffix_sum(const std::vector<T> &);

template <typename T>
void prefix_sum_between_range(const std::vector<T> &,
                              const std::vector<std::pair<uint16_t, uint16_t>> &);

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

template <typename T>
std::ostream &operator<<(std::ostream &out, const std::pair<T, T> &range)
{
    out << '[' << range.first << ", " << range.second << ']';
    return out;
}

int main()
{
    using namespace std;

    const int16_t MIN = -10, MAX = 10;
    uint16_t int_array_size, float_array_size;

    cout << "Enter size of integer array: ";
    cin >> int_array_size;
    cout << "Enter size of real number array: ";
    cin >> float_array_size;

    std::vector<int> integers(int_array_size, 0),
        sum_prefix(int_array_size, 0), sum_suffix(int_array_size, 0);

    std::vector<float> floating_points(float_array_size, 0.0F),
        sum_prefix_float(float_array_size, 0), sum_suffix_float(float_array_size, 0);

    std::vector<pair<uint16_t, uint16_t>> ranges_int(int_array_size),
        ranges_float(float_array_size);

    assign_random_numbers(integers, MIN, MAX);
    assign_random_numbers(floating_points, MIN, MAX);

    cout << integers << '\n';
    cout << "Prefix Sum Array : " << (sum_prefix = prefix_sum(integers)) << '\n'
         << "Suffix Sum Array : " << (sum_suffix = suffix_sum(integers)) << '\n';

    assign_random_ranges(ranges_int, 0, int_array_size - 1);
    prefix_sum_between_range(integers, ranges_int);

    cout << '\n'
         << fixed << floating_points << '\n';
    cout << "Prefix Sum Array : " << (sum_prefix_float = prefix_sum(floating_points)) << '\n'
         << "Suffix Sum Array : " << (sum_suffix_float = suffix_sum(floating_points)) << '\n';

    assign_random_ranges(ranges_float, 0, float_array_size - 1);
    prefix_sum_between_range(floating_points, ranges_float);

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
    using dist_t = std::conditional_t<std::is_floating_point_v<T>,
                                      std::uniform_real_distribution<T>,
                                      std::uniform_int_distribution<T>>;
    dist_t dist(MIN, MAX);
    for (auto &num : numbers)
    {
        num = dist(rd);
    }
}

void assign_random_ranges(std::vector<std::pair<uint16_t, uint16_t>> &ranges,
                          const uint16_t &MIN, const uint16_t &MAX)
{
    if (ranges.empty() || MIN > MAX)
    {
        return;
    }

    std::random_device rd;
    std::uniform_int_distribution<uint16_t> dist(MIN, MAX);

    for (auto &range : ranges)
    {
        uint16_t num1 = dist(rd), num2 = dist(rd);
        range = (num1 < num2)
                    ? std::make_pair(num1, num2)
                    : std::make_pair(num2, num1);
    }
}

template <typename T>
std::vector<T> prefix_sum(const std::vector<T> &numbers)
{
    std::vector<T> sum(numbers.size(), 0);
    sum.at(0) = numbers.at(0);

    for (size_t index = 1; index < numbers.size(); ++index)
    {
        sum.at(index) = sum.at(index - 1) + numbers.at(index);
    }
    return sum;
}

template <typename T>
std::vector<T> suffix_sum(const std::vector<T> &numbers)
{
    const size_t SIZE = numbers.size();
    std::vector<T> sum(SIZE, 0);
    sum.at(SIZE - 1) = numbers.at(SIZE - 1);

    for (int64_t index = SIZE - 2; index >= 0; --index)
    {
        sum.at(index) = sum.at(index + 1) + numbers.at(index);
    }
    return sum;
}

template <typename T>
void prefix_sum_between_range(const std::vector<T> &numbers,
                              const std::vector<std::pair<uint16_t, uint16_t>> &ranges)
{
    if (numbers.empty() || ranges.empty())
    {
        return;
    }
    std::vector<T> sum_range(numbers.size(), 0);
    sum_range = prefix_sum(numbers);

    auto sum_ = [&sum_range](const std::pair<uint16_t, uint16_t> &range) -> T
    {
        if (range.first > range.second)
        {
            return 0;
        }
        else if (range.first == range.second)
        {
            return sum_range.at(range.first);
        }
        else if (range.first == 0)
        {
            return sum_range.at(range.second);
        }
        return sum_range.at(range.second) - sum_range.at(range.first - 1);
    };

    for (const auto &range : ranges)
    {
        std::cout << "Sum " << range << " = " << sum_(range) << '\n';
    }
}