/*
** EPITECH PROJECT, 2021
** marble by Alexis Cheron
** File description:
** Source code
*/
#include <marble/internal/util.h>

bool mrbl_bool(char **str, bool *value)
{
    if (mrbl_is_word(str, "true")) {
        *value = true;
        return (true);
    } else if (mrbl_is_word(str, "false")) {
        *value = false;
        return (true);
    }
    return (false);
}