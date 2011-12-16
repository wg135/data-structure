#include <assert.h>  
#include <fcntl.h>  
#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include <unistd.h>  
  
#include <sys/time.h>  
#include <sys/types.h>  
#include <sys/stat.h>  
  
int main(int argc, char **argv)  
{  
    char *filename = argv[1];  
    int *buffer = (int *)malloc(1<<20);  
    struct stat     sbuf;  
    int rv, data_size, i, bytes, fd;  
  
    fd = open(filename, O_RDONLY);  
    if (fd < 0) {  
        printf("%s not found!\n", filename);  
        exit(0);  
    }  
    rv = fstat(fd, &sbuf);  
    data_size = sbuf.st_size;  
  
    bytes = read(fd, buffer, data_size);  
    for (i = 0; i < bytes/4; i++) {  
        printf("%d ", buffer[i]);  
        if ((i+1) % 10 == 0) {  
            printf("\n");  
        }  
    }  
    printf("\n");  
    close(fd);  
    free(buffer);  
    return 0;  
}
