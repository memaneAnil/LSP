#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<string.h>

int main(int argc,char *argv[])
{
    int fd1 = 0 ,fd2 = 0;
    struct stat sobj1,sobj2;
    char Buffer1[1024],Buffer2[1024];
    int ret = 0;
    if(argc != 3)
    {
        printf("Insufficient arguments\n");
        return -1;
    }

    fd1 = open(argv[1],O_RDONLY);
    fd2 = open(argv[2],O_RDONLY);

    if(fd1 == -1 || fd2 == -1)
    {
        printf("Unable to open file\n");
        return =1;
    }

    fstat(fd1,&sobj1);
    fstat(fd2,&sobj2);

    if(sobj1.st_size != sobj2.st_size)
    {
        printf("Files are different\n");
        return -1;
    }

    while((ret = read(fd1,Buffer1,sizeof(Buffer1)))!= 0)
    {
        ret = read(fd2,Buffer2,sizeof(Buffer2));

       if(memcmp(Buffer1,Buffer2,ret)!= 0)
       {
            break;
       }
    }
    if(ret == 0)
    {
        printf("Both the files are identicle\n");
    }
    else
    {
        printf("Files are different\n");
    }

    close(fd1);
    close(fd2);
    return 0;
}