#include<stdio.h>
#include<fcntl.h>
#include<string.h>
int main(int argc,char * argv[])
{
    int fd = 0;
    int mode = 0;

    if(argc != 3)
    {
        printf("Insufficient arguments\n");
        return -1;
    }

    if(strcmp(argv[2],"Read") == 0)
    {
        mode = O_RDONLY;
    }
    if(strcmp(argv[2],"Write") == 0)
    {
        mode = O_WRONLY;
    }
    
    fd = open(argv[1],mode);
    if(fd == -1)
    {
        printf("Unable to open file\n");
    }
    printf("%d",mode);
    close(fd);
    return 0;
}