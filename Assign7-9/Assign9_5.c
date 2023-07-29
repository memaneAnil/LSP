#include<stdio.h>
#include<unistd.h>
#include <sched.h>
#include <sys/resource.h>


int main()
{
    int ret = 0;
    int ret1;
    ret = fork();
    int pid = 0;

    if(ret == 0)
    {
        pid = getpid();
        printf("In child process\n");
        printf("cPriority : %d\n",getpriority(PRIO_PROCESS,pid));
        nice(5);
        printf("Priority : %d\n",getpriority(PRIO_PROCESS,pid));
    }
    else
    {
        pid = getpid();
        printf("Priority : %d\n",getpriority(PRIO_PROCESS,pid));
        

        ret1=sched_yield();
        
        if(ret1 == 0)
        printf("schedule success\n");
    }
    return 0;
}