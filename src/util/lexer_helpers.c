/*
** MARBLE
**
** Project by:
** Alexis "Norech" CHERON
*/
#include <stdlib.h>
#include <stdio.h>
#include <marble/internal/util.h>

bool mrbl_is_whitespace(char **str)
{
    return (mrbl_is_char(str, ' ')
        || mrbl_is_char(str, '\t')
        || mrbl_is_char(str, '\n')
        || mrbl_is_char(str, '\r'));
}

bool mrbl_is_char(char **str, char c)
{
    if (**str != c)
        return (0);
    (*str)++;
    return (1);
}

bool mrbl_is_word(char **str, char *word)
{
    int i = 0;
    int len = mrbl_strlen(word);

    while (**str != '\0') {
        if (!mrbl_is_char(str, word[i]))
            break;
        i++;
    }
    return (i == len);
}

char mrbl_read_char(char **str)
{
    char c = **str;

    (*str)++;
    if (c < 32)
        return ('\0');
    return (c);
}

char mrbl_read_escaped_char(char **str)
{
    char c = *((*str)++);
    switch (c) {
        case 'b':
            return ('\b');
        case 'f':
            return ('\f');
        case 'n':
            return ('\n');
        case 'r':
            return ('\r');
        case 't':
            return ('\t');
        case 'u':
            return (26);
        case '\\':
        case '/':
        case '"':
            return (c);
    }
    return ('\0');
}