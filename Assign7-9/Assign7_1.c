#include<stdio.h>
#include<dlfcn.h>
#include<string.h>
#include"operation.h"

int main()
{
    void * ptr = NULL;
    int (*fptr)(int,int);
    int no1 = 0 ,no2 = 0;
    
    int ret = 0;

    printf("Enter first number\n");
    scanf("%d",&no1);
    printf("Enter second number\n");
    scanf("%d",&no2);

    ptr = dlopen("/home/anil/Desktop/Assign7-9/operation.so",RTLD_LAZY);

    if(ptr == NULL)
    {
        printf("Unable to load library\n");
        return -1;
    }

    fptr = dlsym(ptr,"Addition");

    ret = fptr(no1,no2);
    printf("Addition is : %d\n",ret);

    fptr = dlsym(ptr,"Subtraction");

    ret = fptr(no1,no2);
    printf("Subtraction is : %d\n",ret);

    fptr = dlsym(ptr,"Multification");

    ret = fptr(no1,no2);
    printf("Multification is : %d\n",ret);

    fptr = dlsym(ptr,"Division");

    ret = fptr(no1,no2);
    printf("Division is : %d\n",ret);

    return 0;
}