#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/wait.h>
#include<string.h>

int main()
{
    int ret = 0;
    int fd = 0,fd1 = 0;
    ret = fork();
    char Buffer[10],data[10],data1[10];
    int cnt = 0;

    fd1 = open("count.txt",O_RDWR |O_APPEND);

    if(fd1 == 0 )
    {
        printf("Unable to create file\n");
        return -1;
    }

    if(ret == 0)
    {
        fd = open("second.txt",O_RDONLY);

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
        
        sprintf(data,"%d\n",cnt);
        write(fd1,data,strlen(data));
        
        printf("Child is running with PID : %d\n",getpid());
        //execl("./Fname","home","anil","Desktop",NULL);
    }
    else
    {
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
        wait(ret);
        
        write(fd1,data1,strlen(data1));
       
        close(fd1);
        fd1 = open("count.txt",O_RDWR |O_APPEND);
        read(fd1,Buffer,sizeof(Buffer));
        printf("%s\n",Buffer);
        
        //printf("Parent is running with PID : %d\n",getpid());  
    }
    

    return 0;
}