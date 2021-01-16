/*
** EPITECH PROJECT, 2021
** marble by Alexis Cheron
** File description:
** Source code
*/
#include <marble/internal/util.h>
#include <stdbool.h>

int mrbl_whitespace(char **str)
{
    int i = 0;
    while (mrbl_is_whitespace(str))
        i++;
    return (i);
}