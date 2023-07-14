#include<stdio.h>
#include<fcntl.h>
#include<dirent.h>

int main(int argc,char * argv[])
{
    DIR *dp = NULL;
    struct dirent * entry = NULL;

    if(argc != 2)
    {
        printf("Insufficient arguments \n");
        return -1;
    }

    dp = opendir(argv[1]);

    if(dp == NULL)
    {
        printf("Unable to open directory\n");
        return -1; 
    }

    printf("Entries from directory files are : \n");

    while((entry = readdir(dp)) != NULL)
    {
        printf("%s,%d\n",entry->d_name,entry->d_type);
    }

    closedir(dp);
    return 0;
}