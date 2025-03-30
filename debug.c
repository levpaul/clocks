#include <stdio.h>

#include "chunk.h"
#include "debug.h"

void disassembleChunk(Chunk* chunk, const char* name) {
    printf("== %s ==\n", name);

    for (int offset = 0; offset < chunk->len;){
        offset = disassembleInstruction(chunk, offset);
    }
}

int simpleInstruction(const char* operation_name, int offset) {
    printf("%s\n", operation_name);
    return offset + 1;
}

int disassembleInstruction(Chunk* chunk, int offset) {
    printf("%04d ", offset);
    u_int8_t instruction = chunk->code[offset];
    switch(instruction){
        case OP_RETURN:
            return simpleInstruction("OP_RETURN", offset);
        default:
            printf("Unknown opcode %d\n", instruction);
            return offset + 1;
    }
}
