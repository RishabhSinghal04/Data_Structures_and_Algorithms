// Sort an array containing 0, 1 and 2 only without using any sorting algorithm.

#include <iostream>
#include <conio.h>
#include <random>
#include <utility>
#include <vector>

void generate_elements_randomly(std::vector<uint16_t> &, const uint16_t &, const uint16_t &);
void sort_elements(std::vector<uint16_t> &);

std::ostream &operator<<(std::ostream &out, const std::vector<uint16_t> &elements)
{
    std::string_view separator{};
    for (const auto element : elements)
    {
        out << std::exchange(separator, ", ") << element;
    }
    return out;
}

int main()
{
    using namespace std;

    const uint16_t MIN = 0, MAX = 2;
    uint16_t size_of_vec;

    cout << "Enter number of elements: ";
    cin >> size_of_vec;

    vector<uint16_t> integers(size_of_vec, 0U);

    generate_elements_randomly(integers, MIN, MAX);
    cout << integers << '\n';

    sort_elements(integers);
    cout << "\nAfter Sorting:-\n"
         << integers << '\n';

    getch();
    return 0;
}

void generate_elements_randomly(std::vector<uint16_t> &numbers, const uint16_t &MIN, const uint16_t &MAX)
{
    if (numbers.empty() || MIN > MAX)
    {
        return;
    }

    std::random_device rd;
    std::uniform_int_distribution dist(MIN, MAX);

    for (auto &number : numbers)
    {
        number = dist(rd);
    }
}

void sort_elements(std::vector<uint16_t> &elements)
{
    uint16_t left = 0, right = elements.size() - 1;
    for (uint16_t index = 0; index < elements.size() && index <= right;)
    {
        if (elements.at(index) == 0)
        {
            std::swap(elements.at(index), elements.at(left));
            ++left;
            ++index;
        }
        else if (elements.at(index) == 2)
        {
            std::swap(elements.at(index), elements.at(right));
            --right;
        }
        else
        {
            ++index;
        }
    }
}