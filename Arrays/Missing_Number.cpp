/*
 * Find missing number
 * A = [1, 3, 2, 5]
 * Output : Missing number is 4
 * */

#include <iostream>
#include <conio.h>
#include <algorithm>
#include <vector>

void input_numbers(std::vector<uint32_t> &);

int missing_number(const std::vector<uint32_t> &);

std::ostream &operator<<(std::ostream &out, const std::vector<uint32_t> numbers)
{
    for (const auto &integer : numbers)
    {
        out << integer << ", ";
    }
    out << "\b\b ";
    return out;
}

int main()
{
    using namespace std;

    uint16_t size_of_array = 0;
    int missing_num = -1;

    cout << "Enter size of array: ";
    cin >> size_of_array;

    vector<uint32_t> numbers(size_of_array, 0);

    cout << "Enter " << size_of_array << " natural numbers:-\n";
    input_numbers(numbers);

    cout << numbers << '\n';
    missing_num = missing_number(numbers);

    (missing_num == -1)
        ? cout << "No missing number\n"
        : cout << "The missing number is " << missing_num << '\n';

    getch();
    return 0;
}

void input_numbers(std::vector<uint32_t> &numbers)
{
    for (auto &integer : numbers)
    {
        std::cin >> integer;
    }
}

int missing_number(const std::vector<uint32_t> &numbers)
{
    if (numbers.size() < 2U || *(std::ranges::min_element(numbers)) < 1U)
    {
        return -1;
    }

    const uint32_t SIZE = numbers.size();
    int32_t sum = 1;

    for (uint32_t num = 2; num <= SIZE + 1; ++num)
    {
        sum -= numbers.at(num - 2);
        sum += num;
    }
    return (sum > SIZE) ? -1 : sum;
}
/*
 1  2  3  4  5
 1  3  2  5

 1-1=0
     0+2-3=-1
           -1+3-2=0
                  0+4-5=-1
                        -1+5=4
*/