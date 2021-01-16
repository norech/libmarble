/*
** EPITECH PROJECT, 2021
** marble by Alexis Cheron
** File description:
** Source code
*/
#include <stdbool.h>
#include <stdlib.h>

#ifndef MRBL_HELPERS_H
#define MRBL_HELPERS_H

enum mrbl_lex_code {
    MRBL_LEX_END,
    MRBL_LEX_NEXT
};

void mrbl_addchar(char **buff, char c);
bool mrbl_is_whitespace(char **str);
bool mrbl_is_char(char **str, char c);
bool mrbl_is_word(char **str, char *word);
char mrbl_read_char(char **str);
char mrbl_read_escaped_char(char **str);
void mrbl_strcpy(char *dest, char *src);
void mrbl_expand_string(char **str, size_t new_size);
size_t mrbl_strlen(char *str);
char *mrbl_strdup(char *str);

#endif //MRBL_HELPERS_H