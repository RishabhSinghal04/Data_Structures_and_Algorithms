
#include <iostream>
#include <conio.h>
#include <string>

bool is_palindrome(const std::string &st, size_t index = 0ULL)
{
    if (index >= st.length())
    {
        return true;
    }
    if (st.at(index) != st.at(st.length() - index - 1))
    {
        return false;
    }
    is_palindrome(st, index + 1);
}

int main()
{
    using namespace std;

    string st{};

    cout << "Enter a string : ";
    getline(cin >> ws, st);

    is_palindrome(st)
        ? cout << st << " is a palindrome string\n"
        : cout << st << " is not a plindrome string\n";

    getch();
    return 0;
}