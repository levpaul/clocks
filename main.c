#include "chunk.h"
#include "common.h"
#include "debug.h"
#include "vm.h"
#include <stdio.h>

int main(int argc, const char* argv[]) {
  initVM();
  Chunk chunk;

  initChunk(&chunk);

  // Constant
  writeChunk(&chunk, OP_CONSTANT, 123);
  writeChunk(&chunk, addConstant(&chunk, 1.2), 123);

  writeChunk(&chunk, OP_CONSTANT, 124);
  writeChunk(&chunk, addConstant(&chunk, 3.4), 124);

  writeChunk(&chunk, OP_ADD, 124);

  writeChunk(&chunk, OP_CONSTANT, 124);
  writeChunk(&chunk, addConstant(&chunk, 5.6), 124);

  writeChunk(&chunk, OP_DIVIDE, 124);

  writeChunk(&chunk, OP_NEGATE, 123);

  writeChunk(&chunk, OP_RETURN, 123);

  interpret(&chunk);
  freeVM();
  freeChunk(&chunk);

  return 0;
}