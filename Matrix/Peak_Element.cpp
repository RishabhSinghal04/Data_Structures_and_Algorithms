
#include <iostream>
#include <conio.h>
#include <limits>
#include <utility>

#include "matrix.h"
#include "display_matrix.h"
#include "fill_matrix.h"

/**
 * @brief Find the index of row with max number, column is same.
 * @tparam T A thing of arbitrary type
 * @param matrix
 * @param column
 * @return index of row with max number if found else -1
 */
template <typename T>
int find_max_num_index(const Matrix<T> &matrix, const uint16_t column)
{
    const uint16_t ROWS = matrix.get_number_of_rows();
    int index = -1;

    T max_num = std::numeric_limits<T>::min();

    for (uint16_t row_index = 0; row_index < ROWS; ++row_index)
    {
        if (matrix(row_index, column) > max_num)
        {
            max_num = matrix(row_index, column);
            index = row_index;
        }
    }
    return index;
}

template <typename T>
std::pair<uint16_t, uint16_t> peak_element(const Matrix<T> &matrix)
{
    if (matrix.empty())
    {
        throw std::runtime_error("empty matrix");
    }

    uint16_t low = 0, high = matrix.get_number_of_columns() - 1;

    while (low <= high)
    {
        uint16_t mid = (low + high) / 2;
        int index = find_max_num_index(matrix, mid);

        T left = mid - 1 >= 0 ? matrix(index, mid - 1) : std::numeric_limits<T>::min();
        T right = mid + 1 <= 0 ? matrix(index, mid + 1) : std::numeric_limits<T>::min();

        if (matrix(index, mid) > left && matrix(index, mid) > right)
        {
            return std::make_pair(index + 1, mid + 1);
        }
        else if (matrix(index, mid) < right)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return std::make_pair(0, 0);
}

int main()
{
    using namespace std;

    const int16_t MIN = -10, MAX = 10;
    uint16_t rows = 0, columns = 0;

    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of rows: ";
    cin >> columns;

    Matrix<int> integer_matrix(rows, columns);

    try
    {
        set_random_numbers(integer_matrix, MIN, MAX);
        cout << "Matrix :-\n"
             << integer_matrix << '\n';
        pair<uint16_t, uint16_t> matrix_indices = peak_element(integer_matrix);

        (matrix_indices.first == 0ULL)
            ? cout << "No peak element\n"
            : cout << "Peak element found at position " << matrix_indices.first
                   << ", " << matrix_indices.second << '\n';
    }
    catch (std::exception &ex)
    {
        cout << "Exception Caught : " << ex.what() << '\n';
    }

    getch();
    return 0;
}