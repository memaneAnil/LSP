#include<stdio.h>
#include<unistd.h>
#include <sys/resource.h>

int main()
{
    int ret = 0;
    int pid = 0;
    
        pid = getpid();
        printf("Priority : %d\n",getpriority(PRIO_PROCESS,pid));
   
    return 0;
}