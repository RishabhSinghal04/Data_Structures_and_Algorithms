#pragma once

#include <iostream>
#include "matrix.h"

template <typename T>
void input(Matrix<T> &matrix)
{
    if (matrix.empty())
    {
        throw std::runtime_error("empty matrix");
    }
    const uint16_t ROWS = matrix.get_number_of_rows();
    const uint16_t COLUMNS = matrix.get_number_of_columns();

    for (uint16_t row_index = 0; row_index < ROWS; ++row_index)
    {
        for (uint16_t col_index = 0; col_index < COLUMNS; ++col_index)
        {
            std::cin >> matrix(row_index, col_index);
        }
    }
}

template <typename T>
void set_random_numbers(Matrix<T> &matrix, const int16_t &MIN, const int16_t &MAX)
{
    if (matrix.empty())
    {
        throw std::runtime_error("empty matrix");
    }
    else if (MIN > MAX)
    {
        throw std::runtime_error("range : min is greater than max");
    }

    const uint16_t ROWS = matrix.get_number_of_rows();
    const uint16_t COLUMNS = matrix.get_number_of_columns();

    std::random_device rd;
    using dist_t = std::conditional_t<std::is_floating_point_v<T>,
                                      std::uniform_real_distribution<T>,
                                      std::uniform_int_distribution<T>>;
    dist_t dist(MIN, MAX);

    for (uint16_t row_index = 0; row_index < ROWS; ++row_index)
    {
        for (uint16_t col_index = 0; col_index < COLUMNS; ++col_index)
        {
            matrix(row_index, col_index) = dist(rd);
        }
    }
}