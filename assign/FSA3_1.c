#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#define MAXSIZE 1024
#include<string.h>
int main(int argc,char *argv[])
{
    int fd[3];
    int cnt = 0;
    char Buffer[MAXSIZE] = {'\0'};
    int ret = 0;
    if(argc != 3)
    {
        printf("Insufficient arguments\n");
        return -1;
    }
    fd[0] = open(argv[1],O_RDONLY);
    fd[1] = open(argv[2],O_RDONLY);

    fd[2] = creat("Combine.txt",0777);
    //printf("%d\n",fd[2]);
    // fd[2] = open("Combine.txt",O_RDWR |O_APPEND);
    // printf("%d\n",fd[2]);

    while(cnt < 2)
    {
        if((ret = read (fd[cnt],Buffer,MAXSIZE))!=0)
        {
            //printf("%s",Buffer);
            write(fd[2],Buffer,ret);
        }
        cnt++;
    }
    close(fd[0]);
    close(fd[1]);
    close(fd[2]);

    return 0;
}