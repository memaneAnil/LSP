#include<dlfcn.h>
#include<stdio.h>


int pass(int no)
{
    void * ptr = NULL;
    int (*fptr)(int) = NULL;
    int ret = 0;

    ptr = dlopen("/home/anil/Desktop/Assign7_9/second.so",RTLD_LAZY);

    if(ptr == NULL)
    {
        printf("Unable to load library\n");
        return -1;
    }

    fptr = dlsym(ptr,"factorial");

    if(fptr == NULL)
    {
        printf("Unable to locate function\n");
        return -1;
    }
    ret = fptr(no);
    
    return ret;

}