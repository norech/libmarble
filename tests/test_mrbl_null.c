/*
** EPITECH PROJECT, 2021
** marble by Alexis Cheron
** File description:
** Source code
*/
#include <criterion/criterion.h>
#include <marble/internal/lexer.h>
#include <marble/internal/util.h>

Test(mrbl_null, null)
{
    char *str = mrbl_strdup("null");
    cr_assert_eq(mrbl_null(&str), true);
}

Test(mrbl_null, not_null)
{
    char *str = mrbl_strdup("none");
    cr_assert_eq(mrbl_null(&str), false);
}

Test(mrbl_null, nothing)
{
    char *str = mrbl_strdup("");
    cr_assert_eq(mrbl_null(&str), false);
}
