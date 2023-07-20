#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc,char *argv[])
{
    char arr1[]="abcdefghijklmnopqrstuvwxyz";
    
    int fd = 0;

    if(argc != 2)
    {
        printf("Insufficient arguments\n");
        return -1;
    }
    fd = creat(argv[1],0777);

    if(fd == -1)
    {
        printf("Unable to create file\n");
        return -1;
    }

    write(fd,arr1,sizeof(arr1));

    lseek(fd,1024,SEEK_END);

    write(fd,arr1,sizeof(arr1));

    close(fd);
    
    return 0;
}