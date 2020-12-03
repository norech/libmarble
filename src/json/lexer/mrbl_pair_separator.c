/*
** MARBLE
**
** Project by:
** Alexis "Norech" CHERON
*/
#include <marble/internal/util.h>

int mrbl_pair_separator(char **str)
{
    return (mrbl_is_char(str, ':'));
}
