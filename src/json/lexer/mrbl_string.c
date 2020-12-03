/*
** MARBLE
**
** Project by:
** Alexis "Norech" CHERON
*/
#include <marble/internal/util.h>
#include <unistd.h>
#include <stdio.h>

static enum mrbl_lex_code mrbl_string_char(char **buff, char **str)
{
    char c = '\0';

    if (**str == '"')
        return (MRBL_LEX_END);
    if (mrbl_is_char(str, '\\')) {
        c = mrbl_read_escaped_char(str);
    } else {
        c = mrbl_read_char(str);
    }
    if (c == '\0')
        return (MRBL_LEX_END);
    if (c == 26) {
        mrbl_addchar(buff, '\\');
        c = 'u';
    }
    mrbl_addchar(buff, c);
    return (MRBL_LEX_NEXT);
}

char *mrbl_string(char **str)
{
    char *buff = malloc(sizeof(char) * 10);
    int i = 0;

    *buff = '\0';
    if (!mrbl_is_char(str, '"')) {
        free(buff);
        return (NULL);
    }
    while (**str != '\0') {
        enum mrbl_lex_code code = mrbl_string_char(&buff, str);
        i++;
        if (code == MRBL_LEX_END)
            break;
    }
    if (!mrbl_is_char(str, '"')) {
        free(buff);
        return (NULL);
    }
    return (buff);
}