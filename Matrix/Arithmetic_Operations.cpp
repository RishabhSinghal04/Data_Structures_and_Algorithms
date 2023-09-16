
#include <iostream>
#include <conio.h>

#include "matrix.h"
#include "fill_matrix.h"
#include "display_matrix.h"

int main()
{
     using namespace std;

     const int16_t MIN = -10, MAX = 10;
     const uint16_t ROWS = 3, COLUMNS = 3;
     try
     {
          Matrix<int16_t> matrix_1(ROWS, COLUMNS);
          Matrix<int16_t> matrix_2(ROWS, COLUMNS);

          set_random_numbers(matrix_1, MIN, MAX);
          set_random_numbers(matrix_2, MIN, MAX);

          cout << "Matrix 1 :-\n"
               << matrix_1 << '\n';
          cout << "Matrix 2 :-\n"
               << matrix_2 << '\n';

          Matrix<int16_t> addition = matrix_1 + matrix_2;
          Matrix<int16_t> subtraction = matrix_1 - matrix_2;

          cout << "Matrix 1 + Matrix 2 :-\n"
               << addition << '\n';
          cout << "Matrix 1 - Matrix 2 :-\n"
               << subtraction << '\n';

          matrix_1 += matrix_2;
          cout << "Matrix 1 = Matrix 1 + Matrix 2 :-\n"
               << matrix_1 << '\n';

          matrix_1 -= matrix_2;
          cout << "Matrix 1 = Matrix 1 - Matrix 2 :-\n"
               << matrix_1 << '\n';

          Matrix<int16_t> matrix_3(ROWS - 1, COLUMNS);
          Matrix<int16_t> matrix_4(ROWS, COLUMNS - 1);

          set_random_numbers(matrix_3, MIN, MAX);
          set_random_numbers(matrix_4, MIN, MAX);

          cout << "Matrix 3:-\n"
               << matrix_3 << '\n';
          cout << "Matrix 4:-\n"
               << matrix_4 << '\n';

          Matrix<int16_t> product = matrix_3 * matrix_4;

          cout << "Matrix 3 X Matrix 4 :-\n"
               << product << '\n';

          matrix_3 *= matrix_4;
          cout << "Matrix 3 = Matrix 3 X Matrix 4 :-\n"
               << matrix_3 << '\n';
     }
     catch (std::exception &ex)
     {
          cout << "Exception Caught : " << ex.what() << '\n';
     }
     Matrix<float> matrix_5(ROWS, COLUMNS - 1);
     Matrix<float> matrix_6(ROWS, COLUMNS - 1);

     set_random_numbers(matrix_5, MIN, MAX);
     set_random_numbers(matrix_6, MIN, MAX);

     cout << "Matrix 5:-\n"
          << matrix_5 << '\n';
     cout << "Matrix 6:-\n"
          << matrix_6 << '\n';
     try
     {
          Matrix<float> division = matrix_5 / matrix_6;

          cout << "Matrix 5 / Matrix 6 :-\n"
               << division << '\n';

          matrix_5 /= matrix_6;
          cout << "Matrix 5 = Matrix 5 / Matrix 6 :-\n"
               << matrix_5 << '\n';
     }
     catch (std::exception &ex)
     {
          cout << "Exception Caught : " << ex.what() << '\n';
     }

     getch();
     return 0;
}