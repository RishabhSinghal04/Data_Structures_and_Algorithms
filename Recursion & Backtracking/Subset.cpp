
#include <iostream>
#include <conio.h>

#include "display_and_set_numbers.h"

template <typename T>
void Subsets_(const std::vector<T> &input, std::vector<T> output,
              uint32_t index, std::vector<std::vector<T>> &subsets)
{
    if (index >= input.size())
    {
        subsets.emplace_back(output);
        return;
    }

    // Exclude
    Subsets_(input, output, index + 1U, subsets);

    // Include
    output.emplace_back(input.at(index));
    Subsets_(input, output, index + 1U, subsets);
}

template <typename T>
std::vector<std::vector<T>> Subsets(const std::vector<T> &input)
{
    std::vector<T> output{};
    std::vector<std::vector<T>> subsets;
    Subsets_(input, output, 0, subsets);
    return subsets;
}

int main()
{
    using namespace std;

    const int MIN = -10, MAX = 10;
    uint16_t num_of_elements = 0;

    cout << "Enter number of elememts: ";
    cin >> num_of_elements;

    vector<int> set(num_of_elements, 0);
    vector<vector<int>> subsets;

    set_random_numbers(set, MIN, MAX);
    subsets = Subsets(set);

    cout << "All subset(s) of " << set << " is/are:-  ";

    for (const auto &row : subsets)
    {
        for(const auto &element : row)
        {
            cout << element << ", ";
        }
        cout << "\b\b \b\n";
    }

    getch();
    return 0;
}