/*
** EPITECH PROJECT, 2021
** marble by Alexis Cheron
** File description:
** Source code
*/
#include <marble/common.h>
#include <marble/json.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

static void mrbl_free_value(mrbl_type_t type, mrbl_u_type_t *value)
{
    switch (type) {
        case MRBL_OBJECT:
            mrbl_free_object(value->objval, true);
            break;
        case MRBL_ARRAY:
            mrbl_free_array(value->arrval, true);
            break;
        case MRBL_STRING:
            if (value->strval != NULL) {
                free(value->strval);
            }
            break;
        default:
            break;
    }
}

void mrbl_free_object(mrbl_object_t *object, bool recursive)
{
    mrbl_object_t *tmp;

    while (object != NULL) {
        tmp = object->next;
        if (recursive)
            mrbl_free_value(object->type, &(object->value));
        if (object->type != MRBL_EMPTY)
            free(object->key);
        free(object);
        object = tmp;
    }
}

void mrbl_free_array(mrbl_array_t *array, bool recursive)
{
    mrbl_array_t *tmp;

    while (array != NULL) {
        tmp = array->next;
        if (array == NULL)
            return;
        if (recursive)
            mrbl_free_value(array->type, &(array->value));
        free(array);
        array = tmp;
    }
}

void mrbl_free_json(mrbl_json_t *json)
{
    mrbl_free_value(json->type, &(json->value));
    free(json);
}