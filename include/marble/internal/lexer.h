/*
** EPITECH PROJECT, 2021
** marble by Alexis Cheron
** File description:
** Source code
*/
#include <stdbool.h>

#ifndef MRBL_LEXER_H
#define MRBL_LEXER_H

bool mrbl_array_close(char **str);
bool mrbl_array_open(char **str);
bool mrbl_object_close(char **str);
bool mrbl_object_open(char **str);
char *mrbl_string(char **str);
int mrbl_whitespace(char **str);
int mrbl_pair_separator(char **str);
bool mrbl_comma(char **str);
bool mrbl_float(char **str, double *value);
bool mrbl_integer(char **str, long *value);
bool mrbl_null(char **str);
bool mrbl_bool(char **str, bool *value);

#endif //MRBL_LEXER_H