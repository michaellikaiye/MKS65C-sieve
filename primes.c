#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
/*
 Input: an integer n > 1.
 
 Let A be an array of Boolean values, indexed by integers 2 to n,
 initially all set to true.
 
 for i = 2, 3, 4, ..., not exceeding √n:
   if A[i] is true:
     for j = i2, i2+i, i2+2i, i2+3i, ..., not exceeding n:
       A[j] := false.
 
 Output: all i such that A[i] is true.
*/

int sieve(int c) {
  int limit = 1.5 * c * log(c);
  bool *array = calloc(limit,sizeof(bool));
  int exit = sqrt((double)limit) + 1;
  int i = 2;
  int nj;
  for(i; i < exit; i++)
    if(*(array+i) == 0) { //checking for primes
      //printf("%d,",i);
      for(nj = 2 * i; nj < limit; nj += i) { 
        *(array+nj) = 1; //making not prime
      }
    }
  int p = 2;
  int size = 1;
  for(p; size - 1 != c; p++)
    if(*(array+p) == 0) { //checking for primes
      //printf("%d: %d, ", size,p);
      size++;
    }
  return p - 1;
}


int main(int argc, char * argv[]) {
  clock_t begin = clock();
  /* here, do your time-consuming job */
  int a = sieve(2000000);
  printf("%d\n",a);
  clock_t end = clock();
  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  printf("\ntime spent:\n%lfs\n\n",time_spent);
  clock_t begi = clock();
  
  /*
  int iterations = 1;
  int target = 1000000;
  if(argc > 1){
    target = atoi(argv[1]);
  }
  if(argc > 2){
    iterations = atoi(argv[2]);
  }


  int ans = 0;
  while(iterations>0){
      ans=sieve(target);
      iterations--;
      printf("The n=%d prime is %d\n", target, ans );
      //this is to modify which prime to
      //potentially avoid CPU caching
      target++;
  }
  */
  return 0;
}
