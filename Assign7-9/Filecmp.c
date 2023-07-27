#include<string.h>
#include<sys/stat.h>
#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>

int compareFile(char *str1,char *str2)
{
    struct stat sobj1,sobj2;
    int fd1 = 0,fd2 = 0;
    int ret = 0;
    char Buffer1[1024],Buffer2[1024];

    // printf("%s%s",str1,str2);

    fd1 = open(str1,O_RDONLY);
    fd2 = open(str2,O_RDONLY);

    if(fd1 == 0 || fd2 == 0)
    {
        printf("Unable to open file\n");
        return -1;
    }

    fstat(fd1,&sobj1);
    fstat(fd2,&sobj2);

    if(sobj1.st_size != sobj2.st_size)
    {
        return -1;
    }
    else
    {
        while(ret = read(fd1,Buffer1,sizeof(Buffer1))!= 0)
        {
            ret = read(fd2,Buffer2,sizeof(Buffer2));
            if(memcmp(Buffer1,Buffer2,ret)!= 0)
            {
                break;
            }

        }
        close(fd1);
        close(fd2);

        if(ret == 0)
        {
            return 0;
        }
        else
        {
            return -1;
        }
    }


}