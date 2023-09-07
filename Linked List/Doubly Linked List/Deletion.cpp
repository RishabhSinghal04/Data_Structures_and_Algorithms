
#include <iostream>
#include <conio.h>

#include "doubly_linked_list.h"

int main()
{
    using namespace std;
    using namespace dll;

    Doubly_Linked_List<float> floating_points;

    floating_points.push(0);
    floating_points.push_back(1.1);
    floating_points.push_back(2.2);

    floating_points.empty() ? cout << "Empty\n" : cout << "Not Empty\n";

    for (size_t index = 0; index <= 4; ++index)
    {
        floating_points.push_back(index * 0.5F);
    }

    floating_points.display();
    cout << '\n';

    floating_points.delete_first_element();
    floating_points.delete_last_element();

    floating_points.display();
    cout << '\n';

    floating_points.push_back(5.5);
    floating_points.push_back(10.1);
    floating_points.display();
    cout << '\n';

    size_t s = floating_points.get_size();
    cout << "Number of element(s) : " << s << '\n';

    s -= 1;
    floating_points.delete_at(s);
    floating_points.delete_at(s - 2);
    floating_points.delete_element(0.5);

    floating_points.display();
    cout << '\n';
    cout << "Number of element(s) : " << floating_points.get_size() << '\n';

    getch();
    return 0;
}