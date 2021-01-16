/*
** EPITECH PROJECT, 2021
** marble by Alexis Cheron
** File description:
** Source code
*/
#include <marble/internal/util.h>

bool mrbl_object_open(char **str)
{
    return (mrbl_is_char(str, '{'));
}
