
#include <iostream>
#include <conio.h>
#include <string>

std::string skip_character(const std::string &st, const char &ch, size_t index = 0ULL)
{
    if (index == st.length())
    {
        return "";
    }

    static std::string result;

    return (st.at(index) == ch)
               ? result = "" + skip_character(st, ch, index + 1)
               : result = st.at(index) + skip_character(st, ch, index + 1);
}

int main()
{
    using namespace std;

    string st, result;
    char ch;

    cout << "Enter a string: ";
    getline(cin >> ws, st);

    cout << "Enter a character to be removed: ";
    cin >> ch;

    result = skip_character(st, ch);
    cout << st << " after removal of " << ch << " is " << result << '\n';

    getch();
    return 0;
}