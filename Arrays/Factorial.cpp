
#include <iostream>
#include <conio.h>
#include <ranges>
#include <vector>

std::ostream &operator<<(std::ostream &out, const std::vector<uint64_t> &factorial)
{
    std::string_view separator{};
    for (const auto &index : std::views::reverse(factorial))
    {
        out << index;
    }
    return out;
}

void display_factorial(const uint16_t &);
void multiplication(const uint16_t &, std::vector<uint64_t> &);

int main()
{
    using namespace std;

    uint16_t num;

    cout << "Enter a number : ";
    cin >> num;

    cout << "Factorial of " << num << " is ";
    display_factorial(num);

    getch();
    return 0;
}

void display_factorial(const uint16_t &num)
{
    std::vector<uint64_t> factorial(1, 1);

    if (num < 2)
    {
        std::cout << 1;
    }

    for (size_t n = 2; n <= num; ++n)
    {
        multiplication(n, factorial);
    }

    std::cout << factorial;
}

/* n = 4
 * 1 2 3 4
 * x   1 0
 * 40, 0 c=4
 * 34, 4 c=3
 * 23, 3 c=2
 * 12, 2 c=1
 */
void multiplication(const uint16_t &num, std::vector<uint64_t> &factorial)
{
    uint16_t carry = 0, product = 0;

    for (auto &digit : factorial)
    {
        product = digit * num + carry;
        digit = product % 10;
        carry = product / 10;
    }

    while (carry > 0)
    {
        factorial.emplace_back(carry % 10);
        carry /= 10;
    }
}