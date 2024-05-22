#include <sys/time.h>
#include <stdio.h>

void loop(int a[], int size) {
    for (int i=0; i<size; i++) {
        a[i] = i;
    }
}

int main() {
    int size = 100000;
    int a[size];
    struct timeval tstart, tend;
    gettimeofday(&tstart, NULL);
    loop(a, size);
    gettimeofday(&tend, NULL);
    long seconds = (tend.tv_sec - tstart.tv_sec);
    long micros = ((seconds * 1000000) + tend.tv_usec) - (tstart.tv_usec);
    printf("Time elapsed is %ld seconds and %ld micros\n", seconds, micros);
    return 0;
}
