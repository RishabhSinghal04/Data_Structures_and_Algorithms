
#include <iostream>
#include <conio.h>
#include <cmath>
#include <iomanip>
#include <random>
#include <utility>
#include <vector>

template <typename T>
std::pair<uint16_t, uint16_t> search(std::vector<std::vector<T>> &, const T &);

template <typename T>
size_t sentinel_linear_search(std::vector<T> &, const T &);

template <typename T>
uint16_t max_width(const std::vector<std::vector<T>> &matrix)
{
    uint16_t width = 0;
    for (const auto &row : matrix)
    {
        for (const auto &element : row)
        {
            std::stringstream ss{};
            ss << element;
            width = std::max<uint16_t>(width, ss.str().length());
        }
    }
    return width;
}

template <typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<std::vector<T>> &matrix)
{
    if (matrix.empty())
    {
        throw std::runtime_error("empty matrix");
    }

    uint16_t width = max_width(matrix);

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

int main()
{
    using namespace std;

    const int16_t MIN = -100, MAX = 100;
    uint16_t rows = 0, columns = 0;

    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> columns;

    vector<vector<int>> matrix;
    matrix.resize(rows, vector<int>(columns));

    try
    {
        set_random_numbers(matrix, MIN, MAX);
        cout << "Matrix:-\n"
             << matrix << '\n';

        int search_integer;
        cout << "Enter an integer to be searched: ";
        cin >> search_integer;

        pair<uint16_t, uint16_t> indices = search(matrix, search_integer);

        indices.first == 0
            ? cout << search_integer << " not found\n"
            : cout << search_integer << " found at position "
                   << indices.first << ", " << indices.second << '\n';
    }
    catch (std::exception &ex)
    {
        cout << "Exception Caught : " << ex.what() << '\n';
    }

    getch();
    return 0;
}

template <typename T>
std::pair<uint16_t, uint16_t> search(std::vector<std::vector<T>> &matrix, const T &key)
{
    if (matrix.empty())
    {
        throw std::runtime_error("empty matrix");
    }

    const uint16_t ROWS = matrix.size();

    for (uint16_t row_index = 0; row_index < ROWS; ++row_index)
    {
        uint16_t col_index = sentinel_linear_search(matrix[row_index], key);
        if (col_index > 0)
        {
            return std::make_pair(row_index + 1, col_index);
        }
    }
    return std::make_pair(0, 0);
}

template <typename T>
size_t sentinel_linear_search(std::vector<T> &row, const T &key)
{
    auto equal = []<typename V>(const V &element, const V &key)
    {
        const double PRECISION = 1e-2;
        return (std::is_floating_point_v<V>)
                   ? fabs(element - key) < PRECISION
                   : element == key;
    };

    const T temp = row.back();
    row.back() = key;
    size_t index = 0ULL;

    while (!equal(row.at(index), key))
    {
        ++index;
    }

    row.back() = temp;
    return (index < row.size() - 1 || equal(temp, key)) ? index + 1 : 0ULL;
}