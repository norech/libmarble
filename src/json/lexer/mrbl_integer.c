/*
** MARBLE
**
** Project by:
** Alexis "Norech" CHERON
*/
#include <stdbool.h>

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

static bool parse_exponent(char **str, long *value)
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

bool mrbl_integer(char **str, long *value)
{
    char *input = *str;
    bool inverted = false;

    *value = 0;
    if (*input == '-') {
        inverted = true;
        input++;
    }
    if (!parse_number(&input, value))
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