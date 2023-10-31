
#include <iostream>
#include <conio.h>
#include <vector>

template <typename T>
bool sorted(const std::vector<T> &vec, size_t index = 0ULL)
{
    if (index == vec.size() - 1)
    {
        return true;
    }

    return vec.at(index) < vec.at(index + 1) && sorted(vec, index + 1);
}

int main()
{
    using namespace std;

    vector<int> integers{1, 2, 3, 4, 5};
    vector<float> floating_points{1.1, 2.1, 3.2, 4.1, 5.5, 4.7};

    cout << boolalpha << "Sorted? " << sorted(integers) << '\n'
         << "Sorted? " << sorted(floating_points) << '\n';

    getch();
    return 0;
}