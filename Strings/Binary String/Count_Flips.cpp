/*
 * Number of flips to make a binary string alternate
 * st = "0001010111"
 * Number of flips = 2
 *      (0 0 0 1 0 1 0 1 1 1)
 *       1 2 3 4 5 6 7 8 9 10
 * (Flip 2nd and 9th bit)
 */

#include <iostream>
#include <conio.h>
#include <string>

uint32_t min_number_of_flips(const std::string &);
uint32_t number_of_flips(const std::string &, char);

int main()
{
    using namespace std;

    string st{};

    cout << "Enter a binary string : ";
    getline(cin >> ws, st);

    cout << "Minimum number of flips to make \"" << st << "\" alternate are "
         << min_number_of_flips(st) << '\n';

    getch();
    return 0;
}

uint32_t min_number_of_flips(const std::string &st)
{
    return std::min(number_of_flips(st, '0'), number_of_flips(st, '1'));
}

uint32_t number_of_flips(const std::string &st, char binary_digit)
{
    if (st.length() < 2)
    {
        return 0U;
    }

    const size_t LENGTH = st.length();
    uint32_t flip_count = 0U;

    for (size_t index = 0; index < LENGTH; ++index)
    {
        if (binary_digit != st.at(index))
        {
            ++flip_count;
        }
        binary_digit = (binary_digit == '0') ? '1' : '0';
    }
    return flip_count;
}