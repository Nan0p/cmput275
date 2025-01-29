#include <stdio.h>

int main() {
//Read from stdin 
  int x;
  scanf("%d", &x);

//Looping through all numbers smaller than stdin
  int first = 1;
  for(int i = 1; i <= x; ++i){
    
    if(x % i == 0){
      
      //no space in front if first divisor
      if(first){
        printf("%d", i);
        first = 0;

      }else{
        printf(" %d", i);
        first = 0;

      }
    }
  }
  printf("\n");

  return 0; 
}
