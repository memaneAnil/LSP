#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
    int ret = 0;

    ret = fork();

    if(ret == 0)
    {
        printf("In child process\n");
    }
    else
    {
        wait(ret);
        printf("In parent process\n");
    }
    return 0;
}