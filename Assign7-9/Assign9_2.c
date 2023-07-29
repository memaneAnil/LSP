#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/wait.h>
#include<string.h>

int main()
{
    int ret = 0;
    int fd1 = 0;
    int cpid = 0;
    int Exit_status = 0;
    char ch[2];
  

    fd1 = open("count.txt",O_RDWR |O_APPEND);

    if(fd1 == 0 )
    {
        printf("Unable to open file\n");
        return -1;
    }
    sprintf(ch,"%d",fd1);
    ret = fork();

    if(ret == 0)
    {
        
        execl("./Second",ch,NULL);
    }
    else
    {
        cpid = wait(&Exit_status);
        printf("Child process is terminated having pid %d & exit status %d \n",cpid,Exit_status);
        execl("./First",ch,NULL);
    }

    close(fd1);
    return 0;
}