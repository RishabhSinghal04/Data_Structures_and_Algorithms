
#include <iostream>
#include <conio.h>

#include "matrix.h"
#include "display_matrix.h"
#include "fill_matrix.h"

template <typename T>
void set_matrix_zero(Matrix<T> &matrix)
{
    const uint16_t ROWS = matrix.get_number_of_rows();
    const uint16_t COLUMNS = matrix.get_number_of_columns();
    T element_00 = 1;

    for (uint16_t row_index = 0; row_index < ROWS; ++row_index)
    {
        for (uint16_t col_index = 0; col_index < COLUMNS; ++col_index)
        {
            if (matrix(row_index, col_index) == 0)
            {
                matrix(row_index, 0) = 0;
                (col_index == 0)
                    ? element_00 = 0
                    : matrix(0, col_index) = 0;
            }
        }
    }

    for (uint16_t row_index = 1; row_index < ROWS; ++row_index)
    {
        for (uint16_t col_index = 1; col_index < COLUMNS; ++col_index)
        {
            if (matrix(row_index, col_index) != 0)
            {
                if (matrix(row_index, 0) == 0 || matrix(0, col_index) == 0)
                {
                    matrix(row_index, col_index) = 0;
                }
            }
        }
    }

    if (matrix(0, 0) == 0)
    {
        for (uint16_t col_index = 0; col_index < ROWS; ++col_index)
        {
            matrix(0, col_index) = 0;
        }
    }
    if (element_00 == 0)
    {
        for (uint16_t row_index = 0; row_index < ROWS; ++row_index)
        {
            matrix(row_index, 0) = 0;
        }
    }
}

int main()
{
    using namespace std;

    const uint16_t MIN = 00, MAX = 5;
    uint16_t rows = 0, columns = 0;

    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> columns;

    Matrix<uint16_t> matrix(rows, columns);

    set_random_numbers(matrix, MIN, MAX);
    cout << "Matrix:-\n"
         << matrix << '\n';

    set_matrix_zero(matrix);
    cout << "Set Matrix Zero:-\n"
         << matrix << '\n';

    getch();
    return 0;
}