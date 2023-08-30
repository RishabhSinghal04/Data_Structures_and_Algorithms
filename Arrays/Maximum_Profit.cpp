/*
 * Maximum profit by buying and selling a share atmost twice
 * Price = [10, 22, 5, 75, 65, 80]
 * Output : 12 + 75 = 87
 * (Buy at 10, sell at 22)
 * (Buy at 5, sell at 80)
 */

#include <iostream>
#include <conio.h>
#include <random>
#include <vector>

template <typename T>
void assign_random_numbers(std::vector<T> &, const uint16_t &, const uint16_t &);

template <typename T>
T max_profit(const std::vector<T> &);

template <typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> &price)
{
    std::string_view separator{};
    for (const auto &num : price)
    {
        out << num << ", ";
    }
    out << "\b\b ";
    return out;
}

int main()
{
    using namespace std;

    const uint16_t MIN = 5, MAX = 100;

    uint16_t size_of_array = 0;
    cout << "Enter size of array : ";
    cin >> size_of_array;

    vector<int> integers(size_of_array, 0);
    vector<double> floating_points(size_of_array, 0.0);

    assign_random_numbers(integers, MIN, MAX);
    cout << integers << '\n';

    cout << "Maximum profit is " << max_profit(integers) << "\n\n";

    assign_random_numbers(floating_points, MIN, MAX);
    cout << floating_points << '\n';

    cout << "Maximum profit is " << max_profit(floating_points) << '\n';

    getch();
    return 0;
}

template <typename T>
void assign_random_numbers(std::vector<T> &price, const uint16_t &MIN, const uint16_t &MAX)
{
    if (price.empty() || MIN > MAX)
    {
        return;
    }

    std::random_device rd;
    using dist_t = std::conditional_t<std::is_floating_point_v<T>,
                                      std::uniform_real_distribution<T>,
                                      std::uniform_int_distribution<T>>;
    dist_t dist(MIN, MAX);

    for (auto &number : price)
    {
        number = dist(rd);
    }
}

template <typename T>
T max_profit(const std::vector<T> &price)
{
    if (price.size() < 2)
    {
        return 0;
    }

    T min_val = (std::is_floating_point_v<T>) ? -9.999999e5F : -99999;
    T first_buy = min_val, first_sell = 0;
    T second_buy = min_val, second_sell = 0;

    for (size_t index = 0; index < price.size(); ++index)
    {
        first_buy = std::max(first_buy, -price.at(index));
        first_sell = std::max(first_sell, first_buy + price.at(index));
        second_buy = std::max(second_buy, first_sell - price.at(index));
        second_sell = std::max(second_sell, second_buy + price.at(index));
    }
    return second_sell;
}