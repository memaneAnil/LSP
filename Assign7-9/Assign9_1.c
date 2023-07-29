#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
    int ret = 0;
    int cpid = 0;
    int Exit_status = 0;
    
    ret = fork();

    if(ret == 0)
    {
        
        //printf("Child is running with PID : %d\n",getpid());
        execl("./Fname","home","anil","Desktop",NULL);
    }
    else
    {
        cpid = wait(&Exit_status);
        printf("Child process is terminated having pid %d & exit status %d \n",cpid,Exit_status);
    }

    return 0;
}