#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/wait.h>
#include<string.h>

int main(int argc,char *argv[])
{
    int ret = 0;
    int fd = 0,fd1 = 0;
    char Buffer[10],data1[10];
    int cnt = 0;
    
    fd = open("first.txt",O_RDONLY);

    if(fd == 0 )
    {
        printf("Unable to open file\n");
        return -1;
    }

    while((ret = read(fd,Buffer,1))!= 0)
    {
        if((*Buffer) >= 'A' && *Buffer<='Z')
        {
            cnt++;
            //printf("%c\n",*Buffer);
        }
        
        
    }
    sprintf(data1,"%d\n",cnt);
    fd1 = atoi(argv[0]);
    
    write(fd1,data1,strlen(data1));
    close(fd);
    return 0;
}