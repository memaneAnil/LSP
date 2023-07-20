#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main(int argc,char *argv[])
{
    int ret = 0;
    if(argc != 3)
    {
        printf("Insufficient arguments\n");
        return -1;
    }

    ret =truncate(argv[1],atoi(argv[2]));

    if(ret == 0)
    {
        printf("Data successfully truncated\n");
    }

    return 0;
}