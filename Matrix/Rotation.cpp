
#include <iostream>
#include <conio.h>
#include <algorithm>
#include <iomanip>
#include <random>
#include <vector>

template <typename T>
void rotate_clockwise(std::vector<std::vector<T>> &);

template <typename T>
void rotate_anticlockwise(std::vector<std::vector<T>> &);

template <typename T>
void transpose(std::vector<std::vector<T>> &);

template <typename T>
void square_matrix_transpose(std::vector<std::vector<T>> &);

template <typename T>
void set_random_numbers(std::vector<std::vector<T>> &matrix,
                        const int16_t &MIN, const int16_t &MAX)
{
    if (matrix.empty())
    {
        throw std::runtime_error("empty matrix");
    }
    else if (MIN > MAX)
    {
        throw std::runtime_error("range : min is greater than max");
    }

    std::random_device rd;
    using dist_t = std::conditional_t<std::is_floating_point_v<T>,
                                      std::uniform_real_distribution<T>,
                                      std::uniform_int_distribution<T>>;
    dist_t dist(MIN, MAX);

    for (auto &row : matrix)
    {
        for (auto &element : row)
        {
            element = dist(rd);
        }
    }
}

template <typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<std::vector<T>> matrix)
{
    if (matrix.empty())
    {
        throw std::runtime_error("empty matrix");
    }

    uint16_t width = 2;

    for (const auto &row : matrix)
    {
        for (const auto &element : row)
        {
            out << std::setw(width + 2) << element;
        }
        out << '\n';
    }
    return out;
}

int main()
{
    using namespace std;

    const int16_t MIN = -10, MAX = 10;
    uint16_t rows = 0, columns = 0;

    cout << "Enter number of rows: ";
    cin >> rows;

    cout << "Enter number of columns: ";
    cin >> columns;

    std::vector<std::vector<int>> matrix;
    matrix.resize(rows, std::vector<int>(columns));

    std::vector<std::vector<int>> matrix_2(rows, std::vector<int>(columns));
    matrix_2.resize(rows, std::vector<int>(columns));

    set_random_numbers(matrix, MIN, MAX);
    cout << "Matrix 1:-\n"
         << matrix << '\n';

    rotate_clockwise(matrix);
    cout << "Matrix 1 after clockwise rotation:-\n"
         << matrix << '\n';

    set_random_numbers(matrix_2, MIN, MAX);
    cout << "Matrix 2:-\n"
         << matrix_2 << '\n';

    rotate_anticlockwise(matrix_2);
    cout << "Matrix 2 after anticlockwise rotation:-\n"
         << matrix_2 << '\n';

    getch();
    return 0;
}

template <typename T>
void transpose(std::vector<std::vector<T>> &matrix)
{
    const uint16_t ROWS = matrix.size();
    const uint16_t COLUMNS = matrix[0].size();

    if (ROWS == COLUMNS)
    {
        return square_matrix_transpose(matrix);
    }

    std::vector<std::vector<T>> transpose_matrix;
    transpose_matrix.resize(COLUMNS, std::vector<T>(ROWS));

    for (uint16_t row_index = 0; row_index < ROWS; ++row_index)
    {
        for (uint16_t col_index = 0; col_index < COLUMNS; ++col_index)
        {
            transpose_matrix[col_index][row_index] = matrix[row_index][col_index];
        }
    }

    matrix.clear();
    matrix.resize(COLUMNS, std::vector<T>(ROWS));
    matrix = std::move(transpose_matrix);
    transpose_matrix.clear();
}

template <typename T>
void square_matrix_transpose(std::vector<std::vector<T>> &square_matrix)
{
    const uint16_t ROWS = square_matrix.size();
    const uint16_t COLUMNS = square_matrix[0].size();

    for (uint16_t row_index = 0; row_index < ROWS - 1; ++row_index)
    {
        for (uint16_t col_index = row_index + 1; col_index < COLUMNS; ++col_index)
        {
            std::swap(square_matrix[row_index][col_index], square_matrix[col_index][row_index]);
        }
    }
}

template <typename T>
void rotate_clockwise(std::vector<std::vector<T>> &matrix)
{
    if (matrix.empty())
    {
        throw std::runtime_error("empty matrix");
    }

    transpose(matrix);
    const uint16_t ROWS = matrix.size();
    const uint16_t COLUMNS = matrix[0].size();

    for (uint16_t row_index = 0; row_index < ROWS; ++row_index)
    {
        std::reverse(matrix[row_index].begin(), matrix[row_index].end());
    }
}
/*
        Transpose  Reverse every row
1 2 3      1 4 7      7 4 1
4 5 6  ->  2 5 8  ->  8 5 2
7 8 9      3 6 9      9 6 3
*/

template <typename T>
void rotate_anticlockwise(std::vector<std::vector<T>> &matrix)
{
    if (matrix.empty())
    {
        throw std::runtime_error("empty matrix");
    }

    transpose(matrix);
    const uint16_t MID = matrix.size() / 2, SIZE = matrix.size();

    for (uint16_t row_index = 0; row_index < MID; ++row_index)
    {
        std::swap(matrix[row_index], matrix[SIZE - row_index - 1]);
    }
}
/*
        Transpose  Reverse every column or swap rows
1 2 3      1 4 7      3 6 9
4 5 6  ->  2 5 8  ->  2 5 8
7 8 9      3 6 9      1 4 7
*/