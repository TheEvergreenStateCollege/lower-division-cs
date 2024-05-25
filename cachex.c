#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>


int **genRandomMatrix(int n, int max) {
    int i, j;
    int **mat = malloc(n * sizeof(int *));

    for (i = 0; i < n; i++) {
        mat[i] = malloc(n * sizeof(int));

        for (j = 0; j < n; j++) {
            mat[i][j] = 1 + rand() % max;
        }
    }

    return mat;
}


void free_all(int **mat, int n) {
    int i;

    for (i = 0; i < n; i++) {
        free(mat[i]);
    }

    free(mat);
}


float averageMat_v1(int **mat, int n) {
    int i, j, total = 0;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            // Note indexing: [i][j]
            total += mat[i][j];
        }
    }

    return (float) total / (n * n);
}


float averageMat_v2(int **mat, int n) {
    int i, j, total = 0;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            // Note indexing: [j][i]
            total += mat[j][i];
        }
    }

    return (float) total / (n * n);
}


int main(int argc, char** argv) {
   /* Validate command line parameters. */
   if (argc != 2) {
       fprintf(stderr, "usage: %s <n>\n", argv[0]);
       fprintf(stderr, "where <n> is the dimension of the matrix\n");
       return 1;
   }

   /* Declare and initialize variables. */
   int i;
   float res;
   double timer;
   int n = strtol(argv[1], NULL, 10);
   srand(time(NULL));
   struct timeval tstart, tend;
   int ** matrix = genRandomMatrix(n, 100);

   /* Time version 1. */
   gettimeofday(&tstart, NULL);
   res = averageMat_v1(matrix, n);
   gettimeofday(&tend, NULL);
   timer = tend.tv_sec - tstart.tv_sec + (tend.tv_usec - tstart.tv_usec)/1.e6;
   printf("v1 average is: %.2f; time is %g\n", res, timer);

   /* Time version 2. */
   gettimeofday(&tstart, NULL);
   res = averageMat_v2(matrix, n);
   gettimeofday(&tend, NULL);
   timer = tend.tv_sec - tstart.tv_sec + (tend.tv_usec - tstart.tv_usec)/1.e6;
   printf("v2 average is: %.2f; time is %g\n", res, timer);

   /* Clean up. */
   free_all(matrix, n);
   return 0;
}
