#include <stdio.h>
#include <stdlib.h>
#define SIZE 300

int main()
{
    int size = SIZE;

    int** A = malloc(size * sizeof(int*));
    int** B = malloc(size * sizeof(int*));
    int** C = malloc(size * sizeof(int*));

    for (int i = 0; i < size; i++) {
        A[i] = malloc(size * sizeof(int));
        B[i] = malloc(size * sizeof(int));
        C[i] = malloc(size * sizeof(int));
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            A[i][j] = rand() % size + 1;
            B[i][j] = rand() % size + 1;
        }
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            C[i][j] = 0;
            for (int k = 0; k < size; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    printf("C[100][100] = %d\n", C[100][100]);

    // free memory
    for (int i = 0; i < size; i++) {
        free(A[i]);
        free(B[i]);
        free(C[i]);
    }
    free(A);
    free(B);
    free(C);

    return 0;
}


