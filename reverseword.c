/*reverse "hello world" to "world hello" */
#include <stdio.h>
#include <string.h>

void reverse(char *start, char *end);
void reverse_word(char *string);

int main(){

  char str[] = "Hello world";
  reverse_word(str);
  printf("%s\n", str);
  return 0;
}

void reverse(char *start, char *end){

  char tmp;
  
  while(start <end){
    tmp = *start;
    *start++ = *end;
    *end-- = tmp;
  }    
}

void reverse_word(char *string){
 
  char *tmp = string;
  char *word = string;

  if(string == NULL){
    printf("string cannot be empty\n");
    return;
  } 
  tmp = string;
  
  while(*tmp){
    tmp++;
    if(*tmp == '\0') 
      reverse(word, tmp-1);
    else if(*tmp == ' '){
      reverse(word, tmp -1);
      word = tmp+1;    
    }
  }  //reverse word by word

  reverse(string, tmp-1); //reverse all char in string including space
 
  
}
