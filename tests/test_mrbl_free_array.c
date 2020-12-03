/*
** MARBLE
**
** Project by:
** Alexis "Norech" CHERON
**
** These tests will only check if mrbl_free_array can cause crashes.
*/
#include <criterion/criterion.h>
#include <marble/json.h>

Test(mrbl_free_array, sample_recursive)
{
    char *str = "[ 1, 2, 3 ]";
    mrbl_json_t *json = mrbl_parse_json(str);
    mrbl_free_array(json->value, true);
}

Test(mrbl_free_array, sample_not_recursive)
{
    char *str = "{\"hello\": [ 1, 2, 3 ] }";
    mrbl_json_t *json = mrbl_parse_json(str);
    mrbl_free_array(json->value, false);
}

Test(mrbl_free_array, sample_recursive_with_sub_array)
{
    char *str = "[ [ 1, 2 ], 3 ]";
    mrbl_json_t *json = mrbl_parse_json(str);
    mrbl_free_array(json->value, true);
}

Test(mrbl_free_array, sample_recursive_with_sub_objects)
{
    char *str = "[ { \"hi\": \"there\" }, { \"world\": \"universe\" } ]";
    mrbl_json_t *json = mrbl_parse_json(str);
    mrbl_free_array(json->value, true);
}
