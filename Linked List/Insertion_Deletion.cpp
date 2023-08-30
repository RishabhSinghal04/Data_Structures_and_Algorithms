
#include <iostream>
#include <conio.h>

#include "linked_list.h"

int main()
{
    using namespace std;
    using namespace ll;

    Linked_List<uint32_t> whole_numbers;

    whole_numbers.push_back(2);
    whole_numbers.push(0);
    whole_numbers.push_back(3);

    Node<uint32_t> *n = whole_numbers.get_head();
    whole_numbers.insert_after(n, 1);

    for(uint32_t num = 4; num < 10; ++num)
    {
        whole_numbers.push_back(num);
    }

    Node<uint32_t> m(10U);

    whole_numbers.push_back(m.data);
    whole_numbers.display();
    cout << '\n';

    whole_numbers.delete_first_node();
    whole_numbers.display();
    cout << '\n';

    whole_numbers.delete_last_node();
    whole_numbers.display();
    cout << '\n';

    Node<uint32_t> *d = whole_numbers.get_head()->next;
    whole_numbers.delete_after(d);
    whole_numbers.display();
    cout << '\n';
    
    whole_numbers.delete_at(6);
    whole_numbers.display();
    cout << '\n';

    whole_numbers.delete_node(5);
    whole_numbers.display();
    cout << '\n';

    getch();
    return 0;
}