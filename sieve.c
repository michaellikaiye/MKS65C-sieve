#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
#include "sieve.h"

int sieve(int targetPrime) {
  if(targetPrime < 1)
    return -1;
  if(targetPrime == 1)
    return 2;
  int locLimit = .7 * targetPrime * (int)log(targetPrime);
  int numLimit = numLimit * 2;
  bool *arrayHalfed = calloc(locLimit,sizeof(bool));
  int locPrime = 0;
  int size = 2;
  for(locPrime; locPrime * locPrime < locLimit; locPrime++)
    if(*(arrayHalfed + locPrime) == 0) { 
      size++;
      int numPrime = 3 + (locPrime) * 2;
      int locComposite = (numPrime * numPrime - 3) / 2;
      for(locComposite; locComposite < locLimit; locComposite += numPrime)
        *(arrayHalfed + locComposite) = 1;
    }
  for(locPrime; size <= targetPrime;locPrime++)
    if(*(arrayHalfed + locPrime) == 0)
      size++;
  return  3 + (locPrime - 1) * 2;
}



/* int sieve(int targetPrime) { */
/*   int limit = 1.5 * targetPrime * log(targetPrime); */
/*   bool *array = calloc(limit,sizeof(bool)); */
/*   int exit = sqrt((double)limit) + 1; */
/*   int prime = 2; */
/*   int composite; */
/*   for(prime; prime < exit; prime++) */
/*     if(*(array+prime) == 0) { //checking for primes */
/*       //printf("%d,",i); */
/*       for(composite = 2 * prime; composite < limit; composite += prime) {  */
/*         *(array+composite) = 1; //making composite */
/*       } */
/*     } */
/*   int p = 2; */
/*   int size = 1; */
/*   for(p; size - 1 != targetPrime; p++) */
/*     if(*(array+p) == 0) { //checking for primes */
/*       //printf("%d: %d, ", size,p); */
/*       size++; */
/*     } */
/*   return p - 1; */
/* } */
