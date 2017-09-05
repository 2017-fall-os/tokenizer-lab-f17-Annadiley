#include "mytoc.h"
#include "stdlib.h"
#include "stdio.h"
#include "strcopy.h"
int numChar , numWords,currentWordLen;
char *stri;                               
int len[100];                              //stores lenght of every word
int main (void){
  stri ="potato y y";
  // countWords(stri,' ');
  char **tokeenVect =mytoc(stri,' ');
 
  printf("%d",numWords);
  printf("\n");
  printf("%d",len[1]);
  printf("\n");
  return 0;
}

void countWords(char *str, char delim){    //get the number of words in the string
  numWords = 0;
  currentWordLen=0;
  if(*str !='\0'){
    numWords=1;               //if string is not empty, it contains a word
    while(*str != '\0'){      //as long as we are not at the end of the string
      currentWordLen++;       //if a char is found increase lenght of word
      if(*str == delim){
	len[numWords]=currentWordLen-1; //at the current word add the lenght
	                                //substract one because of the space
	numWords++;                     //increase the number of found words
	currentWordLen=0;               //set the current word lenght to 0
      }
     *str++;                   //advance the pointer to next character
    }
  }
 
}
void strcaat(char *dest, char src){    //concatenates 2 characters
  int size;
  for(size=0;dest[size]!='\0';++size); //gets the size of the dest string
  dest[size]=src;                      //on the en of string adds source char
  dest[size+1]='\0';                   //at the end adds terminating '\0'


}
char ** mytoc(char *str,char delim){
  countWords(str,delim);             //gets number of words and lenght of words
  char ** tokenVec = (char **) calloc((numWords+1), sizeof(char*));  //allocates memory for vector given the amount of words
  for(int tokNum=0;tokNum<numWords;tokNum++){      // for each word
    tokenVec[tokNum]=(char*)malloc(len[tokNum+1]); //allocate space for the word
    //char* a =(char*)malloc(len[tokNum+1]);
    char* a =(char*)str;            //creates a new char pointer to alocate the current first letter of the word
    for(int cWordLenght =0; cWordLenght < len[tokNum+1];cWordLenght++){ //for the lenght of the word
      char currents = *str;        //get current character in string
      strcaat(a,currents);         //add the new character to the previous one
    }
    tokenVec[tokNum]=a;            //add the complete word to the vector
  }
  tokenVec[numWords+1]='\0';       //add terminating symbol at the end of vector
  return tokenVec;                 //return the vector
}
