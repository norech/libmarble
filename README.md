# marble

A small JSON parser for C.

## Usage

```c
char *json = "{ \"user\": \"john doe\", \"greeting\": [ { \"hello\": \"world\" }, { \"stuff\": 42 } ] }";
mrbl_json_t *root = mrbl_parse_json(json);

if(root->type != MRBL_OBJECT) // will check if root node is an object
    exit(84);

mrbl_object_t *pair1 = root->value;
printf("%s = %s", pair1->key, pair1->value); // will print: user = john doe

// Will iterate through each value of the object
// since mrbl_object_t is a linked list
for (mrbl_object_t *blk = root->value; blk->next != NULL; blk = blk->next) {
    switch (blk->type) {
    
        case MRBL_OBJECT:
            mrbl_object_t *child_object = blk->value;
            while (child_object->next != NULL) {
                char *key = child_object->key;
                mrbl_object_t *value = child_object->value.objval;
                // ...
                child_object = child_object->next;
            }
            break;
        
        case MRBL_ARRAY:
            mrbl_array_t *arr = blk->value.arrval;
            while (arr->next != NULL) {
                void *value = arr->value;
                // ...
                arr = arr->next;
            }
            break;
        
        case MRBL_STRING:
            char *value = blk->value.strval;
            // ...
            break;
        case MRBL_INT:
            long value = blk->value.intval;
            // ...
            break;
        
        case MRBL_FLOAT:
            double value = blk->value.floatval;
            // ...
            break;
        
        case MRBL_BOOL:
            bool value = blk->value.boolval;
            // ...
            break;
        
        case MRBL_NULL:
            // ...
            break;
        
        case MRBL_EMPTY:
            // no key-value pair was found inside of the object
        
    }
}
mrbl_free_json(root);
```

> You may also want to see example_program.

## Data types

| Marble Type       | Value Type        | Possible Values         |
|-------------------|-------------------|-------------------------|
| `MRBL_OBJECT`     | `mrbl_object_t *` | see `mrbl_object_t`     |
| `MRBL_ARRAY`      | `mrbl_array_t *`  | see `mrbl_object_t`     |
| `MRBL_NULL`       | -                 | -                       |
| `MRBL_EMPTY` (only when object/array is empty) | - | -          | 
| `MRBL_FLOAT`      | `double`          | -                       |
| `MRBL_INT`        | `long`            | -                       |
| `MRBL_BOOL`       | `bool` (`char`)   | `true` (1), `false` (0) |

> JSON is a format that does not differentiate float and int. So by default, marble will interpret numbers with explicitly written decimals as `MRBL_FLOAT` and numbers without decimals as `MRBL_INT`.
>
> When exponents are provided, `MRBL_INT` values are cut to the nearest integer (`55e-1` will become `5`). `MRBL_FLOAT` are not subject to this behaviour (so, `55.0e-1` will become `5.5`).

> `MRBL_STRING` does not support `\uXXXX`. Marble will simply print the it in the `char *` as-is.

```c
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
```
Both `mrbl_object_t` and `mrbl_array_t` are linked lists.
