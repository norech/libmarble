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
#include <stdio.h>
#include <unistd.h>

static mrbl_object_t *parse_object_pairs(char **str)
{
    mrbl_object_t *object = malloc(sizeof(mrbl_object_t));

    object->next = NULL;
    mrbl_whitespace(str);
    if ((object->key = mrbl_string(str)) == NULL)
        return (NULL);
    mrbl_whitespace(str);
    mrbl_pair_separator(str);
    mrbl_whitespace(str);
    object->type = mrbl_parse_json_value(str, &(object->value));
    if (object->type == 999) {
        mrbl_free_object(object, false);
        return (NULL);
    }
    mrbl_whitespace(str);
    if (mrbl_comma(str)) {
        object->next = parse_object_pairs(str);
    }
    mrbl_whitespace(str);
    return (object);
}

mrbl_object_t *mrbl_parse_json_object(char **str)
{
    mrbl_object_t *object = NULL;

    if (!mrbl_object_open(str)) {
        return (NULL);
    }
    mrbl_whitespace(str);
    if (mrbl_object_close(str)) {
        object = malloc(sizeof(mrbl_object_t));
        object->type = MRBL_EMPTY;
        object->value.intval = 0;
        object->next = NULL;
        return (object);
    }
    object = parse_object_pairs(str);
    if (!mrbl_object_close(str)) {
        return (NULL);
    }
    return (object);
}