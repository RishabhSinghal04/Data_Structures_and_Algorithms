
#include <iostream>
#include <conio.h>

#include "matrix.h"
#include "display_matrix.h"
#include "fill_matrix.h"

template <typename T>
void transpose(Matrix<T> &);

template <typename T>
void square_matrix_transpose(Matrix<T> &);

int main()
{
    using namespace std;

    const int16_t MIN = -10, MAX = 10;
    uint16_t rows = 0, columns = 0;

    cout << "Enter number of rows: ";
    cin >> rows;

    cout << "Enter number of columns: ";
    cin >> columns;

    Matrix<int> matrix(rows, columns);

    set_random_numbers(matrix, MIN, MAX);
    cout << matrix << '\n';

    transpose(matrix);
    cout << "Transpose:-\n"
         << matrix << '\n';

    getch();
    return 0;
}

template <typename T>
void transpose(Matrix<T> &matrix)
{
    if (matrix.empty())
    {
        throw std::runtime_error("empty matrix");
    }

    const uint16_t ROWS = matrix.get_number_of_rows();
    const uint16_t COLUMNS = matrix.get_number_of_columns();

    if (ROWS == COLUMNS)
    {
        return square_matrix_transpose(matrix);
    }

    Matrix<T> transpose_matrix(COLUMNS, ROWS);

    for (uint16_t row_index = 0; row_index < ROWS; ++row_index)
    {
        for (uint16_t col_index = 0; col_index < COLUMNS; ++col_index)
        {
            transpose_matrix(col_index, row_index) = matrix(row_index, col_index);
        }
    }

    matrix.clear();
    matrix.set_size(COLUMNS, ROWS);
    matrix = transpose_matrix;
    transpose_matrix.clear();
}

template <typename T>
void square_matrix_transpose(Matrix<T> &square_matrix)
{
    const uint16_t ROWS = square_matrix.get_number_of_rows();
    const uint16_t COLUMNS = square_matrix.get_number_of_columns();

    for (uint16_t row_index = 0; row_index < ROWS - 1; ++row_index)
    {
        for (uint16_t col_index = row_index + 1; col_index < COLUMNS; ++col_index)
        {
            std::swap(square_matrix(row_index, col_index), square_matrix(col_index, row_index));
        }
    }
}
