#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<sys/wait.h>
#include<stdlib.h>

void signalhandler(int signo)
{
    if (signo == SIGINT)
    {
        printf("\nreceived SIGINT\n");
    }
    else if (signo == SIGHUP)
    {
        printf("\nreceived SIGHUP\n");
    }
    else if(signo == SIGQUIT)
    {
        printf("\nreceived SIGQUIT\n");
    }
    
    printf("Received signal is %d\n",signo);


}

int main(int argc,char *argv[])
{
    int ret = 0;
    int choice;

    while(choice)
    {
        printf("Enter signal number\n");
        printf("1 : SIGHUP 2 : SIGINT 3 : SIGQUIT 0 : exit \n");

        scanf("%d",&choice);
        
        signal(choice,signalhandler);
        raise(choice);
        sleep(2);
        printf("\n");

    }
   
    return 0;
    
}