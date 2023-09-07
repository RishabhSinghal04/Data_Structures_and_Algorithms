
#include <iostream>
#include <conio.h>

#include "doubly_linked_list.h"

int main()
{
    using namespace std;
    using namespace dll;

    Doubly_Linked_List<int> integers;

    integers.push(1);
    integers.push(0);

    for (size_t index = 2; index <= 10; ++index)
    {
        integers.push_back(index);
    }
    try
    {
        integers.insert_at(11, 11);
        integers.insert_at(13, 13);
        integers.insert_at(0, -1);
    }
    catch (std::exception &ex)
    {
        cout << "Exception Caught : " << ex.what() << '\n';
    }

    integers.display();
    cout << '\n';

    integers.reverse_display();
    cout << '\n';

    cout << "Number of elements " << integers.get_size() << '\n';

    Doubly_Linked_List<int> integers_2;

    integers_2.push(0);
    integers_2.push_back(1);
    integers_2.push_back(02);
    integers_2.push_back(4);

    integers_2.insert_at(3, 3);
    integers_2.display();
    cout << "\nNumber of elements " << integers_2.get_size() << '\n';

    integers_2.delete_first_element();
    integers_2.delete_last_element();
    integers_2.display();
    cout << "\nNumber of elements " << integers_2.get_size() << '\n';

    integers_2.delete_first_element();
    integers_2.delete_last_element();
    integers_2.display();
    cout << "\nNumber of elements " << integers_2.get_size() << '\n';

    integers_2.delete_first_element();
    integers_2.empty() ? cout << "Empty" : cout << "Not Empty";
    cout << "\nNumber of elements " << integers_2.get_size() << '\n';

    integers.delete_first_element();
    integers.delete_last_element();
    integers.display();
    cout << "\nNumber of elements " << integers.get_size() << '\n';

    integers_2.push(0);
    integers_2.push_back(1);
    integers_2.display();
    cout << "\nNumber of elements " << integers_2.get_size() << '\n';

    integers_2.clear();
    integers_2.empty() ? cout << "Empty" : cout << "Not Empty";
    cout << "\nNumber of elements " << integers_2.get_size() << '\n';

    getch();
    return 0;
}