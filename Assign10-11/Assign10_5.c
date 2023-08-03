#include<stdio.h>
#include<pthread.h>
void * ThreadProc(void * ptr)
{
    printf("Thread id : %ld\n",pthread_self());
    pthread_exit(NULL);
}
int main()
{
    pthread_t TID;
    int ret = 0;

    ret = pthread_create(&TID,NULL,ThreadProc,NULL);

    printf("Thread id : %ld\n",TID);
    if(ret != 0)
    {
        printf("Unable to create thread\n");
        return -1;
    }

    pthread_join(TID,NULL);

    pthread_exit(NULL);

    return 0;
}