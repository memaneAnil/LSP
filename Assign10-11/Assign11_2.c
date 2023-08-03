#include<stdio.h>
#include<pthread.h>
#include<sched.h>

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

int main()
{
    pthread_attr_t tattr;
    pthread_t TID[4];
    int ret = 0;
    void* (*fptr[4])(void*) = {ThreadProc1,ThreadProc2};
    int i = 0;
    int newpriority = -15;
    struct sched_param param;

    pthread_attr_init(&tattr);


    for(i = 0; i< 2; i++)
    {
        ret = pthread_attr_getschedparam(&tattr,&param);
        printf("default priority : %d\n",param.sched_priority);
        ret = pthread_create(&TID[i],NULL,fptr[i],NULL);

        if(ret != 0)
        {
            printf("Unable to create thread\n");
            return -1;
        }

        
        ret = pthread_attr_setschedparam(&tattr,&param);
        param.sched_priority = newpriority;
        printf("new priority = %d\n",param.sched_priority);

    }
    
    for(i = 0; i < 2; i++)
    {
        pthread_join(TID[i],NULL);
    } 

    pthread_attr_destroy(&tattr);
    printf("Main thread terminated\n");
    
    pthread_exit(NULL);

    return 0;
}