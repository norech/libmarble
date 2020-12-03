/*
** MARBLE
**
** Project by:
** Alexis "Norech" CHERON
*/
#include <stdlib.h>
#include <marble/internal/util.h>

char *mrbl_strdup(char *str)
{
    int len = mrbl_strlen(str);
    char *dup = malloc(sizeof(char) * (len + 1));

    mrbl_strcpy(dup, str);
    dup[len] = '\0';
    return (dup);
}