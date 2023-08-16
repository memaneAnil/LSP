#include<stdio.h>
#include<unistd.h>

#define SIZE 50
int main()
{
    int fd[2];
    int ret = 0;
    char Buffer[SIZE];
    
    ret = pipe(fd);

    if(ret == -1)
    {
        printf("Unable to create pipe\n");
        return -1;
    }

    ret = fork();

    if(ret == 0)
    {
        close(fd[0]);
        write(fd[1],"Hello world...",14);
    }
    else
    {
        close(fd[1]);
        read(fd[0],Buffer,14);
        printf("Data is : %s\n",Buffer);
    }

}