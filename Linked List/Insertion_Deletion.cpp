
#include <iostream>
#include <conio.h>

#include "linked_list.h"

int main()
{
    using namespace std;
    using namespace ll;

    Linked_List<uint32_t> whole_numbers;

    try
    {
        whole_numbers.push_back(2);
        whole_numbers.push(0);
        whole_numbers.push_back(3);

        whole_numbers.insert_at(1, 1);

        for (uint32_t num = 4; num < 10; ++num)
        {
            whole_numbers.push_back(num);
        }

        whole_numbers.insert_at(10, 111);
        // whole_numbers.insert_at(18, 1111);
        whole_numbers.display();
        cout << '\n';

        whole_numbers.delete_first_element();
        whole_numbers.display();
        cout << '\n';

        whole_numbers.delete_last_element();
        whole_numbers.display();
        cout << '\n';

        whole_numbers.delete_at(1);
        whole_numbers.display();
        cout << '\n';

        whole_numbers.delete_at(6);
        whole_numbers.display();
        cout << '\n';

        whole_numbers.delete_element(5);
        whole_numbers.delete_element(9);
        whole_numbers.display();
        cout << "\nNumber of element(s) : " << whole_numbers.get_size() << '\n';
    }
    catch (std::exception &ex)
    {
        cout << "Exception Caught : " << ex.what() << '\n';
    }

    getch();
    return 0;
}