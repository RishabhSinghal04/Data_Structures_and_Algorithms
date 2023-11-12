
#include <iostream>
#include <conio.h>
#include <string>

#include "display_and_set_numbers.h"

void Subsequence_(const std::string &input, std::string output,
                  uint32_t index, std::vector<std::string> &subsequence)
{
    if (index >= input.length())
    {
        subsequence.emplace_back(output);
        return;
    }

    // Exclude
    Subsequence_(input, output, index + 1U, subsequence);

    // Include
    output += input.at(index);
    Subsequence_(input, output, index + 1U, subsequence);
}

std::vector<std::string> Subsequence(const std::string &input)
{
    std::string output{};
    std::vector<std::string> subsequence;
    Subsequence_(input, output, 0, subsequence);
    return subsequence;
}

int main()
{
    using namespace std;

    string input_st{};
    vector<string> subsequence;

    cout << "Enter a string: ";
    getline(cin >> ws, input_st);

    subsequence = Subsequence(input_st);

    cout << "All subsequence(s) of " << input_st << " is/are " << subsequence << '\n';

    getch();
    return 0;
}