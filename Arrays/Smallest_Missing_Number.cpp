/*
 * Find the smallest missing number
 * Range is from 0 to m-1, where m = maximum element + 1
 * A = [0, 1, 2, 6, 9]
 * Output : 3
 */

#include <iostream>
#include <conio.h>
#include <vector>

int64_t smallest_missing_number(const std::vector<uint16_t> &);
uint64_t smallest_missing_num_(const std::vector<uint16_t> &, uint16_t, uint16_t);

std::ostream &operator<<(std::ostream &out, const std::vector<uint16_t> &whole_numbers)
{
    std::string_view separator{};
    for (const auto &num : whole_numbers)
    {
        out << num << ", ";
    }
    out << "\b\b ";
    return out;
}

int main()
{
    using namespace std;

    vector<uint16_t> whole_numbers{0, 1, 2, 6, 9};
    cout << whole_numbers << '\n';

    cout << "The smallest missing number is " << smallest_missing_number(whole_numbers);

    getch();
    return 0;
}

int64_t smallest_missing_number(const std::vector<uint16_t> &whole_numbers)
{
    if (whole_numbers.size() < 2)
    {
        return -1;
    }
    uint16_t start = 0, end = whole_numbers.size() - 1;
    return smallest_missing_num_(whole_numbers, start, end);
}

uint64_t smallest_missing_num_(const std::vector<uint16_t> &whole_numbers,
                               uint16_t start, uint16_t end)
{
    if (start > end)
    {
        return end + 1;
    }
    if (start != whole_numbers.at(start))
    {
        return start;
    }

    size_t mid = (start + end) / 2;

    if (whole_numbers.at(mid) == mid) // Array has all elements from 0 to mid
    {
        return smallest_missing_num_(whole_numbers, mid + 1, end);
    }
    return smallest_missing_num_(whole_numbers, start, mid);
}