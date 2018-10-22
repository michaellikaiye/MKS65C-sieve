#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
#include "sieve.h"

#include <locale.h> //easy to read numbers

int main(int argc, char * argv[]){
  int iterations = 1;
  int target = 1000000;
  if(argc > 1){
    target = atoi(argv[1]);
  }
  if(argc > 2){
    iterations = atoi(argv[2]);
  }

  int ans = 0;
  double times[iterations];
  clock_t begin;
  clock_t end;
  int i = 0;
  setlocale(LC_NUMERIC, ""); //easy to read
  while(i < iterations) {
    begin = clock();
    ans = sieve(target);
    end = clock();
    
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    times[i] = time_spent;
    printf("The n=%'d prime is %'d \n", target, ans);
    //printf("time spent: %lfs\n\n",time_spent);
    //this is to modify which prime to
    //potentially avoid CPU caching
    target++;
    i++;
  }
  
  
  ans = sieve(target);
    
  double sum;
  double ave;
  sum = ave = 0;
  i = 0;
  while(i < iterations) {
    sum = sum + times[i];
    i++;
  } 
  ave = (double)sum / iterations;
  printf("average time: %lfs\n\n",ave);
  
  return 0;
}
