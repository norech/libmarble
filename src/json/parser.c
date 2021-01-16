/*
** EPITECH PROJECT, 2021
** marble by Alexis Cheron
** File description:
** Source code
*/
#include <marble/internal/parser.h>
#include <marble/json.h>
#include <stdbool.h>
#include <stdlib.h>

mrbl_json_t *mrbl_parse_json(char *input)
{
    mrbl_json_t *json = malloc(sizeof(mrbl_json_t));
    char *str = input;

    if (*input == '\0') {
        free(json);
        return (NULL);
    }
    json->type = mrbl_parse_json_value(&str, &(json->value));
    if (json->type == 999) {
        free(json);
        return (NULL);
    }
    return (json);
}