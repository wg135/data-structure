#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>

int list_dir(char *ptr, struct stat *buf);

int main(int argc, char *argv[]){

  struct stat *buf = NULL;
  char *ptr = NULL;
  int size;

  ptr = (char *)malloc(100 * sizeof(char));
  if(ptr == NULL){
    printf("ptr malloc failed\n");
    exit(1);
  }
  
  buf = (struct stat *)malloc(sizeof(struct stat));
  if(buf == NULL){
    printf("buf malloc failed\n");
    exit(1);
  }
  if(!getcwd(ptr, size)){
    printf("getcwd failed\n");
    exit(1);
  }

 
  list_dir(ptr, buf);
   
  free(ptr);
  free(buf);
  ptr = NULL;
  buf = NULL;
  return 0;
}

int list_dir(char *ptr, struct stat *buf){
 
  DIR *dp = NULL;
  struct dirent *dirp = NULL;
  char *tmp;


  if(lstat(ptr, buf)<0){
    printf("stat error\n");
    exit(1);
  }

  if(S_ISDIR(buf->st_mode) ==0){
    printf("%s\n", ptr);
    return 1;
  }
  else{
    printf("d--%s\n", ptr);
    
    if((dp = opendir(ptr)) == NULL){
      printf("can not open %s\n", ptr);
      exit(1);
    }
    
   tmp = ptr+ strlen(ptr);
  // strcat(tmp, "/");
    while((dirp = readdir(dp)) != NULL){
     
      if((strcmp(dirp->d_name, ".")==0)||(strcmp(dirp->d_name, "..")==0))
        continue;
     strcat(tmp, "/"); 
      strcpy(tmp+1, dirp->d_name);
     
    // printf("%s\n", ptr);  
     list_dir(ptr, buf); 
     *tmp = 0;   
  
    }

  }
  closedir(dp);
  return 1;
}












