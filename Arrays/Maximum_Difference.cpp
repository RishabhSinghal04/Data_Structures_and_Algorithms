/*
 * Maximum difference between any two elements such that larger element appears after smaller element
 * A = [2, 3, 10, 6, 4, 8, 1]
 * Output : 8 (as 10 - 2 = 8)
 */

#include <iostream>
#include <conio.h>
#include <random>
#include <vector>

template <typename T>
void assign_random_numbers(std::vector<T> &, const int16_t &, const int16_t &);

template <typename T>
T max_difference(std::vector<T> &);

template <typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> &numbers)
{
    std::string_view separator{};
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

    const int MIN = -10, MAX = 10;

    uint16_t size_of_array = 0;
    cout << "Enter size of array : ";
    cin >> size_of_array;

    vector<int> integers(size_of_array, 0);
    vector<double> floating_points(size_of_array, 0.0);

    assign_random_numbers(integers, MIN, MAX);
    cout << integers << '\n';

    cout << "Maximum difference is " << max_difference(integers) << "\n\n";

    assign_random_numbers(floating_points, MIN, MAX);
    cout << floating_points << '\n';

    cout << "Maximum difference is " << max_difference(floating_points) << '\n';

    getch();
    return 0;
}

template <typename T>
void assign_random_numbers(std::vector<T> &numbers, const int16_t &MIN, const int16_t &MAX)
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

    for (auto &number : numbers)
    {
        number = dist(rd);
    }
}

template <typename T>
T max_difference(std::vector<T> &numbers)
{
    if (numbers.size() < 2)
    {
        return 0ULL;
    }

    T max_diff = 0, min_num = numbers.at(0);

    for (size_t index = 1; index < numbers.size(); ++index)
    {
        if ((numbers.at(index) - min_num) > max_diff)
        {
            max_diff = numbers.at(index) - min_num;
        }
        if (numbers.at(index) < min_num)
        {
            min_num = numbers.at(index);
        }
    }
    return max_diff;
}