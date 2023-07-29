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
        ret = fork();
        if(ret == 0)
        {
            printf("Inside process 3\n");
            execl("./ProcessSys",NULL,NULL);
        }
        else
        {
            cpid = wait(&Exit_status);
            printf("Child process is terminated having pid %d & exit status %d \n",cpid,Exit_status);
            printf("Inside process 2\n");
            execl("./ProcessSys",NULL,NULL);
        }
        
    }
    else
    {
        printf("Inside process 1\n");
        printf("Parent PID : %d\n",getpid());
        cpid = wait(&Exit_status);
        printf("Child process is terminated having pid %d & exit status %d \n",cpid,Exit_status);
    }
    return 0;
}