#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>


int main(int argc,char *argv[])
{
    int fd = 0;
    int ret = 0;

    char Buffer[20];

    if(argc != 3)
    {
        printf("Insufficient arguments\n");
        return -1;
    }

    fd = open(argv[1],O_RDONLY);
    

    if(fd == -1)
    {
        printf("Unable to open file\n");
        return 1;
    }

    lseek(fd,atoi(argv[2]),SEEK_SET);

    ret = read(fd,Buffer,20);
    printf("Data from file is \n");
    write(1,Buffer,ret);

    close(fd);

    return 0;
}