/*
** EPITECH PROJECT, 2021
** marble by Alexis Cheron
** File description:
** Source code
*/
#include <marble/common.h>
#include <marble/internal/lexer.h>
#include <marble/internal/parser.h>
#include <stdlib.h>
#include <unistd.h>

static mrbl_array_t *parse_array_elements(char **str)
{
    mrbl_array_t *array = malloc(sizeof(mrbl_array_t));

    mrbl_whitespace(str);
    array->type = mrbl_parse_json_value(str, &(array->value));
    mrbl_whitespace(str);
    array->next = NULL;
    if (mrbl_comma(str)) {
        array->next = parse_array_elements(str);
    }
    mrbl_whitespace(str);
    return (array);
}

mrbl_array_t *mrbl_parse_json_array(char **str)
{
    mrbl_array_t *array = NULL;

    if (!mrbl_array_open(str)) {
        return (NULL);
    }
    mrbl_whitespace(str);
    if (mrbl_array_close(str)) {
        array = malloc(sizeof(mrbl_array_t));
        array->type = MRBL_EMPTY;
        array->next = NULL;
        return (array);
    }

    array = parse_array_elements(str);
    if (!mrbl_array_close(str)) {
        return (NULL);
    }
    return (array);
}