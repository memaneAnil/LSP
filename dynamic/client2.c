#include<stdio.h>
#include<dlfcn.h>
#include"nest.h"

int main()
{
    void *ptr = NULL;
    int (*fptr)(int,int) = NULL;
    int ret = 0;
    ptr = dlopen("/home/anil/Desktop/prac/dynamic/first.so",RTLD_LAZY);

    if(ptr == NULL)
    {
        printf("Unable to load library in nest1\n");
        return -1;
    }

    fptr = dlsym(ptr,"GetInfo");
    if(fptr == NULL)
    {
        printf("Unable to locate function in nest1\n");
        return -1;
    }

    ret = fptr(20,10);

    printf("Addition is : %d",ret); 

    return 0;
}