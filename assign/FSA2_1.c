#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

#define MAXSIZE 1024
int main(int argc,char * argv[])
{
    int fd = 0;
    int ret = 0;
    char Buffer[MAXSIZE]= {'\0'};
    if(argc != 2)
    {
        printf("Insufficient arguments\n");
        return 0;
    }
    fd = open(argv[1],O_RDONLY);

    if(fd == -1)
    {
        printf("Unable to open file \n");
        return -1;
    }

    ret = read(fd,Buffer,MAXSIZE);

    if(ret == 0)
    {
        printf("Unable to read data from file\n");
        return -1;
    }

    printf("File size = %d bytes\nData from file is :\n%s\n",ret,Buffer);

    close(fd);
    return 0;
}