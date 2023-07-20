#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<dirent.h>

int main(int argc,char * argv[])
{
    DIR *dp = NULL;
    struct dirent * entry = NULL;
    int fd1 = 0,fd2 = 0;
    int ret = 0;
    char Buffer[1024];

    if(argc != 2)
    {
        printf("Insufficient arguments\n");
        return -1;
    }

    dp = opendir(argv[1]);
    fd1 = creat("AllCombine.txt",0777);

    if(fd1 == -1)
    {
        printf("Unable to create file");
    }

    if(dp == NULL)
    {
        printf("Unable to open directory\n");
        return -1;
    }

    while((entry = readdir(dp)) != NULL)
    {
        fd2 = open(entry->d_name,O_RDONLY);
        ret = read(fd2,Buffer,sizeof(Buffer));
        write(fd1,Buffer,ret);
    }
    close(fd1);
    close(fd2);
    closedir(dp);
    return 0;
}