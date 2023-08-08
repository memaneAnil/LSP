#include<stdio.h>
#include<pthread.h>

void* ThreadProc(void * ptr)
{
    int i = 0;
    int no = *(int *)ptr;
    int ret = 0;

    for(i = 2;i <= (no/2);i++)
    {
        if(no%i == 0)
        {
            break;
        }
    }

    if(i == (no/2)+1)
    {
        printf("Prime number\n");
    }
    else
    {
        printf("Not a prime number\n");
    }    

    pthread_exit(NULL);
}

int main()
{
    pthread_t TID;
    int ret = 0;
    int no = 0;

    printf("Enter the number\n");
    scanf("%d",&no);

    ret =pthread_create(&TID,NULL,ThreadProc,&no);

    if(ret != 0)
    {
        printf("Unable to create thread\n");
        return -1;
    }

    pthread_join(TID,NULL);

    pthread_exit(NULL);

    return 0;
}