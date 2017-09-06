#include "mytoc.h"
#include "stdlib.h"
#include "stdio.h"
#include "strcopy.h"
int numChar , numWords,currentWordLen;
char *stri, *stricopy;                               
int len[100];                              //stores lenght of every word
int main (void){
  stri ="potato y yoo";
  // countWords(stri,' ');
  char **tokeenVect =mytoc(stri,' ');
 
  // printf("%d",numWords);
  // printf("\n");
  // printf("%d",len[1]);
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
    len[numWords]=currentWordLen;       //add lenght to final word
  }
 
}

char *strcopy(char *inStr, int current)	/* like strdup */
{
  char *pStr, *copy, *pCopy;
  size_t len;
    for (pStr = inStr; *pStr; pStr++)    // count # chars in str
      ;
    len = pStr - inStr + 1;
 
  
    // copy = pCopy = (char *)malloc(len); // allocate memory to hold  copy 
  if(current!=0){
    for(int i=0;i<current;i++){
      copy = pCopy = (char *)malloc(current); // allocate memory to hold  copy 
  
      for (pStr = inStr; *pStr; pStr++)   // duplicate 
	*(pCopy++) = *pStr;
    }
  }
  else{
    copy = pCopy = (char *)malloc(len); // allocate memory to hold  copy 
       for (pStr = inStr; *pStr; pStr++)   // duplicate 
	*(pCopy++) = *pStr;
  }
  *pCopy = 0;		      	      // terminate copy 
  return copy;
}


char ** mytoc(char *str,char delim){
 
  stricopy =strcopy(str,0);

  countWords(stricopy,delim);                      //gets number of words and lenght of words

  char ** tokenVec = (char **) calloc((numWords+1), sizeof(char*));               //allocates memory for vector given the amount of words

  for(int tokNum=1;tokNum <= numWords;tokNum++){      // for each word
    tokenVec[tokNum-1]=(char*)malloc(len[tokNum+1]); //allocate space for the word
    char* a =(char*)malloc(len[tokNum+1]+1);
    a =strcopy(str,len[tokNum]);
    a[len[tokNum]]='\0';
    for(int i=1; i<=len[tokNum]+1;i++){
      str++;
    }
    // printf("\n");
    // printf("%s", a);

    tokenVec[tokNum-1]=a;                            //add the complete word to the vector
  }
  tokenVec[numWords+1]='\0';                    //add terminating symbol at the end of vector
  // printf("%s",tokenVec[3]);
  return tokenVec;                                 //return the vector
}
