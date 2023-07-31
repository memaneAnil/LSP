#include<stdio.h>
#include<pthread.h>
#include<string.h>

void * addition(void* ptr)
{
    int ret = 0;
    int i = 0;
    int size = *(int *)ptr;

    for(i =1;i < size;i++)
    {
        ret = ret+ *(((int *)ptr)+i);
    } 
    pthread_exit(ret);
}
void * subtraction(void* ptr)
{
    int ret = 0;
    int i = 0;
    int size = *(int *)ptr;

    for(i =1;i < size;i++)
    {
        if(i != 1)
        {
            ret = ret - *(((int *)ptr)+i);
        }
        else
        {
            ret = *(((int *)ptr)+i);
        }
        
    } 
   pthread_exit(ret);
}
void * multification(void *ptr)
{
    int ret = 1;
    int i = 0;
    int size = *(int *)ptr;

    for(i =1;i < size;i++)
    {
        ret = ret * (*(((int *)ptr)+i));          
    } 
    pthread_exit(ret);
}
void * division(void * ptr)
{
    int ret = 0;
    int i = 0;
    int size = *(int *)ptr;

    for(i =1;i < size;i++)
    {
        if(i != 1)
        {
            ret = ret / *(((int *)ptr)+i);
        }
        else
        {
            ret = *(((int *)ptr)+i);
        }
    } 
    pthread_exit(ret);
}
int main()
{
    int arr[3]={3,10,5};
    void (*fname[4])={addition,subtraction,multification,division};
    char * operation[4]= {"addition","subtraction","multification","division"};
    pthread_t TID[4];
   
    int ret1[4];
    int ret = 0;
    int i = 0;
        
    for(i=0 ;i< 4;i++)
    {
        ret = pthread_create(&TID[i],NULL,fname[i],arr);
        
        if(ret != 0)
        {
            printf("Unable to create thread \n");
            return -1;
        }
        
    }

    for(i=0 ;i< 4;i++)
    {
        pthread_join(TID[i],&ret1[i]);
        printf("%s(%d,%d) is : %d\n",operation[i],arr[1],arr[2],ret1[i]);
    }
    return 0;
}