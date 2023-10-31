
#include <iostream>
#include <conio.h>
#include <random>
#include <vector>

#include "Binary_Tree.h"

template <typename T>
void set_random_number(std::vector<T> &numbers, const int16_t &MIN, const int16_t &MAX)
{
    if (numbers.empty())
    {
        throw std::runtime_error("empty");
    }
    if (MIN > MAX)
    {
        throw std::runtime_error("range : MIN > MAX");
    }

    std::random_device rd;
    using dist_t = std::conditional_t<std::is_floating_point_v<T>,
                                      std::uniform_real_distribution<>,
                                      std::uniform_int_distribution<>>;
    dist_t dist(MIN, MAX);

    for (auto &num : numbers)
    {
        num = dist(rd);
    }
}

template <typename T>
void insertion(BinaryTree<T> &bin_tree, const std::vector<T> &elements)
{
    if (elements.empty())
    {
        return;
    }

    const size_t SIZE = elements.size();

    for (size_t index = 0ULL; index < SIZE; ++index)
    {
        bin_tree.insert(elements.at(index));
    }
}

int main()
{
    using namespace std;

    const int16_t MIN = -5, MAX = 5;
    uint16_t num_of_elements = 0;

    cout << "Enter number of elements: ";
    cin >> num_of_elements;

    BinaryTree<int> bin_tree;
    vector<int> integers(num_of_elements, 0);

    try
    {
        set_random_number(integers, MIN, MAX);
        auto print = []<typename V>(const V &vec)
        {
            for (const auto &element : vec)
            {
                cout << element << ", ";
            }
            cout << "\b\b \b";
        };
        print(integers);

        insertion(bin_tree, integers);
        bin_tree.display(bin_tree.begin(), 5);
    }
    catch (exception &ex)
    {
        cout << "\nException Caught : " << ex.what() << '\n';
    }

    getch();
    return 0;
}