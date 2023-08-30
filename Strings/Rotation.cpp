// Left and right rotation

#include <iostream>
#include <conio.h>
#include <algorithm>
#include <string>

void left_rotation(std::string &, const size_t &);
void right_rotation(std::string &, const size_t &);

int main()
{
    using namespace std;

    string st, st_2;
    size_t num_of_shift = 0;

    cout << "Enter a string : ";
    cin >> st;
    cout << "Enter number of shifts: ";
    cin >> num_of_shift;

    left_rotation(st, num_of_shift);
    cout << "String after left rotation is " << st << "\n\n";

    cout << "Enter a string : ";
    cin >> st_2;
    cout << "Enter number of shifts: ";
    cin >> num_of_shift;

    right_rotation(st_2, num_of_shift);
    cout << "String after right rotation is " << st_2 << '\n';

    getch();
    return 0;
}

void left_rotation(std::string &st, const size_t &num_of_shift)
{
    const size_t temp = num_of_shift % st.length();

    std::reverse(st.begin(), st.begin() + temp);
    std::reverse(st.begin() + temp, st.end());
    std::reverse(st.begin(), st.end());
}

void right_rotation(std::string &st, const size_t &num_of_shift)
{
    const size_t temp = num_of_shift % st.length();
    left_rotation(st, st.length() - temp);
}