// Remove all occurrences of a character in a string

#include <iostream>
#include <conio.h>
#include <string>

std::string &remove_character(std::string &, const char &);

int main()
{
    using namespace std;

    char character = '\0';
    string st{}, res_st{};

    cout << "Enter a string : ";
    getline(cin >> ws, st);

    cout << "Enter a character to be removed : ";
    cin.get(character);

    cout << "String after removing all occurrences of '" << character << "' is "
         << remove_character(st, character) << '\n';

    getch();
    return 0;
}

std::string &remove_character(std::string &st, const char &character)
{
    const size_t LENGTH = st.length();
    size_t index_2 = 0ULL;

    for (size_t index = 0; index < LENGTH; ++index)
    {
        if (st.at(index) != character)
        {
            st.at(index_2) = st.at(index);
            ++index_2;
        }
    }

    st.resize(index_2);
    return st;
}