
#include <iostream>
#include <conio.h>
#include <algorithm>

#include "display_and_set_numbers.h"

std::pair<uint16_t, uint16_t> min_max_amt_of_money(std::vector<uint16_t> candies,
                                                   const uint16_t &num_of_free_candies)
{
    if (num_of_free_candies >= candies.size())
    {
        return std::make_pair(0, 0);
    }

    std::ranges::stable_sort(candies);

    const uint16_t SIZE = candies.size();
    uint16_t min_amt = 0, max_amt = 0, index = 0;

    while (index < SIZE - num_of_free_candies)
    {
        min_amt += candies.at(index);
        max_amt += candies.at(SIZE - index - 1);
        ++index;
    }
    return std::make_pair(min_amt, max_amt);
}

int main()
{
    using namespace std;

    uint16_t num_of_candies = 0, num_of_free_candies = 0;

    cout << "Enter number of candies : ";
    cin >> num_of_candies;

    cout << "Enter number of free candies : ";
    cin >> num_of_free_candies;

    vector<uint16_t> candies(num_of_candies, 0);

    set_random_numbers(candies, 1, 10);
    cout << candies << '\n'
         << "Number of free candies : " << num_of_free_candies << '\n';

    pair<uint16_t, uint16_t> min_max = min_max_amt_of_money(candies, num_of_free_candies);

    cout << "Minimum amount of money you have to spend to buy all the N different candies is "
         << min_max.first << '\n'
         << "Maximum amount of money you have to spend to buy all the N different candies is "
         << min_max.second << '\n';

    getch();
    return 0;
}