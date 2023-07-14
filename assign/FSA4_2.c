#include<stdio.h>
#include<fcntl.h>
#include<dirent.h>

int main(int argc,char * argv[])
{
    

    if(argc != 2)
    {
        printf("Insufficient arguments\n");
        return -1;
    }

    mkdir(argv[1]);
    
    
    return 0;
}