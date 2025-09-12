
#include "common.h"
#include "chunk.h"
#include "debug.h"

int main(int argc, const char *argv[]) {

    Chunk chunk;
    initChunk(&chunk);

    // index of constant in the constant array (aka ValueArray)
    int constant = addConstant(&chunk, 1.2);
    writeChunk(&chunk, OP_CONSTANT);
    // write the index of the constant
    writeChunk(&chunk, constant);

    writeChunk(&chunk, OP_RETURN);
    disassembleChunk(&chunk, "test chunk");

    freeChunk(&chunk);
    return 0;
}
