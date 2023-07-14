#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#define MAXSIZE 1024
int main(int argc,char * argv[])
{
    int fd = 0;
    int Ret = 0;
    char Buffer[MAXSIZE]={'\0'};
    if(argc != 3)
    {
        printf("Invalid number of arguments\n");
        return -1;
    }

    fd = open(argv[1],O_RDONLY);
    if(fd == -1)
    {
        printf("Unable to open file\n");
    }
    Ret = read(fd,Buffer,atoi(argv[2]));
    printf("%d",Ret);
    close(fd);
    return 0;
}