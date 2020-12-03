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

Test(mrbl_float, float_v1)
{
    char *str = mrbl_strdup("1.0");
    double value = 0;

    cr_assert_eq(mrbl_float(&str, &value), true);
    cr_assert_eq(value, 1.0);
}

Test(mrbl_float, float_v2)
{
    char *str = mrbl_strdup("2.5");
    double value = 0;

    cr_assert_eq(mrbl_float(&str, &value), true);
    cr_assert_eq(value, 2.5);
}

Test(mrbl_float, float_v3)
{
    char *str = mrbl_strdup("24.50");
    double value = 0;

    cr_assert_eq(mrbl_float(&str, &value), true);
    cr_assert_eq(value, 24.50);
}

Test(mrbl_float, float_exp)
{
    char *str = mrbl_strdup("24.5e+1");
    double value = 0;

    cr_assert_eq(mrbl_float(&str, &value), true);
    cr_assert_eq(value, 245.0);
}

Test(mrbl_float, float_exp_upper)
{
    char *str = mrbl_strdup("24.5E+1");
    double value = 0;

    cr_assert_eq(mrbl_float(&str, &value), true);
    cr_assert_eq(value, 245.0);
}

Test(mrbl_float, float_exp_neg)
{
    char *str = mrbl_strdup("245.0e-1");
    double value = 0;

    cr_assert_eq(mrbl_float(&str, &value), true);
    cr_assert_eq(value, 24.5);
}

Test(mrbl_float, float_exp_neg_upper)
{
    char *str = mrbl_strdup("24.5E-1");
    double value = 0;

    cr_assert_eq(mrbl_float(&str, &value), true);
    cr_assert_eq(value, 2.45);
}