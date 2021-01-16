/*
** EPITECH PROJECT, 2021
** marble by Alexis Cheron
** File description:
** Source code
*/

#include <criterion/criterion.h>
#include <marble/internal/parser.h>
#include <marble/internal/util.h>
#include <stdio.h>

Test(mrbl_parse_json_value, boolean)
{
    char *str = mrbl_strdup("true");
    void *value;

    cr_assert_eq(mrbl_parse_json_value(&str, &value), MRBL_BOOL);
}

Test(mrbl_parse_json_value, float_)
{
    char *str = mrbl_strdup("1.0");
    void *value;

    cr_assert_eq(mrbl_parse_json_value(&str, &value), MRBL_FLOAT);
}

Test(mrbl_parse_json_value, int_)
{
    char *str = mrbl_strdup("3");
    void *value;
    cr_assert_eq(mrbl_parse_json_value(&str, &value), MRBL_INT);
}

Test(mrbl_parse_json_value, null_)
{
    char *str = mrbl_strdup("null");
    void *value;

    cr_assert_eq(mrbl_parse_json_value(&str, &value), MRBL_NULL);
}

Test(mrbl_parse_json_value, string_)
{
    char *str = mrbl_strdup("\"hello\"");
    void *value;

    cr_assert_eq(mrbl_parse_json_value(&str, &value), MRBL_STRING);
}

Test(mrbl_parse_json_value, empty)
{
    char *str = mrbl_strdup("this is a random input");
    void *value;

    cr_assert_eq(mrbl_parse_json_value(&str, &value), 999);
}