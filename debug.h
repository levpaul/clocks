#ifndef clocks_debug_h
#define clocks_debug_h

void disassembleChunk(Chunk* chunk, const char* name);
int disassembleInstruction(Chunk* chunk, int offset);

#endif