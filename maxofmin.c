#include <stdio.h>
#include <stdlib.h>
#define MAXDIM 100000
#define MINDIM 3
#define MAXVAL 1000000
#define MINVAL 1

int minimum(int s, int *v, int n, int dim){
  int i, min = v[s], p;
  for(i=s, p=0; p<n && i<dim; i++, p++)
    if(v[i]<min)
      min = v[i];

  if(p==n)
    return min;
  else
    return 0;
}

int main(){
  int n, *v, k, i, j, tmp, t, min, max, s;
  printf("Insert array dimension:\n");
  scanf("%d", &n);
  while(n<MINDIM || n>MAXDIM){
    printf("Not acceptable value, insert it again:\n");
    scanf("%d", &n);
  }

  v = malloc(sizeof(int)*n);
  if(v!=NULL){
    printf("Start inserting array values:\n");
    for(i=0, k=n; k>0; i++, k--){
      scanf("%d", &tmp);
      while(tmp<MINVAL || tmp>MAXVAL){
        printf("Not acceptable value, insert it again:\n");
        scanf("%d", &tmp);
      }
      v[i] = tmp;
    }
  } else
    printf("Dinamic allocation error\n");

  /*printf("\nI'm printing all the possible subsequences in order to make it clear:\n");
  for(i=0; i<n; i++){
    for(j=i; j<n; j++){
      for(s=0, k=i; k<=j; k++)
        printf("%d", v[k]);
      printf("\n");
    }
    printf("\n");
  }*/

  printf("Output:\n");
  for(i=0, t=1; i<n; i++, t++){
    s = 0;
    max = minimum(s, v, t, n);
    s++;
    while(s<n){
      min = minimum(s, v, t, n);
      if(min>max)
        max = min;
      s++;
    }
    printf("%d\n", max);
  }






  return 0;
}
