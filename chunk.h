#ifndef clox_chunk_h
#define clox_chunk_h

#include "common.h"

// instruction for vm
typedef enum {
    OP_RETURN,
} OpCode;

// dynamic array of bytes (or 8 bit values)
typedef struct {
    int count;
    int capacity;
    uint8_t *code;
} Chunk;

void initChunk(Chunk *chunk);
void freeChunk(Chunk *chunk);
void writeChunk(Chunk* chunk, uint8_t byte);

#endif