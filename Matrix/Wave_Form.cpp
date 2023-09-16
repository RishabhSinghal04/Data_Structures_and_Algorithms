
#include <iostream>
#include <conio.h>

#include "matrix.h"
#include "display_matrix.h"
#include "fill_matrix.h"

template <typename T>
void wave_form(const Matrix<T> &matrix, std::vector<T> &wave)
{
    const uint16_t COLUMNS = matrix.get_number_of_columns();
    const uint16_t ROWS = matrix.get_number_of_rows();

    for (uint16_t col_index = 0; col_index < COLUMNS; ++col_index)
    {
        if (col_index % 2 == 0)
        {
            for (uint16_t row_index = 0; row_index < ROWS; ++row_index)
            {
                wave.emplace_back(matrix(row_index, col_index));
            }
        }
        else
        {
            for (int16_t row_index = ROWS - 1; row_index >= 0; --row_index)
            {
                wave.emplace_back(matrix(row_index, col_index));
            }
        }
    }
}

int main()
{
    using namespace std;

    const int16_t MIN = -100, MAX = 100;
    uint16_t rows = 0, columns = 0;

    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> columns;

    Matrix<int> matrix(rows, columns);
    vector<int> wave(0);
    wave.reserve(rows*columns);

    set_random_numbers(matrix, MIN, MAX);
    cout << matrix << '\n';

    wave_form(matrix, wave);

    for (const auto &element : wave)
    {
        cout << element << "  ";
    }
    cout << '\n';

    getch();
    return 0;
}