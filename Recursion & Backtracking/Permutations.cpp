
#include <iostream>
#include <conio.h>
#include <string>

#include "display_and_set_numbers.h"

void Permutations_(std::string &input, uint32_t index,
                   std::vector<std::string> &permutations)
{
    if (index >= input.length())
    {
        permutations.emplace_back(input);
        return;
    }

    for (uint32_t i = index; i < input.length(); ++i)
    {
        std::swap(input.at(i), input.at(index));
        Permutations_(input, index + 1, permutations);
        std::swap(input.at(i), input.at(index));
    }
}

std::vector<std::string> Permutations(std::string &input)
{
    std::vector<std::string> permutations;
    Permutations_(input, 0, permutations);
    return permutations;
}

int main()
{
    using namespace std;

    string input;

    cout << "Enter a string: ";
    cin >> input;

    vector<string> permutations = Permutations(input);
    cout << "All permutations of " << input << " are " << permutations << '\n';

    getch();
    return 0;
}