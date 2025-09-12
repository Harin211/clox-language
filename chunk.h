#ifndef clox_chunk_h
#define clox_chunk_h

#include "common.h"
#include "value.h"

// instruction for vm
typedef enum {
    OP_CONSTANT,
    OP_RETURN,
} OpCode;

// dynamic array of bytes (or 8 bit values)
typedef struct {
    int count;
    int capacity;
    uint8_t *code;
    int *lines;
    ValueArray constants;
} Chunk;

// initalize a chunk
void initChunk(Chunk *chunk);
// free the memory of the chunk
void freeChunk(Chunk *chunk);
// add a byte to chunk. Grow chunk if size is too small
void writeChunk(Chunk* chunk, uint8_t byte, int line);

// adds constant to ValueArray and returns the current index of the chunk
int addConstant(Chunk* chunk, Value value);

#endif