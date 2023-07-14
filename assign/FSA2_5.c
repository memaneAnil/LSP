#include<stdio.h>
#include<fcntl.h>
//#include<unistd.h>
//#include<stdlib.h>
#include<sys/stat.h>
#include<dirent.h>
#include<string.h>

int main(int argc,char * argv[])
{
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    struct stat sobj;
    int Max = 0;

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

    while((entry = readdir(dp))!=NULL)
    {
        if(strcmp(entry->d_name ,".") != 0 && strcmp(entry->d_name ,"..") != 0) 
        {
        
            stat(entry->d_name,&sobj);
            
            if(Max<sobj.st_size)
            {
                Max = sobj.st_size;
            }
            //printf(" %s, %ld\n",entry->d_name,sobj.st_size);
        }
    }
    printf("Max file size is %d\n",Max);
    return 0;
}