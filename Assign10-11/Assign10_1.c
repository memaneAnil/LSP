#include<stdio.h>
#include<pthread.h>
void * ThreadProc(void * ptr)
{
    printf("Inside new thread\n");
    pthread_exit(NULL);
}
int main()
{
    pthread_t TID;
    int ret = 0;

    ret = pthread_create(&TID,NULL,ThreadProc,NULL);

    if(ret != 0)
    {
        printf("Unable to create thread\n");
        return -1;
    }

    pthread_join(TID,NULL);

    pthread_exit(NULL);

    return 0;
}