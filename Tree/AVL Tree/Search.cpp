
#include <iostream>
#include <conio.h>
#include <cmath>
#include <random>
#include <utility>
#include <vector>

#include "avl_tree.h"

template <typename T>
void set_random_number(std::vector<T> &, const int16_t &, const int16_t &);

template <typename T>
void insertion(AVLTree<T> &bin_search_tree, const std::vector<T> &elements)
{
    if (elements.empty())
    {
        return;
    }

    const size_t SIZE = elements.size();

    for (size_t index = 0ULL; index < SIZE; ++index)
    {
        bin_search_tree.insert(elements.at(index));
    }
}

template <typename T>
std::pair<int64_t, int64_t> search(Node<T> *node, const T &key,
                                   int64_t index = 0, int64_t level = 0)
{
    if (node == nullptr)
    {
        return std::make_pair(-1, -1);
    }

    auto equal = []<typename V>(const V &data, const V &key)
    {
        const double PRECISION = 1e-2;
        return (std::is_floating_point_v<V>)
                   ? fabs(data - key) < PRECISION
                   : data == key;
    };

    if (equal(node->data, key))
    {
        return std::make_pair(index, level);
    }
    if (key < node->data)
    {
        return search(node->left, key, index + 1, level + 1);
    }
    if (key > node->data)
    {
        return search(node->right, key, index + 1, level + 1);
    }
    return std::make_pair(-1, -1);
}

int main()
{
    using namespace std;

    const int16_t MIN = -5, MAX = 5;
    uint16_t num_of_elements = 0;

    cout << "Enter number of elements: ";
    cin >> num_of_elements;

    AVLTree<int> bin_search_tree;
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

        insertion(bin_search_tree, integers);
        bin_search_tree.display(bin_search_tree.begin(), 5);
        cout << '\n';
    }
    catch (exception &ex)
    {
        cout << "\nException Caught : " << ex.what() << '\n';
    }

    int key;

    cout << "Enter search element: ";
    cin >> key;

    std::pair<int64_t, int64_t> found = search(bin_search_tree.begin(), key);

    (found.first != -1LL)
        ? cout << key << " found at position (index, level) : (" << found.first + 1
               << ", " << found.second + 1 << ")\n"
        : cout << key << " not found\n";

    getch();
    return 0;
}

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