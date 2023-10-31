
#include <iostream>
#include <conio.h>
#include <cmath>

uint64_t reverse_number(uint64_t num)
{
    if (num == 0)
    {
        return 0;
    }

    reverse_number(num / 10);
    static uint64_t rev_num;
    return rev_num += (num % 10) * pow(10, static_cast<size_t>(log10(num)));
}

int main()
{
    using namespace std;

    uint64_t num = 0ULL;

    cout << "Enter a number : ";
    cin >> num;

    cout << "Reverse of " << num << " is " << reverse_number(num);

    getch();
    return 0;
}