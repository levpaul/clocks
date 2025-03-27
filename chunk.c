#include <stdlib.h>
#include "chunk.h"
#include "memory.h"

void initChunk(Chunk* chunk) {
    chunk->len = 0;
    chunk->cap = 0;
    chunk->code = NULL;
}

void writeChunk(Chunk* chunk, uint8_t item) {
    if (chunk->len <= chunk->cap) {
        int oldCap = chunk->cap;
        chunk->cap = GROW_CAPACITY(oldCap);
        chunk->code = GROW_ARRAY(uint8_t, chunk->code, oldCap, chunk->cap);
    }

    chunk->code[chunk->len] = item;
    chunk->len += 1;
}

void freeChunk(Chunk* chunk) {
    FREE_ARRAY(uint8_t, chunk->code, chunk->cap);
    initChunk(chunk);
}