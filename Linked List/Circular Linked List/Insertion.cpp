
#include <iostream>
#include <conio.h>

#include "circular_linked_list.h"

int main()
{
    using namespace std;
    using namespace cll;

    Circular_Linked_List<char> alphabets;

    alphabets.push('b');
    alphabets.push('a');
    alphabets.push_back('c');
    alphabets.insert_at(2, 'b');

    alphabets.display();
    cout << "\nNumber of element(s) : " << alphabets.get_size() << '\n';
    
    getch();
    return 0;
}