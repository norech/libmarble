/*
** MARBLE
**
** Project by:
** Alexis "Norech" CHERON
*/
void mrbl_strcpy(char *dest, char *src)
{
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
}