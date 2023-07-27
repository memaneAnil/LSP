#include<stdio.h>
#include<dlfcn.h>

int main()
{
    void *ptr = NULL;
    int (*fptr)(int) = NULL;
    int ret = 0 ,no = 0;

    printf("Enter the number \n");
    scanf("%d",&no);

    ptr = dlopen("/home/anil/Desktop/Assign7_9/first.so",RTLD_LAZY);

    if(ptr == NULL)
    {
        printf("Unable to load library\n");
        return -1;
    }

    fptr = dlsym(ptr,"pass");

    if(fptr == NULL)
    {
        printf("Unable to locate function\n");
        return -1;
    }

    ret = fptr(no);

    printf("Factorial of %d is : %d\n",no,ret);
    
    return 0;
}