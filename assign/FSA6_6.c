#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<dirent.h>
#include<sys/stat.h>
#define MAXSIZE 1024

int main(int argc,char *argv[])
{
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    struct stat sobj;
    char fpath[50];
    int fd = 0;

    char Buffer[2048];
    int ret =0;

    if(argc != 2)
    {
        printf("Insufficient arguments\n");
        return -1;
    }

    dp = opendir(argv[1]);

    if(dp == NULL)
    {
        printf("Unable to open directory\n");
        return -1;
    }

    while((entry = readdir(dp))!= NULL)
    {
        stat(entry->d_name,&sobj);
        sprintf(fpath,"%s/%s",argv[1],entry->d_name);
        if(sobj.st_size < MAXSIZE)
        {
            
            fd = open(fpath,O_RDWR);
            lseek(fd,1024,SEEK_CUR);
            write(fd,fpath,sizeof(fpath));
            ret = read(fd,Buffer,sizeof(Buffer));
            printf("%d",ret);
        }
        else
        {
            fd = open(fpath,O_RDWR);
            truncate(fpath,MAXSIZE);
        }
        memset(fpath,'\0',sizeof(fpath));
    }

    close(fd);
    closedir(dp);

    return 0;
}