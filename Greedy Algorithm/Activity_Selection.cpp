
#include <iostream>
#include <conio.h>
#include <algorithm>
#include <utility>

#include "display_and_set_numbers.h"

template <typename T>
uint16_t select_num_of_activities(const std::vector<T> &start, const std::vector<T> &end)
{
    if (start.empty() || end.empty())
    {
        return 0;
    }

    std::vector<std::pair<T, T>> start_end;
    start_end.reserve(start.size());

    for (uint16_t index = 0; index < start.size(); ++index)
    {
        start_end.emplace_back(std::make_pair(start.at(index), end.at(index)));
    }

    auto compare = []<typename V>(const V &value_1, const V &value_2)
    {
        return value_1.second < value_2.second;
    };

    std::ranges::stable_sort(start_end, compare);
    std::cout << start_end << '\n';

    uint16_t max_num_of_activities = 1;
    uint16_t start_it = 1, end_it = 0;
    
    std::cout << "(" << start_end.at(end_it).first << ", "
              << start_end.at(end_it).second << ")\n";

    while (start_it < start_end.size() && end_it < start_end.size() - 1)
    {
        if (start_end.at(end_it).second <= start_end.at(start_it).first)
        {
            ++max_num_of_activities;
            end_it = start_it;

            std::cout << "(" << start_end.at(end_it).first << ", "
                      << start_end.at(end_it).second << ")\n";
        }
        ++start_it;
    }
    return max_num_of_activities;
}

int main()
{
    using namespace std;

    uint16_t num_of_activities = 0, max_num_of_activities = 0;

    cout << "Enter total number of activities: ";
    cin >> num_of_activities;

    vector<uint16_t> start(num_of_activities, 0), end;
    end.reserve(num_of_activities);

    try
    {
        set_random_numbers(start, 0, 23);

        random_device rd;
        uniform_int_distribution<uint16_t> dist(1, 24);

        for (const auto element : start)
        {
            uint16_t rand_num = dist(rd);

            while (rand_num + element > 24)
            {
                rand_num = dist(rd);
            }

            end.emplace_back(element + rand_num);
        }

        cout << "start : " << start << '\n'
             << "  end : " << end << '\n';

        max_num_of_activities = select_num_of_activities(start, end);
        cout << "Maximum number of activities that can be done are : " << max_num_of_activities << '\n';
    }
    catch (exception &ex)
    {
        cout << "Exception Caught : " << ex.what() << '\n';
    }

    getch();
    return 0;
}