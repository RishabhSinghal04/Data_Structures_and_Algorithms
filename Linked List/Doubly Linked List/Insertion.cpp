
#include <iostream>
#include <conio.h>

#include "doubly_linked_list.h"

int main()
{
    using namespace std;
    using namespace dll;

    Doubly_Linked_List<int> integers;

    integers.push(10);
    integers.push(0);

    integers.push_back(12);
    integers.push_back(14);

    integers.display();

    try
    {
        cout << '\n'
             << integers.get_head_data() << '\t' << integers.get_tail_data() << '\n';
    }
    catch (std::exception &ex)
    {
        cout << "Exception Caught : " << ex.what() << '\n';
    }
    
    integers.clear();
    try
    {
        cout << '\n'
             << integers.get_head_data() << '\t' << integers.get_tail_data() << '\n';
    }
    catch (std::exception &ex)
    {
        cout << "Exception Caught : " << ex.what() << '\n';
    }

    getch();
    return 0;
}