#include<stdio.h>
#include<pthread.h>

void* ThreadProc(void * ptr)
{
    int i = 0;
    int size = *(int *)ptr;
    int ret = 0;

    printf("%d\n",*(((int *)ptr)+i));

    for(i = 1;i <= size;i++)
    {
        ret = ret + *(((int *)ptr)+i);
    }

    pthread_exit(ret);
}

int main()
{
    pthread_t TID;
    int ret = 0;
    struct number
    {
        int size;
        int arr[5];
    }obj={3,30,40,50};

    ret =pthread_create(&TID,NULL,ThreadProc,&obj);

    if(ret != 0)
    {
        printf("Unable to create thread\n");
        return -1;
    }

    pthread_join(TID,&ret);

    printf("Addition is : %d\n",ret);

    pthread_exit(NULL);

    return 0;
}