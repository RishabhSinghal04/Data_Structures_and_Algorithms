/*
 * Difference Array / Range Update Query in O(1)
 * Differnce Array: D[i] = A[i] - A[i - 1] for 0 < i < N and D[0] = A[0]
 * Given an array of length N.
 * Array = {10, 5, 20, 40}
 * Update(0, 1, 10)
 * Output: {20, 15, 20, 40}
 */

#include <iostream>
#include <conio.h>
#include <random>
#include <tuple>
#include <vector>

void assign_random_numbers(std::vector<uint16_t> &, const uint16_t &, const uint16_t &);

void update(std::vector<int16_t> &, const std::tuple<uint16_t, uint16_t, uint16_t> &);
void print_array(std::vector<uint16_t> &, std::vector<int16_t> &);

std::vector<int16_t> difference_array(const std::vector<uint16_t> &);

std::ostream &operator<<(std::ostream &out, const std::vector<uint16_t> &numbers)
{
    std::string_view separator{};
    for (const auto &num : numbers)
    {
        out << num << ", ";
    }
    out << "\b\b ";
    return out;
}

std::ostream &operator<<(std::ostream &out,
                         const std::tuple<uint16_t, uint16_t, uint16_t> &tuple_container)
{
    return out << std::get<0>(tuple_container) << ", "
               << std::get<1>(tuple_container) << ", "
               << std::get<2>(tuple_container);
}

int main()
{
    using namespace std;

    const uint16_t MIN = 0, MAX = 100;
    uint16_t size_of_array = 0;
    tuple<uint16_t, uint16_t, uint16_t> update_value;

    cout << "Enter size of array : ";
    cin >> size_of_array;

    vector<uint16_t> integers(size_of_array, 0);
    vector<int16_t> diff_arr(size_of_array + 1, 0);

    assign_random_numbers(integers, MIN, MAX);
    cout << integers << '\n';

    diff_arr = difference_array(integers);

    update_value = make_tuple(0, 2, 10);
    cout << "\nUpdate(" << update_value << ")\n";
    update(diff_arr, update_value);
    print_array(integers, diff_arr);
    cout << "\n\n";

    update_value = make_tuple(1, 2, 20);
    cout << "\nUpdate(" << update_value << ")\n";
    update(diff_arr, update_value);
    print_array(integers, diff_arr);
    cout << "\n\n";

    update_value = make_tuple(3, 4, 30);
    cout << "\nUpdate(" << update_value << ")\n";
    update(diff_arr, update_value);
    print_array(integers, diff_arr);
    cout << "\n\n";

    update_value = make_tuple(5, 7, 40);
    cout << "\nUpdate(" << update_value << ")\n";
    update(diff_arr, update_value);
    print_array(integers, diff_arr);
    cout << '\n';

    getch();
    return 0;
}

void assign_random_numbers(std::vector<uint16_t> &numbers,
                           const uint16_t &MIN, const uint16_t &MAX)
{
    if (numbers.empty() || MIN > MAX)
    {
        return;
    }

    std::random_device rd;
    std::uniform_int_distribution<uint32_t> dist(MIN, MAX);

    for (auto &num : numbers)
    {
        num = dist(rd);
    }
}

std::vector<int16_t> difference_array(const std::vector<uint16_t> &arr)
{
    std::vector<int16_t> diff_arr(arr.size() + 1, 0);
    diff_arr.at(0) = arr.at(0);

    for (size_t index = 1; index < arr.size(); ++index)
    {
        diff_arr.at(index) = arr.at(index) - arr.at(index - 1);
    }
    return diff_arr;
}

void update(std::vector<int16_t> &diff_arr,
            const std::tuple<uint16_t, uint16_t, uint16_t> &update_value)
{
    diff_arr.at(std::get<0>(update_value)) += std::get<2>(update_value);
    diff_arr.at(std::get<1>(update_value) + 1) -= std::get<2>(update_value);
}

void print_array(std::vector<uint16_t> &arr, std::vector<int16_t> &diff_arr)
{
    arr.at(0) = diff_arr.at(0);
    std::cout << arr.at(0);

    for (size_t index = 1; index < arr.size(); ++index)
    {
        arr.at(index) = arr.at(index - 1) + diff_arr.at(index);
        std::cout << ", " << arr.at(index);
    }
}