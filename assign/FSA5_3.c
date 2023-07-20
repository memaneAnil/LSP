#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<dirent.h>
#include<string.h>

#pragma pack(1)
struct FileInfo
{
    char FileName[20];
    int FileSize;
};

int main(int argc,char * argv[])
{
    DIR *dp = NULL;
    struct dirent * entry = NULL;
    struct stat sobj;
    struct FileInfo fobj;
    int fd = 0;
    char fpath[30];

    if(argc != 2)
    {
        printf("Insufficient arguments\n");
        return -1;
    }
    dp = opendir(argv[1]);
    fd = creat("combine",0777);
    if(fd == -1)
    {
        printf("Unable to create file\n");
        return -1;
    }

    if(dp == NULL)
    {
        printf("Unable to open directory\n");
        return -1;
    }
    while((entry = readdir(dp))!= NULL)
    {
        stat(entry->d_name,&sobj);
        if(S_ISREG(sobj.st_mode))
        {
            
            strcpy(fobj.FileName,entry->d_name);
            fobj.FileSize = sobj.st_size;
            write(fd,&fobj,sizeof(fobj));
            printf("File name = %s\nFile size =%ld\n",entry->d_name,sobj.st_size);
        }
        
    }

    close(fd);
    closedir(dp);
    return 0;
}