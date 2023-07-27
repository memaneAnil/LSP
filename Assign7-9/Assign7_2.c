#include<stdio.h>
#include<dlfcn.h>

int main(int argc,char *argv[])
{
    void * ptr = NULL;
    int (*fptr)(char *,char *);
    int ret = 0;

    // printf("%s\t%s",argv[1],argv[2]);
    if(argc != 3)
    {
        printf("Insufficient arguments\n");
        return -1;
    }
    ptr = dlopen("/home/anil/Desktop/Assign7_9/libFcmp.so", RTLD_LAZY);

    if(ptr == NULL)
    {
        printf("Unable to load library\n");
        return -1;
    }

    fptr = dlsym(ptr,"compareFile");

    if(fptr == NULL)
    {
        printf("Unable to locate function\n");
        return -1;
    }
    
    ret = fptr(argv[1],argv[2]);

    if(ret == 0)
    {
        printf("Both the file are identicle\n");
    }
    else
    {
        printf("Files are different \n");
    }

    return 0;
}