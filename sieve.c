#include <stdio.h>
#include <stdlib.h>
#include "sieve.h"
#include <math.h>


int rollSum = 0;
int currRecord = 0;


int init(int nth){
  double s = nth;
  int x = (int)(nth *  log(s) * 1.15);
  printf("%d\n", x);
  return x;
}

int sieve(int nth){
  int len = init(nth);
  char * list_of_nums = calloc(sizeof(char), len);
  for(int i = 0 ;i < len; i++){
    list_of_nums[i] = 0;
    // printf("#%d: %d\n", i, list_of_nums[i]);
  }
  for(int i = 2; i < len; i+=2){
    if(list_of_nums[i] == 0){
      list_of_nums[i] = 1;
      rollSum += 1;
      // printf("Prime %d:  %d\n", rollSum, i);
      for(int j = i*i; j <len; j+=2){
        if(list_of_nums[j] == 0){
          if(j % i == 0){
            list_of_nums[j] = 2;
          }
        }
      }
    }
  }
}
