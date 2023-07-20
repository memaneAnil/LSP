#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>

int main(int argc,char *argv[])
{
    int fd1 = 0,fd2 = 0;
    int ret1 = 0 ,ret2 = 0;
    char Buffer1[20];
    char Buffer2[1024];
    char name[20];
    int size = 0;
    int cnt = 1;

    fd1 = open("Demo.txt",O_RDWR);

    if(fd1 == -1)
    {
        printf("Unable to open file\n");
    }

    while((ret1 = read(fd1,Buffer1,15))!= 0)
    {
        
        sscanf(Buffer1,"%s%d",name,&size);
        fd2 = creat(name,0777);
        ret2 = read(fd1,Buffer2,size);
        
        write(fd2,Buffer2,ret2);
        
        memset(name,'\0',sizeof(name));
        memset(Buffer1,'\0',sizeof(Buffer1));
        memset(Buffer2,'\0',sizeof(Buffer2));   
    }

    close(fd1);
    close(fd2);

    return 0;
}