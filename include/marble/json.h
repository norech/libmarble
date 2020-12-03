/*
** MARBLE
**
** Project by:
** Alexis "Norech" CHERON
*/
#include <marble/common.h>

#ifndef MRBL_JSON_H
#define MRBL_JSON_H

typedef struct mrbl_json {
    mrbl_type_t type;
    void *value;
} mrbl_json_t;

mrbl_json_t *mrbl_parse_json(char *input);
void mrbl_free_json(mrbl_json_t *json);

#endif //MRBL_JSON_H
