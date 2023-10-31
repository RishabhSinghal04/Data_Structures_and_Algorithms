
#include <iostream>
#include <conio.h>

#include "heap.h"
#include "display.h"

int main()
{
    using namespace std;

    Heap<int> heap;

    heap.set_size(7);

    heap.insert(12);
    heap.insert(7);
    heap.insert(18);
    heap.insert(22);
    heap.insert(1);
    heap.insert(0);
    heap.insert(-1);

    cout << heap << '\n'
         << "max = " << heap.get_max() << '\n'
         << "\nAfter sorting :-\n";
    heap.sort();
    cout << heap << '\n';

    heap.clear();
    heap.empty()
        ? cout << "\nHeap is empty\n"
        : cout << "\nHeap is not empty\n";

    for (int index = 0; index < 10; ++index)
    {
        heap.insert(index);
    }

    cout << heap << '\n';

    Heap<int, std::less<int>> heap_2;

    heap_2.insert(12);
    heap_2.insert(7);
    heap_2.insert(18);
    heap_2.insert(22);
    heap_2.insert(1);
    heap_2.insert(0);
    heap_2.insert(-1);

    cout << heap_2 << '\n'
         << "min : " << heap_2.get_min() << '\n';

    heap_2.delete_key(-1);
    heap_2.delete_key(7);
    cout << "\n\nAfter removing some elements :-\n"
         << heap_2 << '\n';

    heap_2.insert(11);
    heap_2.insert(20);

    cout << '\n'
         << heap_2 << '\n';

    heap_2.sort();
    cout << "After sorting :-\n"
         << heap_2 << '\n';

    getch();
    return 0;
}