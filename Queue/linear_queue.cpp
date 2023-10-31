
#include <iostream>
#include <conio.h>

#include "linear_queue.h"

template <typename T>
std::ostream &operator<<(std::ostream &out, Queue<T> queue)
{
    while (!queue.empty())
    {
        out << queue.front() << ", ";
        queue.dequeue();
    }
    out << "\b\b \b";
    return out;
}

int main()
{
    using namespace std;

    Queue<int> queue;

    try
    {
        for (int i = -1; i < 10; ++i)
        {
            queue.enqueue(i);
        }
        cout << queue << '\n'
             << "Number of elements " << queue.get_size() << '\n'
             << "Element at front " << queue.front() << '\n'
             << "Element at back : " << queue.back() << '\n';

        while (!queue.empty())
        {
            queue.dequeue();
        }

        (queue.empty()) ? cout << "empty\n" : cout << "not empty\n";
    }
    catch (exception &ex)
    {
        cout << "Exception Caught : " << ex.what() << '\n';
    }

    getch();
    return 0;
}