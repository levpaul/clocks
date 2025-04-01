#include "chunk.h"
#include "memory.h"
#include <stdlib.h>

void initChunk(Chunk* chunk) {
  chunk->len = 0;
  chunk->cap = 0;
  chunk->code = NULL;
  chunk->lines = NULL;
  initValueArray(&chunk->constants);
}

void writeChunk(Chunk* chunk, uint8_t item, int line) {
  if (chunk->len <= chunk->cap) {
    int oldCap = chunk->cap;
    chunk->cap = GROW_CAPACITY(oldCap);
    chunk->code = GROW_ARRAY(uint8_t, chunk->code, oldCap, chunk->cap);
    chunk->lines = GROW_ARRAY(int, chunk->lines, oldCap, chunk->cap);
  }

  chunk->code[chunk->len] = item;
  chunk->lines[chunk->len] = line;
  chunk->len += 1;
}

void freeChunk(Chunk* chunk) {
  FREE_ARRAY(uint8_t, chunk->code, chunk->cap);
  FREE_ARRAY(int, chunk->lines, chunk->cap);
  freeValueArray(&chunk->constants);
  initChunk(chunk);
}

int addConstant(Chunk* chunk, Value value) {
  writeValueArray(&chunk->constants, value);
  // Return index of where the constant was written
  return chunk->constants.len - 1;
}