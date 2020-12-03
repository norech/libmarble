/*
** MARBLE
**
** Project by:
** Alexis "Norech" CHERON
**
** These tests will only check if mrbl_free_object can cause crashes.
*/
#include <criterion/criterion.h>
#include <marble/json.h>

Test(mrbl_free_object, sample_recursive)
{
    char *str = "{\"hello\": \"world\", \"sample\": 10}";
    mrbl_json_t *json = mrbl_parse_json(str);
    mrbl_free_object(json->value, true);
}

Test(mrbl_free_object, sample_not_recursive)
{
    char *str = "{\"hello\": \"world\", \"sample\": 10}";
    mrbl_json_t *json = mrbl_parse_json(str);
    mrbl_free_object(json->value, false);
}

Test(mrbl_free_object, sample_recursive_with_array)
{
    char *str = "{\"hello\": \"world\", \"sample\": [10, 20]}";
    mrbl_json_t *json = mrbl_parse_json(str);
    mrbl_free_object(json->value, false);
}

Test(mrbl_free_object, sample_recursive_with_sub_objects)
{
    char *str = "{\"hello\": \"world\", \"sample\": { \"data1\": 10, \"data2\": 20 }}";
    mrbl_json_t *json = mrbl_parse_json(str);
    mrbl_free_object(json->value, false);
}
