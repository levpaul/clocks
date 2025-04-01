#ifndef clocks_value_h
#define clocks_value_h

#include "common.h"

typedef double Value;

typedef struct {
  int cap;
  int len;
  Value* values;
} ValueArray;

void initValueArray(ValueArray* array);
void writeValueArray(ValueArray* array, Value value);
void freeValueArray(ValueArray* array);

void printValue(Value);

#endif