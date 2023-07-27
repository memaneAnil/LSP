
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
    int ret = 0;

    ret = fork();

    if(ret == 0)
    {
        ret = fork();
        if(ret == 0)
        {
            

            ret = fork();
            if(ret == 0)
            {
                printf("Inside process 4\n");
                printf("Process4 PID : %d\n",getpid());
                printf("Parent PID : %d\n",getppid()); 
            }
            else
            {
                wait(ret);
            printf("Inside process 3\n");
            printf("Process3 PID : %d\n",getpid());
            printf("Parent PID : %d\n",getppid());
            }

        }
        else
        {
            wait(ret);
            printf("Inside process 2\n");
            printf("Process2 PID : %d\n",getpid());
            printf("Parent PID : %d\n",getppid());
        }
        
    }
    else
    {
        wait(ret);
        printf("Inside process 1\n");
        printf("Parent PID : %d\n",getpid());
    }
    return 0;
}