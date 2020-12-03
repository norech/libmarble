/*
** MARBLE
**
** Project by:
** Alexis "Norech" CHERON
*/
#include <marble/internal/util.h>

bool mrbl_array_open(char **str)
{
    return (mrbl_is_char(str, '['));
}