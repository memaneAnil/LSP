#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<dirent.h>
#include<string.h>
#define MAXSIZE 1024

int main(int argc,char *argv[])
{
    DIR *dp = NULL;
    struct dirent * entry = NULL;
    char fpath[30];
    int fd1 = 0,fd2 = 0;
    int ret = 0;
    char Buffer[MAXSIZE];

    if(argc != 3)
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
        if(strcmp(entry->d_name,".")!= 0 && strcmp(entry->d_name,"..")!= 0)
        {
            sprintf(fpath,"%s/%s",argv[2],entry->d_name);
            
            fd1 = open(entry->d_name,O_RDONLY);
            fd2 = creat(fpath,0777);
            ret = read(fd1,Buffer,sizeof(Buffer));
            write(fd2,Buffer,ret);
            close(fd2);
            sprintf(fpath,"%s/%s",argv[1],entry->d_name);
            remove(fpath);

        }
        
    }
    close(fd1);
    closedir(dp);
    return 0;
}