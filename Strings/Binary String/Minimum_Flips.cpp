/*
 * Minimum flips of continuous characters to make all characters same in a string
 * st = "00011110001110"
 * Output : 2
 * (convert 1's sequences and all characters are 0 : 000 0000 000 1110 -> 0000000000 000 0)
 */

#include <iostream>
#include <conio.h>
#include <string>

uint32_t number_of_flips(const std::string &);

int main()
{
    using namespace std;

    string st{};

    cout << "Enter a binary string : ";
    getline(cin >> ws, st);

    cout << "Minimum flips of continuous characters to make all characters same are "
         << number_of_flips(st) << '\n';

    getch();
    return 0;
}

uint32_t number_of_flips(const std::string &st)
{
    if (st.length() < 2)
    {
        return 0U;
    }

    const size_t LENGTH = st.length();
    uint32_t flip_count = 0U;

    for (size_t index = 1; index < LENGTH; ++index)
    {
        if (st.at(index - 1) != st.at(index))
        {
            ++flip_count;
        }
    }
    return (flip_count + 1U)/ 2U;
}