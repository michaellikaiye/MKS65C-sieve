#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "sieve.h"
//bitWise seems to have FAILED MEEEE

//location to the number it represents
int lTn(int l) {
  if(l%2 == 0)
    return 5 + 3 * l;
  else
    return 4 + 3 * l;
}

//number to location in arrayThird
int nTl(int n) {
  return (n - 4) / 3;
}

int sieve(int targetPrime) {
  //special small stuff
  if(targetPrime < 1)
    return -1;
  if(targetPrime == 1)
    return 2;
  if(targetPrime == 2)
    return 3;
  int locLimit; //onethird of actual limit
  //diff k value for magnitudes SET ZONES??
  if(targetPrime < 1000)
    locLimit = .5 * targetPrime * (int)log(targetPrime);
  else
    locLimit = .4 * targetPrime * (int)log(targetPrime);

  int exit = (int)sqrt(locLimit)/ 1.73; //sqrt 3
  char *arrayThird = calloc(locLimit,sizeof(char));
  int locPrime = 0;//represents number 5
  int size = 3;//5 is the 3rd prime
  for(locPrime; locPrime < exit; locPrime++) {
    if(*(arrayThird + locPrime) == 0) {
      size++;
      int numPrime = lTn(locPrime);
      int locComposite = nTl(numPrime * numPrime);
      //getting incremental rates for multiples of numPrime
      int t = 2 * numPrime;
      int m;
      if((locComposite - locPrime) % 2 == 0) //determines initial increment
	m = numPrime -  (numPrime + 1) / 3;
      else
	m = numPrime +  (numPrime + 1) / 3;
      //removing multiples
      for(locComposite; locComposite < locLimit; locComposite += m) {
	*(arrayThird + locComposite) = 1;
	m = t - m;
      }
    }
  }
  //counting up the rest of primes after sqrtlimit aka exit
  //potential to turn into segmented sieve from here, saves on mem
  for(locPrime; size <= targetPrime;locPrime++)
    if(*(arrayThird + locPrime) == 0)
      size++;
  return  lTn(locPrime - 1);
}
