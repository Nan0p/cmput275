#include <stdio.h>

//Checking and converting the Roman Numerals to decimal equivilents
int checkNum(int ch){
  if(ch == 'I') {
    return 1;
  }
  if(ch == 'V'){
    return 5;
  }
  if(ch == 'X'){
    return 10;
  }
  if(ch == 'L'){
    return 50;
  }
  if(ch == 'C'){
    return 100;
  }
  if(ch == 'D'){
    return 500;
  }
  return 0;
}

int main(){
  //Getting the first two chars and converting the first one to decimal
  int sum = 0;
  int currentChar = getchar();
  int currentNum = checkNum(currentChar);
  int readChar = getchar();
  int nextNum;
  
  //Looping through whats left
  for(;;readChar = getchar()){
    //if the later char is EOF end the loop
    if(readChar == EOF){
      sum = sum + currentNum;
      break;
    }
    //Check if the later char is a greater value or not and adjusting behaviour accordingly
    nextNum = checkNum(readChar);
    if(currentNum < nextNum){
      sum = sum - currentNum;
    }else{
      sum = sum + currentNum;  
    }
    //shift chars over so only the later char has to be updated
    currentChar = readChar;
    currentNum = nextNum;
  }
  printf("%d\n", sum);
}
