#include<stdio.h>
#include<unistd.h>

#define SIZE 50
int main()
{
    int fd[2];
    int ret = 0;
    char Buffer[SIZE];
    char path[2];
    
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
        sprintf(path,"%d",fd[1]);
        execl("./unamepipe",path,NULL);
        
    }
    else
    {
        close(fd[1]);
        //wait(NULL);
        read(fd[0],Buffer,21);
        printf("Data is : %s\n",Buffer);
    }

}