#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void usage();

int main(int argc, char *argv[]){

  int fp;
  char file_name[100];
  int *buff;
  struct stat sbuf;
  int data_size, bytes = 1;
  int i;
  int pos = 0;

  if(argc != 2){
    usage();
    return 0;
  }
 
  strcpy(file_name, argv[1]);
  fp = open(file_name, O_RDONLY);
  if(fp == 0){
    printf("open file error\n");
    exit(1);
  }

  buff = (int *)malloc(sizeof(int) * 1024);
  if(buff == NULL){
    printf("malloc error\n");
    exit(1);
  }
   
  fstat(fp, &sbuf);
  data_size = sbuf.st_size; 

  while(bytes){ 
    lseek(fp, (pos++)*1024, SEEK_SET);
    bytes = read(fp, buff, 1024);
    if(bytes == -1){
      printf("read error\n");
      close(fp);
      free(buff);
      exit(1);
    }
    for(i=0; i<1024; i++){
      printf("%d ", buff[i]);
      if((i+1)%10 == 0)
        printf("\n");
    }
  }
  printf("\n");

  close(fp);
  free(buff);
}

void usage(){
  
  printf("Usage: ./readfile <filename>\n");
  exit(1);
}
