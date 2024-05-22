#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>

void loop(int a[], int size) {
  for (int i=0; i < size; i++) {
     a[i] = i;
  }
}

int main(int argc, char *argv[])
{
  int size = strtol(argv[1], NULL, 10);
  int a[size];
  struct timeval tstart, tend;
  gettimeofday(&tstart, NULL);
  loop(a, size);
  gettimeofday(&tend, NULL);
  printf("%f\n", tend.tv_sec - tstart.tv_sec + (tend.tv_usec - tstart.tv_usec)/1.e6);
  return EXIT_SUCCESS;
}
