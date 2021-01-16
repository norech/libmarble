/*
** EPITECH PROJECT, 2021
** marble by Alexis Cheron
** File description:
** Source code
*/
#include <marble/common.h>

#ifndef MRBL_PARSER_H
#define MRBL_PARSER_H

mrbl_type_t mrbl_parse_json_value(char **str, void **value);
mrbl_array_t *mrbl_parse_json_array(char **str);
mrbl_object_t *mrbl_parse_json_object(char **str);

#endif //MRBL_PARSER_H