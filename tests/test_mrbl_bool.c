/*
** MARBLE
**
** Project by:
** Alexis "Norech" CHERON
*/
#include <criterion/criterion.h>
#include <marble/internal/lexer.h>
#include <marble/internal/util.h>

Test(mrbl_bool, _true_)
{
    char *str = mrbl_strdup("true");
    bool value;

    cr_assert_eq(mrbl_bool(&str, &value), true);
    cr_assert_eq(value, true);
}

Test(mrbl_bool, _false_)
{
    char *str = mrbl_strdup("false");
    bool value;

    cr_assert_eq(mrbl_bool(&str, &value), true);
    cr_assert_eq(value, false);
}

Test(mrbl_bool, not_bool)
{
    char *str = mrbl_strdup("null");
    bool value;

    cr_assert_eq(mrbl_bool(&str, &value), false);
}