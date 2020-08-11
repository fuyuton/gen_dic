#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *strings = " 0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!@#$%^&*()-_=+|`~[]{};:'\",<.>/?";
int len, limit, length;
int *array;
int init_value = 0;

int *inc(int n){
  int *a;
  if(n > limit)
    return NULL;
  if(array[n] == init_value)
  {
    array[n] = 1;
    return array;
  }else{
    array[n] += 1;
  }

  if(array[n] >= length)
  {
    array[n] = 1;
    a = inc(n+1);
    if(a == NULL)
      return NULL;
  }
  return array;
}
void main(int argc, char *argv[]){
  if( argc < 2 ){
    printf("gen_dic <start_len> <end_len>\n");
    return;
  }
  int *result;

  len = atoi(argv[1]);
  limit = atoi(argv[2])-1;
  printf("start:%d, limit:%d\n", len, limit);
  length = (int)strlen(strings);
  printf("strlen: %d\n", length);

  // init
  printf("initialize...\n");
  array = (int *)malloc(limit);
  printf("array malloc!\n");
  for(int i=0; i<limit; i++)
    array[i] = init_value;

  //array[0] = init_value;
  printf("initialize complete!\n");

  //main
  while(1){
    result = inc(0);
    if(result == NULL)
      return;

    // print array.reverse_each
    for(int i=limit; i>=0; i--){
      if(array[i] != init_value)
        printf("%c", strings[array[i]]);
    }
    printf("\n");
  }
}

