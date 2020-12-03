/*
** MARBLE
**
** Project by:
** Alexis "Norech" CHERON
*/
#include <stdlib.h>

void mrbl_expand_string(char **str, size_t new_size)
{
    char *old_str = *str;
    char *new_str = malloc(sizeof(char) * new_size);
    size_t i = 0;

    while (old_str[i] != '\0') {
        new_str[i] = old_str[i];
        i++;
    }
    new_str[i] = '\0';
    *str = new_str;
    free(old_str);
}