#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
    int ret = 0,ret1;

    ret = fork();

    if(ret == 0)
    {
        ret1 = daemon(1,1);
        
        if(ret1 == 0)
        {
            printf("Daemon process\n");
        }

    }
    else
    {
        printf("In parent process\n");
    }
    return 0;
}