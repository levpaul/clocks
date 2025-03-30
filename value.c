#include <stdio.h>

#include "memory.h"
#include "value.h"

void initValueArray(ValueArray* array) {
    array->cap = 0;
    array->len = 0;
    array->values = NULL;
}

void writeValueArray(ValueArray* array, Value value) {
    if (array->len <= array->cap) {
        int oldCap = array->cap;
        array->cap = GROW_CAPACITY(oldCap);
        array->values = GROW_ARRAY(Value, array, oldCap, array->cap);
    }

    array->values[array->len] = value;
    array->len++;
}

void freeValueArray(ValueArray* array) {
    FREE_ARRAY(Value, array, array->cap);
    initValueArray(array);
}