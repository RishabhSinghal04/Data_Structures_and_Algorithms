
#include <iostream>
#include <conio.h>

#include "matrix.h"
#include "display_matrix.h"
#include "fill_matrix.h"

template <typename T>
void spiral_form(const Matrix<T> &matrix, std::vector<T> &spiral)
{
    if (matrix.empty())
    {
        throw std::runtime_error("empty matrix");
    }
    if (matrix.get_number_of_rows() == 1)
    {
        spiral.emplace_back(matrix(0, 0));
        return;
    }

    uint16_t top = 0, left = 0;
    int bottom = matrix.get_number_of_rows() - 1,
        right = matrix.get_number_of_columns() - 1;

    while (top <= bottom && left <= right)
    {
        // Left to right traversal (>)
        for (uint16_t index = left; index <= right; ++index)
        {
            spiral.emplace_back(matrix(top, index));
        }
        ++top;

        // Top to bottom traversal (v)
        for (uint16_t index = top; index <= bottom; ++index)
        {
            spiral.emplace_back(matrix(index, right));
        }
        --right;

        if (left <= right)
        {
            // Right to left traversal (<)
            for (int index = right; index >= left; --index)
            {
                spiral.emplace_back(matrix(bottom, index));
            }
            --bottom;
        }

        if (top <= bottom)
        {
            // Bottom to top traversal (^)
            for (int index = bottom; index >= top; --index)
            {
                spiral.emplace_back(matrix(index, left));
            }
            ++left;
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
    vector<int> spiral(0);
    spiral.reserve(rows * columns);

    set_random_numbers(matrix, MIN, MAX);
    cout << matrix << '\n';

    spiral_form(matrix, spiral);
    
    for (const auto &element : spiral)
    {
        cout << element << "  ";
    }
    cout << '\n';

    getch();
    return 0;
}