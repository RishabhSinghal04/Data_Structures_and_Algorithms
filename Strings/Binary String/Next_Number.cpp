// Binary representation of next number

#include <iostream>
#include <conio.h>
#include <string>

std::string &next_num(std::string &);

int main()
{
    using namespace std;

    string st{}, res_st{};

    cout << "Enter a binary number : ";
    getline(cin >> ws, st);

    cout << "Binary representation of next number after " << st << " is "
         << next_num(st) << '\n';

    getch();
    return 0;
}

std::string &next_num(std::string &st)
{
    if (st.empty())
    {
        return st;
    }

    int64_t index = st.length() - 1;

    while (index >= 0)
    {
        if (st.at(index) == '0')
        {
            st.at(index) = '1';
            break;
        }
        else
        {
            st.at(index) = '0';
        }
        --index;
    }

    if (index < 0)
    {
        st = '1' + st;
    }
    return st;
}