/*
** MARBLE
**
** Project by:
** Alexis "Norech" CHERON
*/
#include <marble/internal/util.h>

bool mrbl_null(char **str)
{
    return (mrbl_is_word(str, "null"));
}