#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<sys/wait.h>

void signalhandler(int signo)
{
    if (signo == SIGINT)
    printf("received SIGINT\n");

  printf("Received signal is %d\n",signo);
}

int main()
{
    int ret = 0;
    int cpid = 0;
    int exitstatus = 0;

    ret = fork();

    if(ret == 0)
    {
        sleep(1);
        signal(SIGINT,signalhandler);
        raise(SIGINT);
    }
    else
    {
        cpid =wait(&exitstatus);
        kill(cpid,SIGINT);
        wait(NULL); 
    }

    // while(1)
    //     sleep(1);

    return 0;
    
}