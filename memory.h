#ifndef clocks_memory_h
#define clocks_memory_h

#include "common.h"
#define GROW_CAPACITY(capacity) \
    ((capacity) < 8 ? 8 : (capacity) * 2)

#define GROW_ARRAY(type, pointer, oldCount, newCount) \
    (type*)reallocate(pointer, sizeof(type) * (oldCount), \
        sizeof(type) * newCount)

#define FREE_ARRAY(type, ptr, oldCount) \
    reallocate(ptr, sizeof(type) * oldCount, 0)        

// Use size_t here as we'll be bounded by maximum system memory sizes
void* reallocate(void* ptr, size_t oldSize, size_t newSize);

#endif