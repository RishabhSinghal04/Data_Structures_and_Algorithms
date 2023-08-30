
#include <iostream>
#include <conio.h>
#include <algorithm>
#include <random>
#include <unordered_map>
#include <vector>

template <typename T>
void assign_random_numbers(std::vector<T> &, const int16_t &, const int16_t &);

template <typename T>
void display_distinct_elements(std::vector<T>);

template <typename T>
void display_distinct_elements_hashing(const std::vector<T> &);

template <typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> &numbers)
{
    for (const auto &number : numbers)
    {
        out << number << ", ";
    }
    out << "\b\b ";
    return out;
}

int main()
{
    using namespace std;

    uint16_t size_int_array, size_int_array_2;

    cout << "Enter size of integer array : ";
    cin >> size_int_array;

    cout << "Enter size of another integer array : ";
    cin >> size_int_array_2;

    const int16_t MIN = -10, MAX = 10;

    vector<int> integers(size_int_array, 0);
    vector<int> integers_2(size_int_array_2, 0.0F);
    vector<uint16_t> whole_numbers(10ULL, 0);

    assign_random_numbers(integers, MIN, MAX);
    cout << integers << '\n'
         << "All distinct elements are:-\n";
    display_distinct_elements(integers);

    assign_random_numbers(integers_2, MIN, MAX);
    cout << "\n\n"
         << integers_2 << '\n'
         << "All distinct elements are:-\n";
    display_distinct_elements(integers_2);

    assign_random_numbers(whole_numbers, 0, MAX - 1);
    cout << "\n\n"
         << whole_numbers << '\n'
         << "All distinct elements are:-\n";
    display_distinct_elements_hashing(whole_numbers);

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
void display_distinct_elements(std::vector<T> numbers)
{
    std::stable_sort(numbers.begin(), numbers.end());

    numbers.emplace_back(NULL);
    auto num_it = numbers.begin();

    while (num_it < numbers.end() - 1)
    {
        while (*num_it == *(num_it + 1))
        {
            ++num_it;
        }
        std::cout << *num_it << ", ";
        ++num_it;
    }
    std::cout << "\b\b ";
}

template <typename T>
void display_distinct_elements_hashing(const std::vector<T> &numbers)
{
    std::unordered_map<T, uint16_t> indices;

    for (uint16_t index = 0; index < numbers.size(); ++index)
    {
        indices[numbers.at(index)] = numbers.at(index);
    }

    for (const auto &index : indices)
    {
        std::cout << index.second << ", ";
    }
    std::cout << "\b\b ";
}