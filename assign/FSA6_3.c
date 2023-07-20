#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<dirent.h>
#include<sys/stat.h>
#include<string.h>

int main(int argc,char * argv[])
{
    int fd = 0;
    char path[1024]={'\0'};
    
    if(argc != 3)
    {
        printf("Insufficient arguments\n");
        return -1;
    }
    sprintf(path,"%s/%s",argv[1],argv[2]);
    fd = creat(path,0777);

    if(fd == -1)
    {
        printf("Unable to create file \n");
    }
    printf("%d",fd);   

    close(fd);
    return 0;
}