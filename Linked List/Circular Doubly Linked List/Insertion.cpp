
#include <iostream>
#include <conio.h>

#include "circular_doubly_linked_list.h"

int main()
{
    using namespace std;
    using namespace cdll;

    Circular_Doubly_Linked_List<int> integers;

    integers.push(0);
    integers.push(-1);
    integers.push_back(1);
    try
    {
        integers.insert_at(3, 3);
        integers.insert_at(3, 2);
        integers.insert_at(10, 10);
    }
    catch (std::exception &ex)
    {
        cout << "Exception Caught : " << ex.what() << '\n';
    }
    integers.push_back(4);
    integers.push(-2);
    integers.display();
    cout << '\n';

    getch();
    return 0;
}