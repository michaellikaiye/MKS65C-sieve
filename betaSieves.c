#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
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

char *arrayThird; //needs this
void locationPlus(int *arr,int p) {
  arr[0] += p;
  int tr = arr[2] + p;
  while(tr>7) {
    arr[1] += 1;
    tr -= 8;
  }
  arr[2] = tr;
}

void set_bitTo1l(int *k) {
  arrayThird[k[1]] |= 1 << k[2];
}

int get_bitl(int *k) {
  return 1 & (arrayThird[k[1]] >> k[2]);
}
int sieveNoModDivideBitWise(int targetPrime) {
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
  arrayThird = calloc(locLimit/8,sizeof(char));//change /8 +1
  int locPrime[3] = {0,0,0};
  int size = 3;
  for(locPrime[0]; locPrime[0] < exit; locationPlus(locPrime, 1)) {
    if(get_bitl(locPrime) == 0) {
    //if(*(arrayThird + locPrime) == 0) {
      size++;
      int numPrime = lTn(locPrime[0]);
      int locComposite[3] = {0,0,0};
      locationPlus(locComposite, nTl(numPrime * numPrime));
      int t = 2 * numPrime;
      int m;
      if((locComposite[0] - locPrime[0]) % 2 == 0)
	m = numPrime -  (numPrime + 1) / 3;
      else
	m = numPrime +  (numPrime + 1) / 3;
      for(locComposite[0]; locComposite[0] < locLimit; locationPlus(locComposite, m)) {
	//*(arrayThird + locComposite) = 1;
	set_bitTo1l(locComposite);
	m = t - m;
      }
    }
  }
  for(locPrime[0]; size <= targetPrime; locationPlus(locPrime, 1))
    if(get_bitl(locPrime) == 0)
      //if(*(arrayThird + locPrime) == 0)
      size++;
  return  lTn(locPrime[0] - 1);
}

void set_bitTo1(char *array, int index) {
  array[index/8] |= 1 << index%8;
}

int get_bit(char *array, int index) {
  return 1 & (array[index / 8] >> (index % 8));
}


int sieveBitWise(int targetPrime) {
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
  char *arrayThird = calloc(locLimit/8,sizeof(char));//change /8 +1
  int locPrime = 0;
  int size = 3;
  for(locPrime; locPrime < exit; locPrime++) {
    if(get_bit(arrayThird, locPrime) == 0) {
    //if(*(arrayThird + locPrime) == 0) {
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
	//*(arrayThird + locComposite) = 1;
	set_bitTo1(arrayThird, locComposite);
	m = t - m;
      }
    }
  }
  for(locPrime; size <= targetPrime;locPrime++)
    if(get_bit(arrayThird, locPrime) == 0)
      //if(*(arrayThird + locPrime) == 0)
      size++;
  return  lTn(locPrime - 1);
}


int sieveOdd(int targetPrime) {
  if(targetPrime < 1)
    return -1;
  if(targetPrime == 1)
    return 2;
  int locLimit = .6 * targetPrime * (int)log(targetPrime); //below 3million?
  int numLimit = numLimit * 2;
  bool *arrayHalfed = calloc(locLimit,sizeof(bool));
  int locPrime = 0;
  int size = 2;
  for(locPrime; locPrime * locPrime < locLimit; locPrime++)
    if(*(arrayHalfed + locPrime) == 0) {
      size++;
      int numPrime = 3 + (locPrime) * 2;//put in array
      int locComposite = (numPrime * numPrime - 3) / 2;
      for(locComposite; locComposite < locLimit; locComposite += numPrime)
        *(arrayHalfed + locComposite) = 1;
    }

  for(locPrime; size <= targetPrime;locPrime++)
    if(*(arrayHalfed + locPrime) == 0)
      size++;
  return  3 + (locPrime - 1) * 2;
}



int sieveOG(int targetPrime) {
  int limit = 1.5 * targetPrime * log(targetPrime);
  bool *array = calloc(limit,sizeof(bool));
  int exit = sqrt((double)limit) + 1;
  int prime = 2;
  int composite;
  for(prime; prime < exit; prime++)
    if(*(array+prime) == 0) { //checking for primes
      //printf("%d,",i);
      for(composite = 2 * prime; composite < limit; composite += prime) {
        *(array+composite) = 1; //making composite
      }
    }
  int p = 2;
  int size = 1;
  for(p; size - 1 != targetPrime; p++)
    if(*(array+p) == 0) { //checking for primes
      //printf("%d: %d, ", size,p);
      size++;
    }
  return p - 1;
}



int main() {
  int target = 1000000;
  int ans = 0;
  clock_t begin;
  clock_t end;
  double time_spent;
  
  begin= clock();
  ans = sieveOG(target);
  end = clock();
    
  printf("OG: The %dth prime is %d\n", target, ans);
  time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  printf("time spent: %lfs\n\n",time_spent);

  begin= clock();
  ans = sieveOdd(target);
  end = clock();
    
  printf("Odd: The %dth prime is %d\n", target, ans);
  time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  printf("time spent: %lfs\n\n",time_spent);

  begin= clock();
  ans = sieveBitWise(target);
  end = clock();
    
  printf("BitWise: The %dth prime is %d\n", target, ans);
  time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  printf("time spent: %lfs\n\n",time_spent);

  begin= clock();
  ans = sieveNoModDivideBitWise(target);
  end = clock();
    
  printf("Big L: The %dth prime is %d\n", target, ans);
  time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  printf("time spent: %lfs\n\n",time_spent);
  printf("nosegmented... :|\n");
  return 0;
}
