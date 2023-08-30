// Sort string of characters (all lower case)

#include <iostream>
#include <conio.h>
#include <string>
#include <vector>

std::string &sort_characters(std::string &);

int main()
{
    using namespace std;

    string st{}, res_st{};

    cout << "Enter a string : ";
    getline(cin >> ws, st);

    res_st = st;
    res_st = sort_characters(res_st);
    (res_st == st)
        ? cout << "Lower case or small letters only\n"
        : cout << "String after sorting all characters is " << res_st << '\n';

    getch();
    return 0;
}

std::string &sort_characters(std::string &st)
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

    if (st.length() < 2 || !is_lower())
    {
        return st;
    }

    const size_t LENGTH = st.length();
    const uint16_t TOTAL_LOWER_CASE_CHARACTERS = 26;
    std::vector<uint16_t> char_frequency(TOTAL_LOWER_CASE_CHARACTERS, 0);

    for (const auto &character : st)
    {
        ++char_frequency.at(character - 'a');
    }

    char ch = 'a';
    st.clear();

    for (size_t index = 0; index < char_frequency.size(); ++index)
    {
        while (char_frequency.at(index) > 0)
        {
            st += ch;
            --char_frequency.at(index);
        }
        ++ch;
    }
    return st;
}