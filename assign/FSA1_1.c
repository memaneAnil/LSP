#include<stdio.h>
#include<fcntl.h>

int main(int argc,char * argv[])
{
    int fd = 0;

    if(argc != 2)
    {
        printf("Insufficient arguments\n");
        return -1;
    }

    fd = open(argv[1],O_RDWR);
    if(fd == -1)
    {
        printf("Unable to open file\n");
    }
    printf("%d",fd);
    close(fd);
    return 0;
}