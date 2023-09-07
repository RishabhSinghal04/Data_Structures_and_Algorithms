
#include <iostream>
#include <conio.h>

#include "circular_doubly_linked_list.h"

int main()
{
    using namespace std;
    using namespace cdll;

    Circular_Doubly_Linked_List<int> integers;

    for (size_t index = 0ULL; index < 10; ++index)
    {
        integers.push_back(index);
    }
    integers.display();
    cout << '\n';

    try
    {
        integers.delete_first_element();
        integers.delete_last_element();
        integers.display();
        cout << '\n';

        integers.delete_at(7);
        integers.delete_at(2);
        integers.delete_element(5);
        integers.display();
        cout << '\n';
    }
    catch (std::exception &ex)
    {
        cout << "Exception Caught : " << ex.what() << '\n';
    }

    getch();
    return 0;
}