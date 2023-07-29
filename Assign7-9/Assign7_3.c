#include<stdio.h>
#include<dlfcn.h>

#include"perfect.h"
#include"prime.h"

int main(int argc,char *argv[])
{
    void * ptr = NULL;
    int (*fptr)(int) = NULL;
    int no = 0,ret = 0;

    printf("Enter the number\n");
    scanf("%d",&no);

    ptr = dlopen("/TestPrime.so",RTLD_LAZY);

    if(ptr == NULL)
    {
        printf("Unable to load library\n");
        return -1;
    }

    fptr = dlsym(ptr,"checkPrime");

    if(fptr == NULL)
    {
        printf("Unable to locate function\n");
        return -1;
    }

    ret = fptr(no);

    if(ret)
    {
        printf("%d is Prime number\n",no);
    }
    else
    {
        printf("%d is not a Prime number\n",no);
    }

    ptr = dlopen("/home/anil/Desktop/Assign7_9/TestPerfect.so",RTLD_LAZY);

    if(ptr == NULL)
    {
        printf("Unable to load library\n");
        return -1;
    }

    fptr = dlsym(ptr,"checkPerfect");

    if(fptr == NULL)
    {
        printf("Unable to locate function\n");
        return -1;
    }

    ret = fptr(no);

    if(ret)
    {
        printf("%d is Perfect number\n",no);
    }
    else
    {
        printf("%d is not a Perfect number\n",no);
    }


    return 0;
}