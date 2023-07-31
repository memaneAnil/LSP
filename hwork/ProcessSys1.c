#include<stdio.h>
#include<pthread.h>

void * ThreadProc(void *ptr)
{
    int res = 0 , i =0;
    int size = *(int *)ptr;

    for(i = 1; i< size; i++)
    {
       res =res +*(((int*)ptr)+i);    
    }
    
    pthread_exit(res);   
}

int main()
{
    int arr[6]={6,10,20,30,40,50};
    int ret = 0;
    pthread_t TID;

    ret = pthread_create(&TID,NULL,ThreadProc,arr);

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