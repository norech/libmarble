/*
** EPITECH PROJECT, 2021
** marble by Alexis Cheron
** File description:
** Source code
*/
#include <stdbool.h>

#ifndef MRBL_COMMON_H
#define MRBL_COMMON_H

typedef enum {
    MRBL_EMPTY,
    MRBL_NULL,
    MRBL_BOOL,
    MRBL_INT,
    MRBL_FLOAT,
    MRBL_STRING,
    MRBL_ARRAY,
    MRBL_OBJECT,
} mrbl_type_t;

typedef union mrbl_u_type {
    char *strval;
    bool boolval;
    long intval;
    double floatval;
    struct mrbl_array *arrval;
    struct mrbl_object *objval;
} mrbl_u_type_t;

typedef struct mrbl_object {
    mrbl_type_t type;
    char *key;
    union mrbl_u_type value;
    struct mrbl_object *next;
} mrbl_object_t;

typedef struct mrbl_array {
    mrbl_type_t type;
    union mrbl_u_type value;
    struct mrbl_array *next;
} mrbl_array_t;

void mrbl_free_object(mrbl_object_t *object, bool recursive);
void mrbl_free_array(mrbl_array_t *array, bool recursive);

#endif //MRBL_COMMON_H