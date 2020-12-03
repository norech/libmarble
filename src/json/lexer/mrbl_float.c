/*
** MARBLE
**
** Project by:
** Alexis "Norech" CHERON
*/
#include <marble/internal/lexer.h>
#include <marble/internal/util.h>

static bool parse_number(char **str, long *value)
{
    if (!(**str >= '0' && **str <= '9'))
        return (false);
    while (**str >= '0' && **str <= '9') {
        *value = *value * 10 + (**str - '0');
        (*str)++;
    }
    return (true);
}

static bool parse_exponent(char **str, double *value)
{
    bool negative = false;
    long exponent = 0;

    if (**str != '+' && **str != '-')
        return (false);
    negative = (**str == '-');
    (*str)++;
    if (!parse_number(str, &exponent))
        return (false);
    if (negative) {
        for (int i = 0; i < exponent; i++)
            *value /= 10;
    } else {
        for (int i = 0; i < exponent; i++)
            *value *= 10;
    }
    return (true);
}

static double convert_to_double(long whole, long decimals)
{
    double d_decimals = decimals;

    while (d_decimals >= 10) {
        d_decimals /= 10;
    }
    d_decimals /= 10;
    return (whole + d_decimals);
}

static bool parse_float(char **str, double *value)
{
    long whole = 0;
    long decimals = 0;

    *value = 0;
    if (!parse_number(str, &whole))
        return (false);
    if (!mrbl_is_char(str, '.'))
        return (false);
    if (!parse_number(str, &decimals))
        return (false);
    *value = convert_to_double(whole, decimals);
    return (true);
}

bool mrbl_float(char **str, double *value)
{
    char *input = *str;
    bool inverted = false;

    if (*input == '-') {
        inverted = true;
        input++;
    }
    if (!parse_float(&input, value))
        return (false);
    if (*input == 'e' || *input == 'E') {
        input++;
        if (!parse_exponent(&input, value))
            return (false);
    }
    if (inverted)
        *value = -*value;
    *str = input;
    return (true);
}