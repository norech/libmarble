/*
** MARBLE
**
** Project by:
** Alexis "Norech" CHERON
*/
#include <criterion/criterion.h>
#include <marble/internal/lexer.h>
#include <marble/internal/util.h>
#include <marble/common.h>
#include <marble/json.h>

Test(mrbl_parse_json, empty_parse)
{
    char *str = "{}";
    mrbl_json_t *json = mrbl_parse_json(str);
    cr_assert_not_null(json);
    cr_assert_eq(json->type, MRBL_OBJECT);
    mrbl_object_t *object = json->value;
    cr_assert_not_null(object);
    cr_assert_eq(object->type, MRBL_EMPTY);
    cr_assert_eq(object->next, (void *)0);
}

Test(mrbl_parse_json, parse_with_single_prop)
{
    char *str = "{ \"hello\": null }";
    mrbl_json_t *json = mrbl_parse_json(str);
    cr_assert_not_null(json);
    cr_assert_eq(json->type, MRBL_OBJECT);
    mrbl_object_t *object = json->value;
    cr_assert_not_null(object);
    cr_assert_str_eq(object->key, "hello");
    cr_assert_eq(object->type, MRBL_NULL);
    cr_assert_eq(object->next, (void *)0);
}

Test(mrbl_parse_json, parse_with_multiple_props)
{
    char *str = "{ \"hello\": null, \"world\": 18 }";
    mrbl_json_t *json = mrbl_parse_json(str);
    cr_assert_not_null(json);
    cr_assert_eq(json->type, MRBL_OBJECT);
    mrbl_object_t *object = json->value;
    cr_assert_not_null(object);
    cr_assert_str_eq(object->key, "hello");
    cr_assert_eq(object->type, MRBL_NULL);
    cr_assert_str_eq(object->next->key, "world");
    cr_assert_eq(object->next->type, MRBL_INT);
    cr_assert_eq(object->next->value, 18);
    cr_assert_eq(object->next->next, (void *)0);
}

Test(mrbl_parse_json, parse_with_object_nested)
{
    char *str = "{ \"hello\": { \"world\": null } }";
    mrbl_json_t *json = mrbl_parse_json(str);
    cr_assert_not_null(json);
    cr_assert_eq(json->type, MRBL_OBJECT);
    mrbl_object_t *object = json->value;
    cr_assert_not_null(object);
    cr_assert_str_eq(object->key, "hello");
    cr_assert_eq(object->type, MRBL_OBJECT);

    mrbl_object_t *subobject = object->value;
    cr_assert_not_null(subobject);
    cr_assert_str_eq(subobject->key, "world");
    cr_assert_eq(subobject->type, MRBL_NULL);
}

Test(mrbl_parse_json, parse_with_array_nested)
{
    char *str = "{ \"greeting\": [ \"hello\", \"world\" ] }";
    mrbl_json_t *json = mrbl_parse_json(str);
    cr_assert_not_null(json);
    cr_assert_eq(json->type, MRBL_OBJECT);
    mrbl_object_t *object = json->value;
    cr_assert_not_null(object);
    cr_assert_str_eq(object->key, "greeting");
    cr_assert_eq(object->type, MRBL_ARRAY);

    mrbl_array_t *array = object->value;
    cr_assert_not_null(array);
    cr_assert_eq(array->type, MRBL_STRING);
    cr_assert_str_eq(array->value, "hello");
    cr_assert_not_null(array->next);
    cr_assert_eq(array->next->type, MRBL_STRING);
    cr_assert_str_eq(array->next->value, "world");
}

Test(mrbl_parse_json, parse_with_object_nested_in_array)
{
    char *str = "{ \"greeting\": [ { \"hello\": \"world\" } ] }";
    mrbl_json_t *json = mrbl_parse_json(str);
    cr_assert_not_null(json);
    cr_assert_eq(json->type, MRBL_OBJECT);
    mrbl_object_t *object = json->value;
    cr_assert_not_null(object);
    cr_assert_str_eq(object->key, "greeting");
    cr_assert_eq(object->type, MRBL_ARRAY);

    mrbl_array_t *array = object->value;
    cr_assert_not_null(array);
    cr_assert_eq(array->type, MRBL_OBJECT);
    mrbl_object_t *subobject = array->value;
    cr_assert_eq(subobject->type, MRBL_STRING);
    cr_assert_str_eq(subobject->key, "hello");
    cr_assert_str_eq(subobject->value, "world");
}

Test(mrbl_parse_json, parse_with_two_objects_nested_in_array)
{
    char *str = "{ \"greeting\": [ { \"hello\": \"world\" } , { \"marvin\": 42 } ] }";
    mrbl_json_t *json = mrbl_parse_json(str);
    cr_assert_not_null(json);
    cr_assert_eq(json->type, MRBL_OBJECT);
    mrbl_object_t *object = json->value;
    cr_assert_not_null(object);
    cr_assert_str_eq(object->key, "greeting");
    cr_assert_eq(object->type, MRBL_ARRAY);

    mrbl_array_t *array = object->value;
    cr_assert_not_null(array);
    cr_assert_eq(array->type, MRBL_OBJECT);
    mrbl_object_t *subobject = array->value;
    mrbl_object_t *subobject_2 = array->next->value;
    cr_assert_eq(subobject->type, MRBL_STRING);
    cr_assert_str_eq(subobject->key, "hello");
    cr_assert_str_eq(subobject->value, "world");
    cr_assert_eq(subobject_2->type, MRBL_INT);
    cr_assert_str_eq(subobject_2->key, "marvin");
    cr_assert_eq(subobject_2->value, 42);
}

Test(mrbl_parse_json, parse_array)
{
    char *str = "[ 1, 2, 3 ]";
    mrbl_json_t *json = mrbl_parse_json(str);
    cr_assert_not_null(json);
    cr_assert_eq(json->type, MRBL_ARRAY);
    mrbl_array_t *array = json->value;
    cr_assert_not_null(array);
    cr_assert_eq(array->type, MRBL_INT);
    cr_assert_eq(array->value, 1);
    cr_assert_not_null(array->next);
    cr_assert_eq(array->next->type, MRBL_INT);
    cr_assert_eq(array->next->value, 2);
    cr_assert_not_null(array->next->next);
    cr_assert_eq(array->next->next->type, MRBL_INT);
    cr_assert_eq(array->next->next->value, 3);
    cr_assert_null(array->next->next->next);
}

Test(mrbl_parse_json, parse_empty)
{
    char *str = "";
    mrbl_json_t *json = mrbl_parse_json(str);
    cr_assert_null(json);
}