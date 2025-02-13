#include <stdio.h>

int main(){
  //Initializing and declaring odd positions and even positons and how many of their respective values are greater than 5
  int oddsGT = 0;
  int oddsLT = 0;
  int oddsNum = 0;
  int evensGT = 0;
  int evensLT = 0;
  int evensNum = 0;
  
  int len = 0;
  int checkDigit;
  int sum;
  
  //Looping through all of stdin
  int ch = getchar();
  for(;;ch = getchar()){
    if(ch == EOF|| ch == 10){
      break;
    }
    ++len;
    checkDigit = ch - '0';
    
    //oddCheck add values to respective counters depending on if it is bigger than 5
    if(len%2){
      if(checkDigit >= 5){
        ++oddsNum;
        oddsGT = oddsGT + checkDigit;
      }else{
        oddsLT = oddsLT + checkDigit;
      }

    //evenCheck same as oddCheck
    }else{
      if(checkDigit >= 5){
        ++evensNum;
        evensGT = evensGT + checkDigit;
      }else{
        evensLT = evensLT + checkDigit;
      }

    }
  }

  //Depending on if the last value was even or odd the opposite will be the every second digit affected
  //Sum everything up
  if(len%2){
    sum = 2*evensGT - 9*evensNum + 2*evensLT + oddsGT + oddsLT;
  }else{
    sum = 2*oddsGT - 9*oddsNum + 2*oddsLT + evensGT + evensLT;
  }

  //Check if Valid or Invalid
  if(((sum - checkDigit)*9)%10 == checkDigit){
    printf("Valid\n");
  }else{
    printf("Invalid\n");
  }
}
