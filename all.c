#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <fcntl.h>

#define Error( Str )        FatalError( Str )
#define FatalError( Str )   fprintf( stderr, "%s\n", Str ), exit( 1 )

int cal_line(char *ptr, struct stat *buf);


int main(int argc, char *argv[]){

  char *ptr = NULL;
  struct stat *buf = NULL;
  int size;

  ptr = (char *)malloc(100 * sizeof(char));
  if(ptr == NULL)
    FatalError("ptr malloc failed");

  buf = (struct stat *)malloc(sizeof(struct stat));
  if(buf == NULL)
    FatalError("buf malloc failed");

  if(!getcwd(ptr, size))
    FatalError("getcwd error");

  cal_line(ptr, buf);

  free(ptr);
  free(buf);
  ptr = NULL;
  buf = NULL;

  return 0;
}
 
int cal_line(char *ptr, struct stat *buf){

  DIR *dp = NULL;
  struct dirent *dirp = NULL;
  char *tmp = NULL;
  int fp;

  if(lstat(ptr, buf) < 0)
    FatalError("stat error");

  if(S_ISREG(buf->st_mode)){
    if(fp = open(ptr, O_RDONLY, 0) == -1)
      FatalError("open file error");  
 
  }
}









 
