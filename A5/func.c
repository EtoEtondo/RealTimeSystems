#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"

void print_header(int threads, int resources){
int i;
    for (i = 1; i <= threads; i++) {
        char buf[64];
        snprintf(buf, sizeof(buf), "t%d", i); //speichert den char in buffer
         
        printf("%3s ", buf);
    }
 
    for (i = 1; i <= resources; i++) {
        char buf[64];
        snprintf(buf, sizeof(buf), "r%d", i); //r1 r2...
         
        printf("%3s ", buf);
    }
 
    printf("\n");
}

void print_matrix(int* mat, size_t n){
	size_t w,h;

	for(h=0;h<n;h++){
		for(w=0;w<n;w++){
			printf("%3d",mat[h*n+w]);
		}
	printf("\n");
	}
}

int dfs(int* mat, int n, int* colormap, int v){
printf("Teifensuche an Knoten %d\n",v);

switch (colormap[v]){
	case COLORMAP_Black:
		return 0;
	case COLORMAP_Gray:
		return 1;
	case COLORMAP_White:
		colormap[v]= COLORMAP_Gray;
		break;
	default:
		break;
}

for(int i=0;i<v;i++){
	if(mat[v*n+i]){
		if(dfs(mat,n,colormap,i)) return 1;
	}
}
colormap[v] = COLORMAP_Black;

return 0;
}

void print_colormap(int* arr, size_t n){
printf("colormap dump| ");
    size_t i;
    for (i = 0; i < n; i++) {
        char *str;
        switch (arr[i]) {
        case COLORMAP_White:
            str = "White";
            break;
        case COLORMAP_Gray:
            str = "Gray";
            break;
        case COLORMAP_Black:
            str = "Black";
            break;
        default:
            str = NULL;
        }
        printf("%s ", str);
    }
    printf("\n");

}

int deadlock_cycle(int* mat, int n){
int i;
    int ret = 0;
    int *colormap = (int *)malloc(n * sizeof(int));
 
    for (i = 0; i < n; i++) {
        colormap[i] = COLORMAP_White;
    }
 
    for (i = 0; i < n; i++) {
        printf("big dfs on %d\n", i);
        print_colormap(colormap, n);
        if (dfs(mat, n, colormap, i)) {
            ret = 1;
            break;
        }
    }
 
    free(colormap);
 
    return ret;

}
