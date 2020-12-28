#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define COUNT 10000

void mojang_cube_algorithm();
void mojang_cube_console_print(int *ptr);
void mojang_cube_calc(int *vertices, int x, int y, int z);

void cube_algorithm();
void cube_console_print(int **ptr);
int **cube_vertices_calc(int *x, int *y, int *z, int *X, int *Y, int *Z);

static const float positions[72] = {
	-1, -1, -1, -1, -1, +1, -1, +1, -1, -1, +1, +1,
	+1, -1, -1, +1, -1, +1, +1, +1, -1, +1, +1, +1,
	-1, +1, -1, -1, +1, +1, +1, +1, -1, +1, +1, +1,
	-1, -1, -1, -1, -1, +1, +1, -1, -1, +1, -1, +1,
	-1, -1, -1, -1, +1, -1, +1, -1, -1, +1, +1, -1,
	-1, -1, +1, -1, +1, +1, +1, -1, +1, +1, +1, +1};

int main()
{
	//just un-comment one and
	mojang_cube_algorithm();
	//cube_algorithm();
}

//mojangs way
void mojang_cube_algorithm()
{
	int *vertices = (int *)malloc(sizeof(int) * 72);
	for (int x = 0; x < COUNT; x++)
	{
		printf("%d\n", x);
		for (int y = 0; y < 1; y++)
			for (int z = 0; z < COUNT; z++)
			{
				mojang_cube_calc(vertices, x, y, z);
				//mojang_cube_console_print(vertices); //debuging print only
			}
	}
	free(vertices);
	printf("Done with mojang\n");
}
void mojang_cube_console_print(int *ptr)
{
	printf("__1__|__2__|__3__|__4__|__5__|__6__|__7__|__8__|__9__|__10__|_11_|_12_|\n");
	for (int i = 1; i <= 6; i++)
	{
		for (int x = 0; x < 12; x++)
		{
			printf("  %d,  ", ptr[(x * i)]);
		}
		printf("\n");
	}
}
void mojang_cube_calc(int *vertices, int x, int y, int z)
{
	for (int i = 0; i < 72;)
	{
		vertices[i] = x + positions[i];
		i++;
		vertices[i] = y + positions[i];
		i++;
		vertices[i] = y + positions[i];
	}
}
//Sam's way
void cube_algorithm()
{
	int x = 0, y = 0, z = 0, X1 = 1, Y1 = 1, Z1 = 1;

	int **vertices = cube_vertices_calc(&x, &y, &z, &X1, &Y1, &Z1);
	for (x = 0; x < COUNT; x++)
	{
		printf("%d\n", x);
		X1 = x + 1;
		for (y = 0; y < 1; y++)
		{
			Y1 = y + 1;
			for (z = 0; z < COUNT; z++)
			{
				Z1 = z + 1;
				//cube_console_print(vertices);
			}
		}
	}

	free(vertices);
	printf("Done with cube\n");
}
void cube_console_print(int **ptr)
{
	printf("__1__|__2__|__3__|__4__|__5__|__6__|__7__|__8__|__9__|__10__|_11_|_12_|\n");
	for (int i = 1; i <= 6; i++)
	{
		for (int x = 0; x < 12; x++)
		{
			printf("  %d,  ", *ptr[(x * i)]);
		}
		printf("\n");
	}
}

int **cube_vertices_calc(int *x, int *y, int *z, int *X, int *Y, int *Z)
{
	int **ptr = (int **)malloc(sizeof(int *) * 72);
	int *positions[72] = {
		x, Y, Z, X, Y, Z, X, Y, z, x, Y, z,
		x, y, z, X, y, z, X, y, Z, x, y, Z,
		x, y, z, x, y, Z, x, Y, Z, x, Y, z,
		X, y, Z, X, y, z, X, Y, z, X, Y, Z,
		X, y, z, x, y, z, x, Y, z, X, Y, z,
		x, y, Z, X, y, Z, X, Y, Z, x, Y, Z};

	bcopy(positions, ptr, sizeof(positions));
	//print(positions);
	return ptr;
}