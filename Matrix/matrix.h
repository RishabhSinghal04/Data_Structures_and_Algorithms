#pragma once

#include <concepts>
#include <random>
#include <vector>

template <typename T>
concept Numeric = std::is_arithmetic_v<T>;

template <Numeric T>
class Matrix
{
    std::vector<std::vector<T>> matrix{};
    uint16_t rows = 0, columns = 0;
    const std::string range_message{"Out of range"},
        message_empty{"empty matirx"},
        size_message{"Size of matrices is not equal"};

public:
    Matrix() {}

    Matrix(const uint16_t &rows)
        : Matrix(rows, rows) {}

    Matrix(const uint16_t &rows, const uint16_t &columns)
        : rows{rows}, columns{columns}
    {
        matrix.resize(rows, std::vector<T>(columns));
    }

    Matrix(const Matrix &other_matrix)
        : matrix{other_matrix.matrix} {}

    Matrix(Matrix &&other_matrix)
        : matrix(std::move(other_matrix.matrix)) {}

    bool empty() const { return rows == 0; }
    bool equal_size(const Matrix<T> &other_matrix) const
    {
        return (rows == other_matrix.rows &&
                columns == other_matrix.columns);
    }

    void clear()
    {
        matrix.clear();
        rows = 0;
        columns = 0;
    }

    /* _Getters_ */
    const uint16_t get_number_of_rows() const { return rows; }
    const uint16_t get_number_of_columns() const { return columns; }

    T &operator()(const size_t &row_index, const size_t &column_index)
    {
        return (row_index >= rows || column_index >= columns)
                   ? throw std::out_of_range(range_message)
                   : matrix[row_index][column_index];
    }

    const T &operator()(const size_t &row_index, const size_t &column_index) const
    {
        return (row_index >= rows || column_index >= columns)
                   ? throw std::out_of_range(range_message)
                   : matrix[row_index][column_index];
    }

    /* _Setters_ */
    void set_size(const uint16_t &rows, const uint16_t &columns)
    {
        this->rows = rows;
        this->columns = columns;
        matrix.resize(rows, std::vector<T>(columns));
    }

    void operator=(const Matrix<T> &other_matrix)
    {
        rows = other_matrix.rows;
        columns = other_matrix.columns;
        matrix = other_matrix.matrix;
    }
    void operator=(Matrix<T> &&other_matrix)
    {
        rows = other_matrix.rows;
        columns = other_matrix.columns;
        matrix = std::move(other_matrix.matrix);
    }

    /* _Arithematic Operations_ */
    Matrix<T> operator+(const Matrix<T> &second_matrix) const
    {
        if (empty())
        {
            throw std::runtime_error(message_empty);
        }
        if (!equal_size(second_matrix))
        {
            throw std::invalid_argument(size_message);
        }

        Matrix<T> resultant_matrix(rows, columns);

        for (uint16_t row_index = 0; row_index < rows; ++row_index)
        {
            for (uint16_t col_index = 0; col_index < columns; ++col_index)
            {
                resultant_matrix(row_index, col_index) = matrix[row_index][col_index] +
                                                         second_matrix(row_index, col_index);
            }
        }
        return resultant_matrix;
    }

    void operator+=(const Matrix<T> &rhs_matrix)
    {
        if (empty())
        {
            throw std::runtime_error(message_empty);
        }
        if (!equal_size(rhs_matrix))
        {
            throw std::invalid_argument(size_message);
        }

        for (uint16_t row_index = 0; row_index < rows; ++row_index)
        {
            for (uint16_t col_index = 0; col_index < columns; ++col_index)
            {
                matrix[row_index][col_index] += rhs_matrix(row_index, col_index);
            }
        }
    }

    Matrix<T> operator-(const Matrix<T> &second_matrix) const
    {
        if (empty())
        {
            throw std::runtime_error(message_empty);
        }
        if (!equal_size(second_matrix))
        {
            throw std::invalid_argument(size_message);
        }

        Matrix<T> resultant_matrix(rows, columns);

        for (uint16_t row_index = 0; row_index < rows; ++row_index)
        {
            for (uint16_t col_index = 0; col_index < columns; ++col_index)
            {
                resultant_matrix(row_index, col_index) = matrix[row_index][col_index] -
                                                         second_matrix(row_index, col_index);
            }
        }
        return resultant_matrix;
    }

    void operator-=(const Matrix<T> &rhs_matrix)
    {
        if (empty())
        {
            throw std::runtime_error(message_empty);
        }
        if (!equal_size(rhs_matrix))
        {
            throw std::invalid_argument(size_message);
        }

        for (uint16_t row_index = 0; row_index < rows; ++row_index)
        {
            for (uint16_t col_index = 0; col_index < columns; ++col_index)
            {
                matrix[row_index][col_index] -= rhs_matrix(row_index, col_index);
            }
        }
    }

    Matrix<T> operator*(const Matrix<T> &second_matrix) const
    {
        if (empty())
        {
            throw std::runtime_error(message_empty);
        }
        if (columns != second_matrix.rows)
        {
            throw std::invalid_argument("number of columns of 1st matrix is not equal to number of rows of 2nd matrix");
        }

        const uint16_t COLUMNS = second_matrix.columns;
        Matrix<T> resultant_matrix(rows, COLUMNS);

        for (uint16_t row_index = 0; row_index < rows; ++row_index)
        {
            for (uint16_t col_index = 0; col_index < COLUMNS; ++col_index)
            {
                T sum{};
                for (uint16_t temp = 0; temp < columns; ++temp)
                {
                    sum += matrix[row_index][temp] * second_matrix(temp, col_index);
                }
                resultant_matrix(row_index, col_index) = sum;
            }
        }
        return resultant_matrix;
    }

    void operator*=(const Matrix<T> &rhs_matrix)
    {
        if (empty())
        {
            throw std::runtime_error(message_empty);
        }
        if (columns != rhs_matrix.rows)
        {
            throw std::invalid_argument("number of columns of 1st matrix is not equal to number of rows of 2nd matrix");
        }

        const uint16_t COLUMNS = rhs_matrix.columns;
        Matrix<T> resultant_matrix(rows, COLUMNS);

        for (uint16_t row_index = 0; row_index < rows; ++row_index)
        {
            for (uint16_t col_index = 0; col_index < COLUMNS; ++col_index)
            {
                T sum{};
                for (uint16_t temp = 0; temp < columns; ++temp)
                {
                    sum += matrix[row_index][temp] * rhs_matrix(temp, col_index);
                }
                resultant_matrix(row_index, col_index) = sum;
            }
        }
        columns = COLUMNS;
        matrix = std::move(resultant_matrix.matrix);
    }

    Matrix<T> operator/(const Matrix<T> &second_matrix) const
    {
        if (empty())
        {
            throw std::runtime_error(message_empty);
        }
        if (!equal_size(second_matrix))
        {
            throw std::invalid_argument(size_message);
        }

        Matrix<T> resultant_matrix(rows, columns);

        for (uint16_t row_index = 0; row_index < rows; ++row_index)
        {
            for (uint16_t col_index = 0; col_index < columns; ++col_index)
            {
                (second_matrix(row_index, col_index) == 0)
                    ? throw std::runtime_error("cannot divide by zero")
                    : resultant_matrix(row_index, col_index) = matrix[row_index][col_index] /
                                                               second_matrix(row_index, col_index);
            }
        }
        return resultant_matrix;
    }

    void operator/=(const Matrix<T> &second_matrix)
    {
        if (empty())
        {
            throw std::runtime_error(message_empty);
        }
        if (!equal_size(second_matrix))
        {
            throw std::invalid_argument(size_message);
        }

        for (uint16_t row_index = 0; row_index < rows; ++row_index)
        {
            for (uint16_t col_index = 0; col_index < columns; ++col_index)
            {
                (second_matrix(row_index, col_index) == 0)
                    ? throw std::runtime_error("cannot divide by zero")
                    : matrix[row_index][col_index] /= second_matrix(row_index, col_index);
            }
        }
    }
};