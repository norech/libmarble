/*
** EPITECH PROJECT, 2021
** marble by Alexis Cheron
** File description:
** Source code
*/
#include <criterion/criterion.h>
#include <marble/internal/lexer.h>
#include <marble/internal/util.h>

Test(mrbl_string, can_get_string)
{
    char *str = mrbl_strdup("\"hello world\"");
    cr_assert_str_eq(mrbl_string(&str), "hello world");
}

Test(mrbl_string, can_get_string_with_escape)
{
    char *str = mrbl_strdup("\"say \\\"hello\\\" to the world\"");
    cr_assert_str_eq(mrbl_string(&str), "say \"hello\" to the world");
}

Test(mrbl_string, can_get_string_not_ended)
{
    char *str = mrbl_strdup("\"say");
    cr_assert_eq(mrbl_string(&str), NULL);
}