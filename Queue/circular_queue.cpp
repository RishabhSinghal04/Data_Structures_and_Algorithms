
#include <iostream>
#include <conio.h>

#include "circular_queue.h"

template <typename T>
std::ostream &operator<<(std::ostream &out, Circular_Queue<T> queue)
{
    while (!queue.empty())
    {
        auto element = queue.front();
        out << element.value() << ", ";
        queue.dequeue();
    }
    out << "\b\b \b";
    return out;
}

int main()
{
    using namespace std;

    Circular_Queue<int> queue;

    try
    {
        for (int i = -1; i < 10; ++i)
        {
            queue.enqueue(i);
        }
        cout << queue << '\n';
        cout << "Number of elements " << queue.get_size() << '\n';

        auto front_value = queue.front();
        auto back_value = queue.back();

        front_value.has_value()
            ? cout << "Element at front is " << front_value.value() << '\n'
            : cout << "Queue is empty\n";

        back_value.has_value()
            ? cout << "Element at back is " << back_value.value() << '\n'
            : cout << "Queue is empty\n";
        (queue.empty()) ? cout << "empty\n" : cout << "not empty\n";

        while (!queue.empty())
        {
            queue.dequeue();
        }
        (queue.empty()) ? cout << "empty\n" : cout << "not empty\n";

        queue.enqueue(-2);
        queue.enqueue(-1);
        queue.dequeue();
        cout << queue << '\n';
    }
    catch (exception &ex)
    {
        cout << "Exception Caught : " << ex.what() << '\n';
    }

    getch();
    return 0;
}