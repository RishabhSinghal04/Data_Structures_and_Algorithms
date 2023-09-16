#pragma once

#include <iostream>
#include <iomanip>
#include "matrix.h"

template <typename T>
std::ostream &operator<<(std::ostream &out, const Matrix<T> &matrix)
{
    if(matrix.empty())
    {
        throw std::runtime_error("empty matrix");
    }
    const uint16_t ROWS = matrix.get_number_of_rows();
    const uint16_t COLUMNS = matrix.get_number_of_columns();
    uint16_t width = max_width(matrix);

    for (uint16_t row_index = 0; row_index < ROWS; ++row_index)
    {
        for (uint16_t col_index = 0; col_index < COLUMNS; ++col_index)
        {
            out << std::setw(width + 2) << matrix(row_index, col_index);
        }
        out << '\n';
    }
    return out;
}

template <typename T>
uint16_t max_width(const Matrix<T> &matrix)
{
    const uint16_t ROWS = matrix.get_number_of_rows();
    const uint16_t COLUMNS = matrix.get_number_of_columns();
    uint16_t width = 0;

    for (uint16_t row_index = 0; row_index < ROWS; ++row_index)
    {
        for (uint16_t col_index = 0; col_index < COLUMNS; ++col_index)
        {
            std::stringstream ss{};
            ss << matrix(row_index, col_index);
            width = std::max<uint16_t>(width, ss.str().length());  
        }
    }
    return width;
}