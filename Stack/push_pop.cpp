
#include <iostream>
#include <conio.h>

#include "stack.h"

template <typename T>
std::ostream &operator<<(std::ostream &out, stk::Stack<T> stack)
{
    while (!stack.empty())
    {
        out << stack.top() << '\n';
        stack.pop();
    }
    return out;
}

int main()
{
    using namespace std;
    using namespace stk;

    Stack<char> alphabets;
    try
    {
        alphabets.push('a');
        alphabets.push('b');
        alphabets.push('c');
        alphabets.push('d');
        cout << alphabets << '\n';

        alphabets.pop();
        alphabets.pop();
        cout << alphabets << '\n';

        alphabets.pop();
        alphabets.pop();
        alphabets.empty()
            ? cout << "stack is empty\n"
            : cout << "stack is not empty\n";
        alphabets.pop();
    }
    catch (exception &ex)
    {
        cout << "Exception Caught : " << ex.what() << '\n';
    }

    getch();
    return 0;
}