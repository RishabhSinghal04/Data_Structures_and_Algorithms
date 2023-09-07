
#include <iostream>
#include <conio.h>

#include "circular_linked_list.h"

int main()
{
    using namespace std;
    using namespace cll;

    Circular_Linked_List<char> alphabets;
    try
    {
        alphabets.push('Z');
        alphabets.display();
        cout << '\n';

        alphabets.delete_first_element();
        alphabets.empty() ? cout << "Empty\n" : cout << "Not Empty\n";

        alphabets.push('b');
        alphabets.push('a');
        alphabets.display();
        cout << '\n';

        alphabets.delete_first_element();
        alphabets.display();
        cout << '\n';

        alphabets.delete_last_element();
        alphabets.empty() ? cout << "Empty\n" : cout << "Not Empty\n";

        alphabets.push_back('c');
        alphabets.push_back('d');
        alphabets.push_back('e');
        alphabets.display();
        cout << '\n';

        alphabets.delete_last_element();
        alphabets.display();
        cout << '\n';

        alphabets.push('b');
        alphabets.display();
        cout << '\n';

        alphabets.delete_first_element();
        alphabets.display();
        cout << '\n';

        alphabets.clear();
        alphabets.empty() ? cout << "Empty\n" : cout << "Not Empty\n";

        alphabets.push_back('x');
        alphabets.push_back('y');
        alphabets.push_back('z');
        alphabets.display();
        cout << '\n';

        alphabets.delete_at(1);
        alphabets.display();
        cout << '\n';

        alphabets.push('n');
        alphabets.push('m');
        alphabets.display();
        cout << '\n';

        alphabets.delete_at(alphabets.get_size() - 1);
        alphabets.delete_at(alphabets.get_size());
        alphabets.delete_at(1);
        alphabets.display();
        cout << '\n';

        cout << "Number of element(s) : " << alphabets.get_size() << '\n';
        alphabets.push_back('p');
        alphabets.display();
        cout << '\n';

        alphabets.delete_at(alphabets.get_size());
        alphabets.delete_at(alphabets.get_size() - 1);
        alphabets.display();
        cout << '\n';

        alphabets.push_back('j');
        alphabets.push_back('k');
        alphabets.display();
        cout << '\n';

        alphabets.delete_element('k');
        alphabets.display();
        cout << '\n';

        alphabets.delete_element('z');
        alphabets.clear();
        alphabets.delete_element('z');
    }
    catch (std::exception &ex)
    {
        cout << "Exception Caught : " << ex.what() << '\n';
    }
    
    getch();
    return 0;
}