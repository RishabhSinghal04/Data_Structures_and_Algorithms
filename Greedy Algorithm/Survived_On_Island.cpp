
#include <iostream>
#include <conio.h>
#include <utility>

std::pair<bool, uint16_t> survived(const uint16_t &survival_days,
                                   const uint16_t &max_food, const uint16_t &required_food)
{
    if (survival_days == 0 || required_food == 0)
    {
        return std::make_pair(true, 0);
    }
    else if (required_food > max_food)
    {
        return std::make_pair(false, 0);
    }

    uint32_t total_required_food = survival_days * required_food;
    uint16_t min_days = total_required_food / max_food;

    if (total_required_food % max_food != 0)
    {
        ++min_days;
    }
    if (total_required_food <= max_food * (survival_days - survival_days / 7))
    {
        return std::make_pair(true, min_days);
    }
    return std::make_pair(false, min_days);
}

int main()
{
    using namespace std;

    uint16_t survival_days = 0, max_food = 0, required_food = 0;

    cout << "Enter number of days you are required to survive : ";
    cin >> survival_days;

    cout << "Enter maximum unit of food you can buy each day : ";
    cin >> max_food;

    cout << "Enter unit of food required each day to survive : ";
    cin >> required_food;

    pair<bool, uint16_t> could_you_survive = survived(survival_days, max_food, required_food);

    cout << boolalpha << "Could you survive? " << could_you_survive.first << '\n';

    if (could_you_survive.first)
    {
        cout << "Minimum number of days on which you need to buy food from the shop are "
             << could_you_survive.second << '\n';
    }

    getch();
    return 0;
}