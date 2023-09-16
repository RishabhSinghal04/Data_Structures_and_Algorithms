
#include <iostream>
#include <conio.h>

#include <cmath>
#include <iomanip>
#include <utility>
#include <vector>

template <typename T>
std::pair<uint16_t, uint16_t> search_(const std::vector<std::vector<T>> &, const T &);

int main()
{
    using namespace std;

    vector<vector<int>> integer_matrix{
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}};

    for (const auto &row : integer_matrix)
    {
        for (const auto &element : row)
        {
            cout << setw(4) << element << ", ";
        }
        cout << "\b\b \b\n";
    }

    int search_element;

    cout << "Enter search element : ";
    cin >> search_element;
    try
    {
        pair<uint16_t, uint16_t> matrix_indices = search_(integer_matrix, search_element);

        (matrix_indices.first == 0)
            ? cout << search_element << " not found\n"
            : cout << search_element << " found at position " << matrix_indices.first
                   << ", " << matrix_indices.second << '\n';
    }
    catch (std::exception &ex)
    {
        cout << "Exception Caught : " << ex.what() << '\n';
    }

    getch();
    return 0;
}

template <typename T>
std::pair<uint16_t, uint16_t> search_(const std::vector<std::vector<T>> &matrix,
                                      const T &key)
{
    if (matrix.empty())
    {
        throw std::runtime_error("Empty");
    }

    const uint16_t ROWS = matrix.size();
    uint16_t row_index = 0;
    int col_index = matrix[0].size() - 1;

    while (row_index < ROWS && col_index >= 0)
    {
        if (fabs(matrix[row_index][col_index] - key) < 1e-2)
        {
            return std::make_pair(row_index + 1, col_index + 1);
        }
        else if (matrix[row_index][col_index] < key)
        {
            ++row_index;
        }
        else
        {
            --col_index;
        }
    }
    return std::make_pair(0, 0);
}

/*
 1   4   7  11  15
 2   5   8  12  19
 3   6   9  16  22
10  13  14  17  24
18  21  23  26  30

Search Element (key) = 10

Take 15:-
Left side elements are smaller and bottom side elements are greater than 15.
Therefore search key on left side.

Take 11:-
Left side elements are smaller and bottom side elements are greater than 11.
Therefore search key on left side.

Take 7:-
Left side elements are smaller and bottom side elements are greater than 7.
Therefore search key on bottom of 7.

Take 8:-
Left side elements are smaller and bottom side elements are greater than 8.
Therefore search key on bottom of 8.

Take 9:-
Left side elements are smaller and bottom side elements are greater than 9.
Therefore search key on bottom of 9.

Take 14:-
Left side elements are smaller and bottom side elements are greater than 14.
Therefore search key on left side.

Take 13:-
Left side elements are smaller and bottom side elements are greater than 13.
Therefore search key on left side.
*/