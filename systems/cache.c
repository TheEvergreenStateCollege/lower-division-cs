#include <sys/time.h>

      void loop(int a[], int size) {
      	for (i=0; i&lt;size; i++) {
           a[i] = i;
        }
      }
      
      int main() {
      	int size = 100000;
        struct timeval tstart, tend;
        gettimeofday(&tstart, NULL);
        loop
        gettimeofday(&tend, NULL);
        //print the time difference
        return 0;
      }