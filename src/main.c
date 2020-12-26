#include <stdio.h>
#include <stdlib.h>
#include "cube.h"
#include "chunk.h"

#define Add(X, x) X = (x + 1)

int main()
{
    cubeCalculation cc;
    Chunk chunk;
    //cube_set_pos(&cc, 0, 0, 0);
    cube_init(&cc);
    cube_calc(&cc);
    chunk_create_vertices(&chunk, &cc);
    //cc.ptr = cube_vertices_calc(&cc.x, &cc.y, &cc.z, &cc.X, &cc.Y, &cc.Z);
    //print(ptr);
    cube_console_print(cc.ptr);
    free(cc.ptr);
    free(chunk.vertices);

    printf("\n\n");
}
