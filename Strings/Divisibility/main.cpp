
#include <iostream>
#include <conio.h>

#include "divisibility.h"

int main()
{
    using namespace std;

    string num{};

    cout << "Enter a number : ";
    getline(cin >> ws, num);

    cout << boolalpha;
    cout << "\nIs " << num << " divisible by 2: " << Divisibility::divisible_by_two(num);
    cout << "\nIs " << num << " divisible by 3: " << Divisibility::divisible_by_three(num);
    cout << "\nIs " << num << " divisible by 4: " << Divisibility::divisible_by_four(num);
    cout << "\nIs " << num << " divisible by 5: " << Divisibility::divisible_by_five(num);
    cout << "\nIs " << num << " divisible by 6: " << Divisibility::divisible_by_six(num);
    cout << "\nIs " << num << " divisible by 7: " << Divisibility::divisible_by_seven(num);
    cout << "\nIs " << num << " divisible by 8: " << Divisibility::divisible_by_eight(num);
    cout << "\nIs " << num << " divisible by 9: " << Divisibility::divisible_by_nine(num);
    cout << "\nIs " << num << " divisible by 10: " << Divisibility::divisible_by_ten(num);
    cout << "\nIs " << num << " divisible by 11: " << Divisibility::divisible_by_eleven(num);
    cout << "\nIs " << num << " divisible by 12: " << Divisibility::divisible_by_twelve(num);
    cout << "\nIs " << num << " divisible by 13: " << Divisibility::divisible_by_thirteen(num);
    cout << "\nIs " << num << " divisible by 14: " << Divisibility::divisible_by_fourteen(num);
    cout << "\nIs " << num << " divisible by 15: " << Divisibility::divisible_by_fifteen(num);

    getch();
    return 0;
}