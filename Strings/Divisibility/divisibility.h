#pragma once

#include <string>
#include <cmath>

class Divisibility
{
    static inline const char zero = '0';

public:
    Divisibility() = default;

    static bool divisible_by_two(const std::string &num)
    {
        return (num[num.length() - 1] - zero) % 2 == 0;
    }

    static bool divisible_by_three(const std::string &num)
    {
        int64_t sum_of_digits = 0LL;

        for (const auto &digit : num)
        {
            sum_of_digits += (digit - zero);
        }

        return sum_of_digits % 3 == 0;
    }

    static bool divisible_by_four(const std::string &num)
    {
        int16_t last_digit = num[num.length() - 1] - zero;
        int16_t second_last_digit = num[num.length() - 2] - zero;

        return (last_digit + 10 * second_last_digit) % 4 == 0;
    }

    static bool divisible_by_five(const std::string &num)
    {
        return (num[num.length() - 1] - zero) % 5 == 0;
    }

    static bool divisible_by_six(const std::string &num)
    {
        return divisible_by_two(num) && divisible_by_three(num);
    }

    static bool divisible_by_seven(const std::string &num)
    {
        int remainder = 0, temp = 0;

        for (const auto &digit : num)
        {
            temp = remainder * 10 + (digit - zero);
            remainder = temp % 7;
        }

        return remainder == 0;

        /* num = 371
         * temp = 0, 0 x 10 + 3 = 3,  3 x 10 + 7 = 37,  2 x 10 + 1 = 21
         * rem = 0, 3 % 7 = 3,  37 % 7 = 2,  21 % 7 = 0
         * true
         */
    }

    static bool divisible_by_eight(const std::string &num)
    {
        int16_t last_digit = num[num.length() - 1] - zero;
        int16_t second_last_digit = num[num.length() - 2] - zero;
        int16_t third_last_digit = num[num.length() - 3] - zero;

        return (last_digit + 10 * second_last_digit + 100 * third_last_digit) % 8 == 0;
    }

    static bool divisible_by_nine(const std::string &num)
    {
        int64_t sum_of_digits = 0LL;

        for (const auto &digit : num)
        {
            sum_of_digits += (digit - zero);
        }

        return sum_of_digits % 9 == 0;
    }

    static bool divisible_by_ten(const std::string &num)
    {
        return num.ends_with("0");
    }

    static bool divisible_by_eleven(const std::string &num)
    {
        int64_t sum_of_odd_place_digits = 0LL, sum_of_even_place_digits = 0LL;

        for (size_t index = 0; index < num.length(); ++index)
        {
            (index % 2 == 0)
                ? sum_of_odd_place_digits += (num[index] - zero)
                : sum_of_even_place_digits += (num[index] - zero);
        }
        return abs(sum_of_even_place_digits - sum_of_odd_place_digits) % 11 == 0;
    }

    static bool divisible_by_twelve(const std::string &num)
    {
        return divisible_by_three(num) && divisible_by_four(num);
    }

    static bool divisible_by_thirteen(const std::string &num)
    {
        if (num.length() <= 3)
        {
            return std::stoi(num) % 13 == 0;
        }

        std::string_view temp{};

        temp = (num.length() % 3 == 1) ? "00" + num
                                       : ((num.length() % 3 == 2) ? "0" + num : num);
        int64_t index = temp.length() - 1LL, digits_sum = 0LL;
        int16_t sign_plus_minus = 1;

        while (index >= 0)
        {
            digits_sum += sign_plus_minus * ((temp[index] - zero) +
                                             (temp[--index] - zero) * 10 +
                                             (temp[--index] - zero) * 100);
            sign_plus_minus *= -1;
            --index;
        }
        return digits_sum % 13 == 0;
    }

    static bool divisible_by_fourteen(const std::string &num)
    {
        return divisible_by_two(num) && divisible_by_seven(num);
    }

    static bool divisible_by_fifteen(const std::string &num)
    {
        return divisible_by_three(num) && divisible_by_five(num);
    }
};