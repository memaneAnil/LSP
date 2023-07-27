#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
    int ret = 0;
    int pid = 0;
    ret = fork();

    if(ret == 0)
    {
        
        //printf("Child is running with PID : %d\n",getpid());
        execl("./Fname","home","anil","Desktop",NULL);
    }
    else
    {
        wait(ret);
        //printf("Parent is running with PID : %d\n",getpid());  
    }

    return 0;
}