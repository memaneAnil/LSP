#include<stdio.h>
#include <sys/ipc.h>
#include <sys/stat.h>
#include<unistd.h>
#include<fcntl.h>

#define SIZE 512
int main()
{
    int fd = 0;
    char ch[2];
    char Buffer[SIZE];
    int ret = 0;
    
    fd = mkfifo("namepipe",0666);

    if(fd != 0)
    {
        printf("Unable to create pipe\n");
        return -1;
    }

    fd = open("namepipe",O_RDWR);
    
    ret = fork();

    if(ret == 0)
    {
        
        sprintf(ch,"%d",fd);
        printf("namepipe = %d\n",fd);
        execl("./npipedemo",ch,NULL);
    }
    else
    {
        wait(NULL);
        
        read(fd,Buffer,sizeof(Buffer));
    }

    close(fd);

    return 0;
}