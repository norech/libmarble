/*
** EPITECH PROJECT, 2021
** marble by Alexis Cheron
** File description:
** Source code
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