/*
** MARBLE
**
** Project by:
** Alexis "Norech" CHERON
*/
#include <marble/internal/util.h>

bool mrbl_object_close(char **str)
{
    return (mrbl_is_char(str, '}'));
}