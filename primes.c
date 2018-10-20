#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
#include "sieve.h"

/* int sieve(int targetPrime) { */
/*   int limit = 1.5 * targetPrime * log(targetPrime); */
/*   bool *array = calloc(limit,sizeof(bool)); */
/*   int sqrtLimit = sqrt((double)limit) + 1; */
/*   int prime = 2; */
/*   int composite; */
/*   for(prime; prime < sqrtLimit; prime++) */
/*     if(*(array+prime) == 0) { checking for primes */
/*       printf("%d,",i); */
/*       for(composite = 2 * prime; composite < limit; composite += prime) {  */
/*         *(array+composite) = 1; making composite */
/*       } */
/*     } */
/*   int p = 2; */
/*   int size = 1; */
/*   for(p; size - 1 != targetPrime; p++) */
/*     if(*(array+p) == 0) { checking for primes */
/*       printf("%d: %d, ", size,p); */
/*       size++; */
/*     } */
/*   return p - 1; */
/* } */

// loc 3 -> num 3 loc 4 -> num 5
int locToNum2(int location) {
  return 3 + (location - 3) * 2;
}

// n > 3
// num even -> ??
// num odd ex num 21 -> loc 12
int numToLoc2(int number) {
  return 3 + (number - 3) / 2;
}

int sieve2(int targetPrime) {
  int numLimit = 1.5 * targetPrime * log(targetPrime);
  int locLimit = 3 + numLimit / 2;
  bool *arrayHalfed = calloc(locLimit,sizeof(bool));
  int numSqrtLimit = sqrt((double)numLimit) + 1;
  int locSqrtLimit = 3 + numSqrtLimit / 2;
  int locPrime = 3;
  int numComposite;
  for(locPrime; locPrime < locSqrtLimit; locPrime++)
    if(*(arrayHalfed + locPrime) == 0) { //checking for primes
      //printf("%d,",i);
      int numPrime = locToNum2(locPrime);
      int numPrime2 = 2 * numPrime;
      for(numComposite = 3 * numPrime; numComposite < numLimit; numComposite += numPrime2) {
	int locComposite = numToLoc2(numComposite);
        *(arrayHalfed + locComposite) = 1; //making composite
      }
    }
  int locP = 3;
  int size = 2;
  for(locP; size - 1 != targetPrime; locP++)
    if(*(arrayHalfed + locP) == 0) { //checking for primes
      //printf("%d: %d, ", size,p);
      size++;
    }
  int numPm1 = locToNum2(locP - 1);
  return numPm1;
}



int main(){
  
  int ans = 0;
  clock_t begin;
  clock_t end;
  begin = clock();
  ans = sieve2(1000000);
  end = clock();
    
  printf("The n=%d prime is %d\n", 1000000, ans );
  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  printf("time spent: %lfs\n\n",time_spent);


  return 0;
}
