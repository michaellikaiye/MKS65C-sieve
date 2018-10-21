#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "sieve.h"

int lTn(int l) {
  if(l%2 == 0)
    return 5 + 3 * l;
  else
    return 4 + 3 * l;
}
int nTl(int n) {
  return (n - 4) / 3;
}

int sieve(int targetPrime) {
  if(targetPrime < 1)
    return -1;
  if(targetPrime == 1)
    return 2;
  if(targetPrime == 2)
    return 3;
  int locLimit;
  if(targetPrime < 1000)
    locLimit = .5 * targetPrime * (int)log(targetPrime);//set zones?
  else
    locLimit = .4 * targetPrime * (int)log(targetPrime);

  int numLimit = numLimit * 3;
  int exit = (int)sqrt(locLimit) + 1;
  char *arrayThird = calloc(locLimit,sizeof(char));//change /8 +1
  int locPrime = 0;
  int size = 3;
  for(locPrime; locPrime < exit; locPrime++) {
    if(*(arrayThird + locPrime) == 0) {
      size++;
      int numPrime = lTn(locPrime);
      int locComposite = nTl(numPrime * numPrime);
      int t = 2 * numPrime;
      int m;
      if((locComposite - locPrime) % 2 == 0)
	m = numPrime -  (numPrime + 1) / 3;
      else
	m = numPrime +  (numPrime + 1) / 3;
      for(locComposite; locComposite < locLimit; locComposite += m) {
	*(arrayThird + locComposite) = 1;
	m = t - m;
      }
    }
  }
  for(locPrime; size <= targetPrime;locPrime++)
    if(*(arrayThird + locPrime) == 0)
      size++;
  return  lTn(locPrime - 1);
}


/* void set_bitTo1(char *array, int index) { */
/*   array[index/8] |= 1 << index/8; */
/* } */

/* int get_bit(char *array, int index) { */
/*   return 1 & (array[index / 8] >> (index % 8)); */
/* } */


/* int sieveBitWise(int targetPrime) { */
/*   if(targetPrime < 1) */
/*     return -1; */
/*   if(targetPrime == 1) */
/*     return 2; */
/*   if(targetPrime == 2) */
/*     return 3; */
/*   int locLimit; */
/*   if(targetPrime < 1000) */
/*     locLimit = .5 * targetPrime * (int)log(targetPrime);//set zones? */
/*   else */
/*     locLimit = .4 * targetPrime * (int)log(targetPrime); */

/*   int numLimit = numLimit * 3; */
/*   int exit = (int)sqrt(locLimit) + 1; */
/*   char *arrayThird = calloc(locLimit/8,sizeof(char));//change /8 +1 */
/*   int locPrime = 0; */
/*   int size = 3; */
/*   for(locPrime; locPrime < exit; locPrime++) { */
/*     if(get_bit(arrayThird, locPrime) == 0) { */
/*     //if(*(arrayThird + locPrime) == 0) { */
/*       size++; */
/*       int numPrime = lTn(locPrime); */
/*       int locComposite = nTl(numPrime * numPrime); */
/*       int t = 2 * numPrime; */
/*       int m; */
/*       if((locComposite - locPrime) % 2 == 0) */
/* 	m = numPrime -  (numPrime + 1) / 3; */
/*       else */
/* 	m = numPrime +  (numPrime + 1) / 3; */
/*       for(locComposite; locComposite < locLimit; locComposite += m) { */
/* 	//\*(arrayThird + locComposite) = 1; */
/* 	set_bitTo1(arrayThird, locComposite); */
/* 	m = t - m; */
/*       } */
/*     } */
/*   } */
/*   for(locPrime; size <= targetPrime;locPrime++) */
/*     if(get_bit(arrayThird, locPrime) == 0) */
/*       //if(*(arrayThird + locPrime) == 0) */
/*       size++; */
/*   return  lTn(locPrime - 1); */
/* } */


/* int sieveOdd(int targetPrime) { */
/*   if(targetPrime < 1) */
/*     return -1; */
/*   if(targetPrime == 1) */
/*     return 2; */
/*   int locLimit = .6 * targetPrime * (int)log(targetPrime); //below 3million? */
/*   int numLimit = numLimit * 2; */
/*   bool *arrayHalfed = calloc(locLimit,sizeof(bool)); */
/*   int locPrime = 0; */
/*   int size = 2; */
/*   for(locPrime; locPrime * locPrime < locLimit; locPrime++) */
/*     if(*(arrayHalfed + locPrime) == 0) { */
/*       size++; */
/*       int numPrime = 3 + (locPrime) * 2;//put in array */
/*       int locComposite = (numPrime * numPrime - 3) / 2; */
/*       for(locComposite; locComposite < locLimit; locComposite += numPrime)//exit at sqrt? */
/*         *(arrayHalfed + locComposite) = 1; */
/*       //put locComp - numPrime //flipped; into array? */
/*     } */
/*   //for(int i = 0; i<arraysize; i++){ */
/*   // call location in new array set sieve to equal false; */
/*   //} */
/*   //repeat size thing for each sieve?? */
/*   for(locPrime; size <= targetPrime;locPrime++) */
/*     if(*(arrayHalfed + locPrime) == 0) */
/*       size++; */
/*   return  3 + (locPrime - 1) * 2; */
/* } */



/* int sieveOG(int targetPrime) { */
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
