/*
** MARBLE
**
** Project by:
** Alexis "Norech" CHERON
*/
#include <criterion/criterion.h>
#include <marble/internal/lexer.h>
#include <marble/internal/util.h>
#include <stdio.h>

Test(mrbl_integer, integer_v1)
{
    char *str = mrbl_strdup("1");
    long value = 0;

    cr_assert_eq(mrbl_integer(&str, &value), true);
    cr_assert_eq(value, 1.0);
}

Test(mrbl_integer, negative_integer)
{
    char *str = mrbl_strdup("-2");
    long value = 0;

    cr_assert_eq(mrbl_integer(&str, &value), true);
    cr_assert_eq(value, -2);
}

Test(mrbl_integer, integer_v2)
{
    char *str = mrbl_strdup("24");
    long value = 0;

    cr_assert_eq(mrbl_integer(&str, &value), true);
    cr_assert_eq(value, 24);
}

Test(mrbl_integer, integer_exp)
{
    char *str = mrbl_strdup("24e+1");
    long value = 0;

    cr_assert_eq(mrbl_integer(&str, &value), true);
    cr_assert_eq(value, 240);
}

Test(mrbl_integer, integer_exp_upper)
{
    char *str = mrbl_strdup("24E+1");
    long value = 0;

    cr_assert_eq(mrbl_integer(&str, &value), true);
    cr_assert_eq(value, 240);
}

Test(mrbl_integer, integer_exp_neg)
{
    char *str = mrbl_strdup("24e-1");
    long value = 0;

    cr_assert_eq(mrbl_integer(&str, &value), true);
    cr_assert_eq(value, 2);
}

Test(mrbl_integer, integer_exp_neg_upper)
{
    char *str = mrbl_strdup("24E-1");
    long value = 0;

    cr_assert_eq(mrbl_integer(&str, &value), true);
    cr_assert_eq(value, 2);
}