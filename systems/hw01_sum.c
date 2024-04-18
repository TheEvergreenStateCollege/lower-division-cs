#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int Sum(int k) ;

int main(int argc, char *argv[])
{
  for(int i = 1; i <= argc; i += 1)
  {
    printf("The sum of %d is %d\n", atoi(argv[i]), Sum(atoi(argv[i])));
  }

  return EXIT_SUCCESS;
}

int Sum(int k) 
{
  int result = 0;
  for(int i = 0; i <= k; i += 1) 
  {
    result += pow(2, i);
  }

  return result;
}