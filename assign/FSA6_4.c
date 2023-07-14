#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<dirent.h>
#include<sys/stat.h>
#include<string.h>

int main(int argc,char * argv[])
{
    DIR *dp = NULL;
    struct dirent * entry = NULL;
    struct stat sobj;
    int ret = 0;
    char path[1024]={'\0'};
    
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
        if(strcmp(entry->d_name,".")!= 0 && strcmp(entry->d_name,"..")!= 0)
        {
            
            stat(entry->d_name,&sobj);
            
            if(sobj.st_size > 100)
            {
                sprintf(path,"%s/%s",argv[1],entry->d_name);
                ret = remove(path);
                if(ret == -1)
                {
                    printf("ERROR : There is no such file\n");
                }
                if(ret == 0)
                {
                    printf("File is successfully removed\n");
                }
                
            }
            sobj.st_size = 0;
        }
    }

    return 0;
}