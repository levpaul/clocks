#include "common.h"
#include "chunk.h"
#include <stdio.h>

int main(int argc, const char* argv[]) {
  Chunk mine;

  initChunk(&mine);
  printf("%d\n", mine.len);
  writeChunk(&mine, OP_RETURN);
  printf("%d - %d\n", mine.len, mine.code[0]);
  printf("mainptr: %p\n", &mine.code);
  freeChunk(&mine);

  return 0;
}