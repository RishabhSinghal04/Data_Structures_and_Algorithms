// Check if all bits can be made same by single flip

#include <iostream>
#include <conio.h>
#include <string>

bool same_by_single_flip(const std::string &);

int main()
{
    using namespace std;

    string st{}, res_st{};

    cout << "Enter a binary string : ";
    getline(cin >> ws, st);

    same_by_single_flip(res_st)
        ? cout << "All bits can be made same by single flip\n"
        : cout << "All bits cannot be made same by single flip\n";

    getch();
    return 0;
}

bool same_by_single_flip(const std::string &st)
{
    if(st.length() < 2)
    {
        return false;
    }

    uint64_t count_0s = 0ULL;

    for (const auto &character : st)
    {
        if (character == '0')
        {
            ++count_0s;
        }
    }

    return (count_0s == 1 || st.length() - 1 - count_0s == 1) ? true : false;
}