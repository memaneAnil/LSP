#include<dlfcn.h>
#include<stdio.h>
int GetInfo(int no1,int no2)
{
    void *ptr = NULL;
    int (*fptr)(int,int) = NULL;
    int ret = 0;
    ptr = dlopen("/home/anil/Desktop/prac/dynamic/second.so",RTLD_LAZY);

    if(ptr == NULL)
    {
        printf("Unable to load library in nest1\n");
        return -1;
    }

    fptr = dlsym(ptr,"nestAdd");
    if(fptr == NULL)
    {
        printf("Unable to locate function in nest1\n");
        return -1;
    }

    ret = fptr(no1,no2);

    return ret;
}