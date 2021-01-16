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

static mrbl_type_t parse_primitive_value(char **str, mrbl_u_type_t *value)
{
    if (mrbl_null(str)) {
        value->intval = 0;
        return (MRBL_NULL);
    }
    if (mrbl_float(str, &(value->floatval))) {
        return (MRBL_FLOAT);
    }
    if (mrbl_integer(str, &(value->intval))) {
        return (MRBL_INT);
    }
    if (mrbl_bool(str, &(value->boolval))) {
        return (MRBL_BOOL);
    }
    value->strval = mrbl_string(str);
    if (value->strval != NULL) {
        return (MRBL_STRING);
    }
    return (999);
}

mrbl_type_t mrbl_parse_json_value(char **str, mrbl_u_type_t *value)
{
    mrbl_type_t type = parse_primitive_value(str, value);

    if (type != 999)
        return (type);
    if (**str == '{') {
        value->objval = mrbl_parse_json_object(str);
        return (MRBL_OBJECT);
    }
    if (**str == '[') {
        value->arrval = mrbl_parse_json_array(str);
        return (MRBL_ARRAY);
    }
    return (999);
}