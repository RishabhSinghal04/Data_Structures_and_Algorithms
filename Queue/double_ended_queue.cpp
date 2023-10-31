
#include <iostream>
#include <conio.h>

#include "double_ended_queue.h"

template <typename T>
std::ostream &operator<<(std::ostream &out, Deque<T> queue)
{
    while (!queue.empty())
    {
        out << queue.front() << ", ";
        queue.pop_front();
    }
    out << "\b\b \b";
    return out;
}

int main()
{
    using namespace std;

    Deque<int> queue;

    try
    {
        queue.push_front(-2);

        for (int i = -1; i < 10; ++i)
        {
            queue.push_back(i);
        }

        cout << queue << '\n';
        cout << "Number of elements " << queue.get_size() << '\n'
             << "Element at front is " << queue.front() << '\n'
             << "Element at back is " << queue.back() << '\n';

        (queue.empty()) ? cout << "empty\n" : cout << "not empty\n";

        while (!queue.empty())
        {
            queue.pop_front();
        }
        (queue.empty()) ? cout << "empty\n" : cout << "not empty\n";

        queue.push_back(-1);
        queue.push_back(-2);
        queue.pop_back();
        cout << queue << '\n';
    }
    catch (exception &ex)
    {
        cout << "Exception Caught : " << ex.what() << '\n';
    }

    getch();
    return 0;
}