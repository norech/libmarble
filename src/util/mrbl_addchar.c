/*
** EPITECH PROJECT, 2021
** marble by Alexis Cheron
** File description:
** Source code
*/
#include <marble/internal/util.h>

void mrbl_addchar(char **buff, char c)
{
    int len = mrbl_strlen(*buff);

    if (len % 10 == 9) {
        mrbl_expand_string(buff, len + 11);
    }
    (*buff)[len] = c;
    (*buff)[len + 1] = '\0';
}