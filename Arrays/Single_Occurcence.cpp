// Find the element that appears once where every other element appears twice

#include <iostream>
#include <conio.h>
#include <vector>

int element_with_single_occurence(const std::vector<int> &);

std::ostream &operator<<(std::ostream &out, const std::vector<int> &numbers)
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

    vector<int> integers{0, 0, 1, 2, 4, 4, 2, -2, -7, -2, 7, 7, -7};

    cout << integers << '\n'
         << "\nElement which appear once is " << element_with_single_occurence(integers);

    getch();
    return 0;
}

int element_with_single_occurence(const std::vector<int> &numbers)
{
    int result = numbers.at(0);

    for (size_t index = 1; index < numbers.size(); ++index)
    {
        result = result ^ numbers.at(index);
    }
    return result;
}
