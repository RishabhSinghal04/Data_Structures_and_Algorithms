// Frequency of each character (all lower case)

#include <iostream>
#include <conio.h>
#include <array>
#include <string>

template <size_t SIZE>
void frequency_of_characters(const std::string &, std::array<uint64_t, SIZE> &);

int main()
{
    using namespace std;

    string st{};
    const size_t SIZE = 26;
    array<size_t, SIZE> character_frequency{0};

    cout << "Enter a string : ";
    getline(cin >> ws, st);

    frequency_of_characters(st, character_frequency);
    cout << "Character    \t    Frequency\n";

    for (uint64_t index = 0; index < SIZE; ++index)
    {
        if (character_frequency.at(index) > 0)
        {
            cout << "    " << static_cast<char>('a' + index) << "\t\t\t"
                 << character_frequency.at(index) << '\n';
        }
    }

    getch();
    return 0;
}

template <size_t SIZE>
void frequency_of_characters(const std::string &st,
                             std::array<uint64_t, SIZE> &character_frequency)
{
    auto is_lower = [&st]() -> bool
    {
        for (const auto &ch : st)
        {
            if (!std::islower(ch))
            {
                return false;
            }
        }
        return true;
    };

    if (st.empty() || !is_lower())
    {
        return;
    }

    for (const auto &character : st)
    {
        ++character_frequency.at(character - 'a');
    }
}