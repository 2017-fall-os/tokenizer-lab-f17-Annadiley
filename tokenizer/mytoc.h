#ifndef mytoc_included
#define mytoc_included

// variables that will store the number of characters and spaces in a string
extern int numChar , numWords;

//Method get the lenght of the string
void countWords (char *str, char delim);

//Auxiliar method to concatinate strings
void strcaat(char*dest, char src);

//Main tokenizer method
char ** mytoc(char *str, char delim);
#endif