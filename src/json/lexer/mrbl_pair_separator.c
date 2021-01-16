/*
** EPITECH PROJECT, 2021
** marble by Alexis Cheron
** File description:
** Source code
*/
#include <marble/internal/util.h>

int mrbl_pair_separator(char **str)
{
    return (mrbl_is_char(str, ':'));
}
