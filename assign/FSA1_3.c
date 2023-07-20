#include<stdio.h>
#include<unistd.h>
#include<string.h>

int main(int argc,char * argv[])
{
    int result = 0;
    int mode = 0;
    if(argc != 3)
    {
        printf("Insufficient arguments\n");
        return -1;
    }
    if(strcmp(argv[2],"Read")== 0)
    {
        mode = R_OK; 
    }
    else if(strcmp(argv[2],"Write")== 0)
    {
        mode = W_OK;
        
    }
    else if(strcmp(argv[2],"Execute")== 0)
    {
        mode = X_OK;  
    }

    result = access(argv[1],mode);
    if(result == 0)
    {
        printf("Access file %s in %s mode\n",argv[1],argv[2]);
    }
    else
    {
        printf("Can't access %s in %s mode\n",argv[1],argv[2]);
    }

    return 0;
}