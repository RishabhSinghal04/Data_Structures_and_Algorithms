
#include <iostream>
#include <conio.h>
#include <array>

void divide_array(const std::array<int, 10> &arr, uint16_t low, uint16_t high)
{
    if (low < high)
    {
        for (size_t index = low; index <= high; ++index)
        {
            std::cout << arr.at(index) << " ";
        }
        std::cout << '\n';

        uint16_t mid = (low + high) / 2;
        divide_array(arr, low, mid);
        divide_array(arr, mid + 1, high);
    }
}

int main()
{
    using namespace std;

    const array<int, 10> arr{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    divide_array(arr, 0, 9);

    getch();
    return 0;
}