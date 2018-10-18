#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
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
//0->2
//1->3,2->5
int iTn(int i) {
  return 2 * i + 1;
}
//5->2,3->1
//if n is even return ??
int nTi(int n) {
  return (n - 1)/2;
}
void sieve(int c) {
  int nlimit = 1.5 * c * log(c);
  int bsize = nlimit / 2;
  bool brot[bsize];
  int s = 0;
  for(s; s < bsize; s++) {
    brot[s] = 1;
  }
  int exit = sqrt((double)(nlimit)) + 1;
  int i;
  int nj;
  int iexit = nTi(exit+1);
  for(i = 1; i < iexit + 2; i++)
    if(brot[i] == 1) {
      int ni = iTn(i);
      printf("i%d,ni%d,  ", i,ni);
      for(nj = 2 * ni; nj < 2 * exit; nj += ni) {
        int j;
        if(nj % 2 == 0)
          j = 0;
        else {
          if(i == 1)
            printf("s%d",nj);
          j = nTi(nj);
          brot[j] = 0;
        }
      }
    }
  int p = 1;
  int size = 2;
  printf("\n\n");
   for(p; size - 1 != c; p++)
     if(brot[p]) {
      printf("%d: %d, ", size,iTn(p));
      if(size%10 == 0)
        printf("\n");
      size++;
    }
  printf("\n%d: %d,",size - 1, iTn(p - 1));
}

void sieveo(int c) {
  int bro = 1.5 * c * log(c);
  bool brot[bro];
  int s = 0;
  for(s; s < bro; s++) {
    brot[s] = 1;
  }
  int exit = sqrt((double)bro) + 1;
  int i = 2;
  int nj;
  for(i; i < exit; i++)
    if(brot[i] == 1) {
      printf("%d,",i);
      for(nj = 2 * i; nj < bro; nj += i) { 
        brot[nj] = 0;
      }
    }
  int p = 2;
  int size = 1;
  printf("\n\n");
  for(p; size - 1 != c; p++)
    if(brot[p]) {
      printf("%d: %d, ", size,p);
      if(size%10 == 0)
        printf("\n");
      size++;
    }
  printf("\n%d: %d,",size - 1, p - 1);
}


int main(int argc, char * argv[]) {
  clock_t begin = clock();
  /* here, do your time-consuming job */
  sieveo(100);
  clock_t end = clock();
  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  printf("\ntime spent:\n%lfs\n\n",time_spent);
  clock_t begi = clock();
  /* here, do your time-consuming job */
  sieve(100);
  clock_t en = clock();
  double time_spen = (double)(en - begi) / CLOCKS_PER_SEC;
  printf("\ntime spent:\n%lfs\n",time_spen);

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
