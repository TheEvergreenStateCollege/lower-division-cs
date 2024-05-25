#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>

void loop(int a[], int size) {
    for (int i=0; i < size; i++) {
        a[i] = i;
    }
}
      
int main() {
    int size = 100000;
    struct timeval tstart, tend;
    int *arr = malloc(size * sizeof(int));

    gettimeofday(&tstart, NULL);
    loop (arr, size);
    gettimeofday(&tend, NULL);

    //print the time difference
    long elapsed = (tend.tv_sec - tstart.tv_sec) * 1000000 + tend.tv_usec-tstart.tv_usec;
    printf("Time elapsed: %ld microseconds\n", elapsed);
    free(arr);

    return 0;
}