
#include <iostream>
#include <conio.h>
#include <random>
#include <vector>

template <typename T>
void assign_random_numbers(std::vector<T> &, const int &, const int &);

template <typename T>
uint64_t peak_element_index(const std::vector<T> &);

template <typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> &numbers)
{
    std::string_view separator{};
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

    const int16_t MIN = -100, MAX = 100;
    uint16_t size_of_array;

    cout << "Enter size of array: ";
    cin >> size_of_array;

    vector<int> integers(size_of_array, 0);
    vector<float> floating_points(size_of_array, 0.0F);

    assign_random_numbers(integers, MIN, MAX);
    cout << integers << '\n';

    size_t position = peak_element_index(integers);
    position == 0ULL
        ? cout << "\nNo peak element\n"
        : cout << "\nPosition of peak element in array is " << position << "\n\n";

    assign_random_numbers(floating_points, MIN, MAX);
    cout << fixed << floating_points << '\n';

    size_t position_2 = peak_element_index(floating_points);
    position_2 == 0ULL
        ? cout << "\nNo peak element\n"
        : cout << "\nPosition of peak element in array is " << position_2 << '\n';

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
                                      std::uniform_real_distribution<>,
                                      std::uniform_int_distribution<>>;
    dist_t dist(MIN, MAX);
    for(auto&num : numbers)
    {
        num = dist(rd);
    }
}

template <typename T>
uint64_t peak_element_index(const std::vector<T> &numbers)
{
    if (numbers.empty())
    {
        return 0ULL;
    }

    size_t start = 0ULL, end = numbers.size() - 1ULL;

    while (start < end)
    {
        size_t mid = (start + end) / 2ULL;
        if (numbers.at(mid) > numbers.at(mid + 1))
        {
            end = mid;
        }
        else
        {
            start = mid + 1ULL;
        }
    }
    return start + 1;
}