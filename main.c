#include "chunk.h"
#include "common.h"
#include "debug.h"
#include <stdio.h>

int main(int argc, const char *argv[]) {
  Chunk chunk;

  printf("asdf");
  initChunk(&chunk);

  // Constant
  printf("asdf");
  int constant = addConstant(&chunk, 1.2);
  writeChunk(&chunk, OP_CONSTANT, 1);
  writeChunk(&chunk, constant, 1);

  printf("asdf");
  // Return
  writeChunk(&chunk, OP_RETURN, 2);

  disassembleChunk(&chunk, "test chunk");
  freeChunk(&chunk);

  return 0;
}