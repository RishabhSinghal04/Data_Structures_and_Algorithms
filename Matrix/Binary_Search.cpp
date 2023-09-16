
#include <iostream>
#include <conio.h>

#include <cmath>
#include <iomanip>
#include <utility>
#include <vector>

template <typename T>
std::pair<size_t, size_t> binary_search(const std::vector<std::vector<T>> &matrix,
                                        const T &key)
{
    if (matrix.empty())
    {
        throw std::runtime_error("Empty");
    }

    const size_t ROWS = matrix.size(), COLUMNS = matrix[0ULL].size();
    size_t left = 0ULL, right = ROWS * COLUMNS - 1;
    size_t mid = 0ULL, row_index = 0ULL, col_index = 0ULL;

    while (left <= right)
    {
        mid = (left + right) / 2ULL;
        row_index = mid / COLUMNS;
        col_index = mid % COLUMNS;

        if (fabs(matrix[row_index][col_index] - key) < 1e-2)
        {
            return std::make_pair(row_index + 1, col_index + 1);
        }
        else if (matrix[row_index][col_index] > key)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return std::make_pair(0, 0);
}

int main()
{
    using namespace std;

    vector<vector<int>> integer_matrix{
        {-1, -2, -3, -4}, {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};

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
        pair<size_t, size_t> matrix_indices = binary_search(integer_matrix, search_element);

        (matrix_indices.first == 0ULL)
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