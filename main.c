#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 3
#define RANGE 100

void create_random_matrix(int mat[MAX][MAX]);
void print_matrix(int mat[MAX][MAX]);
void sort_matrix(int mat[MAX][MAX]);

int main() {
    int mat[MAX][MAX];
    
    create_random_matrix(mat);

    printf("\nUnsorted\n");
    print_matrix(mat);
    
    sort_matrix(mat);

    printf("\nSorted\n");
    print_matrix(mat);
    
    return 0;
}

void create_random_matrix(int mat[MAX][MAX]) {
    srand(time(NULL));
    for (int row = 0; row < MAX; ++row) {
        for (int column = 0; column < MAX; ++column) {
            mat[row][column]=(rand()%100)+1;
        }
    }
}

void print_matrix(int mat[MAX][MAX]){
    for (int row = 0; row < MAX; ++row) {
        for (int column = 0; column < MAX; ++column) {
            printf("%4d",mat[row][column]);
        }
        printf("\n");
    }
}

void sort_matrix(int mat[MAX][MAX]){
    for (int x = 0; x < MAX; ++x) {
        for (int y = 0; y < MAX; ++y) {
            for (int row = 0; row < MAX; ++row) {
                for (int column = 0; column < MAX; ++column) {
                    if(mat[x][y] < mat[row][column]){
                        int temp = mat[x][y];
                        mat[x][y]=mat[row][column];
                        mat[row][column]=temp;
                    }
                }
            }
        }
    }
}
