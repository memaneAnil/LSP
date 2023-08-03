#include<stdio.h>
#include<pthread.h>

void * ThreadProc1(void * ptr)
{
    printf("Inside Thread1\n");
    pthread_exit(NULL);  
}
void * ThreadProc2(void * ptr)
{
    printf("Inside Thread2\n");
    pthread_exit(NULL);
}
void * ThreadProc3(void * ptr)
{
    printf("Inside Thread3\n");
    pthread_exit(NULL);  
}
void * ThreadProc4(void * ptr)
{
    printf("Inside Thread4\n");
    pthread_exit(NULL);  
}
int main()
{
    pthread_t TID[4];
    int ret = 0;
    void* (*fptr[4])(void*) = {ThreadProc1,ThreadProc2,ThreadProc3,ThreadProc4};
    int i = 0;

    for(i=0; i< 4;i++)
    {
        ret = pthread_create(&TID[i],NULL,fptr[i],NULL);

        if(ret != 0)
        {
            printf("Unable to create thread\n");
            return -1;
        }
    }
    
    for(i = 0; i < 4; i++)
    {
        pthread_join(TID[i],NULL);
    } 
    printf("Main thread terminated\n");
    
    pthread_exit(NULL);

    return 0;
}