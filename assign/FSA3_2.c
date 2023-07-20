#include<stdio.h>
#include<fcntl.h>
#include<dirent.h>
#include<string.h>


int main(int argc,char *argv[])
{
    DIR *dp = NULL;
    struct dirent * entry = NULL;
    

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
        if(strcmp(argv[2],entry->d_name) == 0)
        {
            printf("File is present in directory\n");
            break;
        }
    }

    if(entry == NULL)
    {
        printf("File is not present in directory\n");
    }

    closedir(dp);

    return 0;
}
