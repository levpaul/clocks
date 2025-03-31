#include <stdio.h>

#include "chunk.h"
#include "debug.h"
#include "value.h"

void disassembleChunk(Chunk *chunk, const char *name) {
  printf("== %s ==\n", name);

  for (int offset = 0; offset < chunk->len;) {
    offset = disassembleInstruction(chunk, offset);
  }
}

int simpleInstruction(const char *operation_name, int offset) {
  printf("%s\n", operation_name);
  return offset + 1;
}

int constantInstruction(const char *operation_name, Chunk *chunk, int offset) {
  // this is the offset of the chunk's constants array where the constant lives
  uint8_t constant = chunk->code[offset + 1];
  printf("%-16s %4d '", operation_name, constant);
  printValue(chunk->constants.values[constant]);
  printf("'\n");
  return offset + 2;
}

// disassembleInstruction takes in a Chunk pointer and instruction offset. It
// prints information about the instruction at the given offset and returns the
// offset of the next instruction in the Chunk.
int disassembleInstruction(Chunk *chunk, int offset) {
  printf("%04d ", offset);
  if (offset > 0 && chunk->lines[offset] != chunk->lines[offset - 1]) {
    printf("    |");
  } else {
    printf("%4d ", chunk->lines[offset]);
  }
  u_int8_t instruction = chunk->code[offset];
  switch (instruction) {
  case OP_CONSTANT:
    return constantInstruction("OP_CONSTANT", chunk, offset);
  case OP_RETURN:
    return simpleInstruction("OP_RETURN", offset);
  default:
    printf("Unknown opcode %d\n", instruction);
    return offset + 1;
  }
}
