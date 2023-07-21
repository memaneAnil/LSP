#include<stdio.h>
#include"number.h"
#include<dlfcn.h>
int main(int argc,char *argv[])
{
    int no1 = 0,no2 = 0;
    int ret = 0;
    void * ptr = NULL;
    int (*fptr)(int,int) = NULL;


    ptr = dlopen("/home/anil/Desktop/prac/dynamic/number.so",RTLD_LAZY);

    if(ptr == NULL)
    {
        printf("Unable to load library\n");
        return -1;
    }

    fptr = dlsym(ptr,"addition");

    if(fptr == NULL)
    {
        printf("Unable to connect\n");
        return -1;
    }
    
    ret = fptr(10,12);

    printf("Addition is : %d\n",ret);

    fptr = dlsym(ptr,"subtraction");

    if(fptr == NULL)
    {
        printf("Unable to connect\n");
        return -1;
    }
    
    ret = fptr(10,12);

    printf("Subtraction is : %d\n",ret);

    return 0;
}