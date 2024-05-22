#include <sys/time.h>
#include <stdio.h>

    void loop(int a[], long size) {
        for (int i = 0; i < size; i++) {
           a[i] = i;
        }
    }
      
    int main() {
      	int size = 999999;
        int array[size];
        struct timeval tstart, tend;
        gettimeofday(&tstart, NULL);
        loop(array, size);
        gettimeofday(&tend, NULL);
        long elapsed = (tend.tv_sec - tstart.tv_sec) * 1000000 + tend.tv_usec-tstart.tv_usec;
        printf("%ld microseconds\n", elapsed);
        return 0;
      }