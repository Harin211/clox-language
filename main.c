
#include "common.h"
#include "chunk.h"
#include "debug.h"
#include "vm.h"

int main(int argc, const char *argv[]) {

    initVM();

    Chunk chunk;
    initChunk(&chunk);

    // index of constant in the constant array (aka ValueArray)
    int constant = addConstant(&chunk, 1.2);
    writeChunk(&chunk, OP_CONSTANT, 123);
    // write the index of the constant
    writeChunk(&chunk, constant, 123);
    writeChunk(&chunk, OP_RETURN, 123);

    disassembleChunk(&chunk, "test chunk");
    
    interpret(&chunk);
    freeVM();
    freeChunk(&chunk);
    return 0;
}
