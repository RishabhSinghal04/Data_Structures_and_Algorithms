
#include <iostream>
#include <conio.h>
#include <map>
#include <string>

#include "display_and_set_numbers.h"

void Combinations_(const std::string &input, std::string output,
                   const std::map<uint16_t, std::string> &mapping,
                   uint32_t index, std::vector<std::string> &combinations)
{
    if (index >= input.length())
    {
        combinations.emplace_back(output);
        return;
    }

    uint16_t digit = input.at(index) - '0';
    std::string keypad_letters = mapping.at(digit);

    for (uint32_t i = 0; i < keypad_letters.length(); ++i)
    {
        output += keypad_letters.at(i);
        Combinations_(input, output, mapping, index + 1, combinations);
        output.pop_back();
    }
}

bool Are_All_Digits(const std::string &input)
{
    for (const char &character : input)
    {
        if (!isdigit(character))
        {
            return false;
        }
    }
    return true;
}

std::vector<std::string> Combinations(const std::string &input)
{
    std::vector<std::string> combinations;

    if (!Are_All_Digits(input))
    {
        return combinations;
    }

    std::map<uint16_t, std::string> mapping{{0, ""},
                                            {1, ""},
                                            {2, "abc"},
                                            {3, "def"},
                                            {4, "ghi"},
                                            {5, "jkl"},
                                            {6, "mno"},
                                            {7, "pqrs"},
                                            {8, "tuv"},
                                            {9, "wxyz"}};

    Combinations_(input, "", mapping, 0, combinations);
    return combinations;
}

int main()
{
    using namespace std;

    string input;

    cout << "Enter digits: ";
    cin >> input;

    vector<string> combinations = Combinations(input);
    cout << "All combinations of " << input << " are " << combinations << '\n';

    getch();
    return 0;
}