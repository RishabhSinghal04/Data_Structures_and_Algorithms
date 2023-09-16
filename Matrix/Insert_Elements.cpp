
#include <iostream>
#include <conio.h>

#include "fill_matrix.h"
#include "display_matrix.h"

int main()
{
    using namespace std;

    const int MIN = -10, MAX = 10;
    Matrix<int> matrix(3, 3);

    set_random_numbers(matrix, MIN, MAX);
    cout << matrix << '\n';

    try
    {
        Matrix<int> matrix_2;
        cout << matrix_2 << '\n';
    }
    catch (std::exception &ex)
    {
        cout << "Exception Caught : " << ex.what() << '\n';
    }

    getch();
    return 0;
}