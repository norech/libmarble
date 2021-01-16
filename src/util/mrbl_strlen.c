/*
** EPITECH PROJECT, 2021
** marble by Alexis Cheron
** File description:
** Source code
*/
#include <stdlib.h>

size_t mrbl_strlen(char *str)
{
    if (*str != '\0')
        return (mrbl_strlen(str + 1) + 1);
    return (0);
}