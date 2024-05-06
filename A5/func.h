#ifndef FUNC_H
#define FUNC_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum colormap_colors{
	COLORMAP_White, COLORMAP_Gray ,COLORMAP_Black
};

void print_header(int threads, int resources);
void print_matrix(int* mat, size_t n);
int dfs(int* mat, int n, int* colormap, int v);
void print_colormap(int* arr, size_t n);
int deadlock_cycle(int* mat, int n);


#endif
