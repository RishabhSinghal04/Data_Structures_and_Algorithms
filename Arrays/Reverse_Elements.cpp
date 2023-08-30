
#include <iostream>
#include <conio.h>
// #include <ranges>
#include <random>
#include <utility>
#include <vector>

void assign_random_integers(std::vector<int> &integers)
{
    const int MIN = -1000, MAX = 1000;

    std::random_device rd;
    std::uniform_int_distribution<int> dist(MIN, MAX);

    /* std::ranges::for_each(integers, [&](int &integer)
                          { return integer = dist(rd); }); */

    for (auto &integer : integers)
    {
        integer = dist(rd);
    }
}

void reverse_elements(std::vector<int> &integers)
{
    auto begin = integers.begin();
    auto end = integers.end() - 1;

    while (begin < end)
    {
        std::swap(*begin, *end);
        ++begin;
        --end;
    }
}

std::ostream &operator<<(std::ostream &out, const std::vector<int> &integers)
{
    std::string_view separator{};
    /* std::ranges::for_each(integers, [&](const int &integer)
                          { out << std::exchange(separator, ", ") << integer; }); */

    for (const auto &integer : integers)
    {
        out << std::exchange(separator, ", ") << integer;
    }

    return out;
}

int main()
{
    using namespace std;

    uint16_t num_of_integers;

    cout << "Enter number of integers: ";
    cin >> num_of_integers;

    vector<int> integers(num_of_integers, 0);

    assign_random_integers(integers);
    cout << "Before Reversing:-\n"
         << integers << '\n';

    reverse_elements(integers);
    cout << "After Reversing:-\n"
         << integers << '\n';

    getch();
    return 0;
}