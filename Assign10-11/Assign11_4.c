#include<stdio.h>
#include<pthread.h>

pthread_mutex_t mt;
int no = 10;

void * ThreadProc1(void * ptr)
{
    int i = 0;
    
    pthread_mutex_lock(&mt);

    for(i =  1; i<= 10; i++)
    {
        printf("Thread1 : %d\n",no++);
    }

    pthread_mutex_unlock(&mt);

    pthread_exit(NULL);
}
void * ThreadProc2(void * ptr)
{
    int i = 0;

    pthread_mutex_lock(&mt);

    for(i =10; i>= 1; i--)
    {
        printf("Thread2 : %d\n",no--);
    }

    pthread_mutex_unlock(&mt);

    pthread_exit(NULL);
}
int main()
{
    pthread_t TID[2];
    int ret = 0;
    void (*fname[2]) = {ThreadProc1,ThreadProc2};
    int i = 0;

    pthread_mutex_init(&mt,NULL);

    for(i=0; i< 2;i++)
    {
        ret = pthread_create(&TID[i],NULL,fname[i],NULL);

        if(ret != 0)
        {
            printf("Unable to create thread\n");
            return -1;
        }
    }
    
    for(i = 0; i < 2; i++)
    {
        pthread_join(TID[i],NULL);
    } 

    pthread_exit(NULL);

    return 0;
}