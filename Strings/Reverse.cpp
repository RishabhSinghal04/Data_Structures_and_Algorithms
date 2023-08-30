
#include <iostream>
#include <conio.h>
#include <string>

void reverse(std::string &st)
{
    auto begin = st.begin();
    auto end = st.end() - 1;

    while (begin < end)
    {
        std::swap(*begin, *end);
        ++begin;
        --end;
    }
}

int main()
{
    using namespace std;

    string st;

    cout << "Enter a string : ";
    cin >> st;

    cout << st << " in reverse is ";
    reverse(st);
    cout << st;

    getch();
    return 0;
}