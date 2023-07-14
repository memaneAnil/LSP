#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<dirent.h>
#include<string.h>
#include<sys/stat.h>

int main(int argc,char *argv[])
{
    DIR *dp = NULL;
    struct dirent * entry = NULL;
    struct stat sobj;
    char Buffer[10] = {'\0'};
    int ret = 0;
    int fd = 0 , fd1 = 0;
    char path[1024]={'\0'};

    if(argc != 2)
    {
        printf("Insufficient arguments\n");
        return -1;
    }

    dp = opendir(argv[1]);
    fd = creat("Demo.txt",0777);

    if(dp == NULL)
    {
        printf("Unable to open directory\n");
        return -1;
    }

    while((entry = readdir(dp))!= NULL)
    {
        stat(entry->d_name,&sobj);

        //sprintf("%s/%s\n",entry->d_name,entry->d_type);
        if(entry->d_type == 8)
        {
            sprintf(path,"%s/%s",argv[1],entry->d_name);
            //printf("%s\n",path);
            fd1 = open(path,O_RDONLY);
            
            ret = read(fd1,Buffer,10);
            //printf("%s",Buffer);
            write(fd,Buffer,ret);
        }
    }

    close(fd);
    close(fd1);

    return 0;
}