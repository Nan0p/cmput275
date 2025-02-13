#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const char * const GREEN = "\x1b[32m";
const char * const YELLOW = "\x1b[33m";
const char * const WHITE = "\x1b[0m";
const char * current = WHITE;

void setColour(const char *colour) {
  if (current == colour) return;
  printf("%s", colour);
  current = colour;
}


int main(int argc, char **argv) {
  if (argc != 2) {
    printf("Usage: %s word\n", argv[0]);
    return 1;
  }
  // theWord is not a pointer to a string that stores the command line argument word that was provided.
  char *theWord = argv[1];
  
  int wordLen = strlen(theWord);
  //Code Starts
  //looping 6 times, one time per guess
  for(int gc = 1; gc<=6; ++gc){
    char *warr = malloc(wordLen*sizeof(char));
    char *garr = malloc(wordLen*sizeof(char));
    
    setColour(WHITE);
    printf("Enter guess: ");
    int gChar = getchar();
    int comp = 1;
    //Storring the Values that dont match into malloc
    for(int i = 0; i < wordLen; ++i){
      if(gChar == *(theWord+i)){
        warr[i] = '0';
      }else{
        warr[i] = *(theWord+i);
        comp = 0;
      }
      garr[i] = gChar;
      gChar = getchar();
    }
    //Printing the guesses with all colours
    //First checking if char is in correct place
    for(int j = 0; j < wordLen; ++j){
      if(warr[j] == '0'){
        setColour(GREEN);
        printf("%c", garr[j]);

        //else checking if char is in word at all
      }else{
        int seek = 1;
        for(int k = 0; k < wordLen; ++k){
          if(garr[j] == warr[k]){
            setColour(YELLOW);
            printf("%c", garr[j]);
            warr[k] = '1';
            seek = 0;
          }
        }
        //If check fails print in white
        if(seek){
          setColour(WHITE);
          printf("%c", garr[j]);
        }
      }
    }
    //free the dynamic data
    free(warr);
    free(garr);
    warr = NULL;
    garr = NULL;
    printf("\n");
    //Checking if guess was correct 
    if(comp){
      setColour(WHITE);
      printf("Finished in %d guesses\n", gc);
      return 1;
    }
  }
  //print fail message
  setColour(WHITE);
  printf("Failed to guess the word: ");
  for(int i = 0; i < wordLen; ++i){
    printf("%c", *(theWord+i));
  }
  printf("\n");
  return 1;
}
