#include<stdio.h>
#include"fileInfo.h"

int main(int argc,char * argv[])
{
    if(argc != 2)
    {
        printf("Insufficient arguments\n");
        return -1;
    }

    displayInfo(argv[1]);

    return 0;
}