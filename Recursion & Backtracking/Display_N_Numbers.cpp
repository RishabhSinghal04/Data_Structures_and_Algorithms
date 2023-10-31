
#include <iostream>
#include <conio.h>

// Display numbers from 1 to N
void display_numbers(uint16_t num)
{
    if (num < 1)
    {
        return;
    }

    display_numbers(num - 1);
    std::cout << num << " ";
}

// Display numbers from N to 1
void display_numbers_(uint16_t num)
{
    if (num < 1)
    {
        return;
    }

    std::cout << num << " ";
    display_numbers_(num - 1);
}

int main()
{
    using namespace std;

    display_numbers(10);
    cout << '\n';

    display_numbers_(10);
    cout << '\n';

    getch();
    return 0;
}