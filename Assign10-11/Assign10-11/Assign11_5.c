#include<stdio.h>
#include<pthread.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

char Buffer[512];
void * ThreadProc1(void *ptr)
{
    int ret = 0,cnt = 0, i = 0;
    
    while((ret = read(*(int *)ptr,Buffer,sizeof(Buffer))))
    {
        for(i = 0;i < ret ; i++)
        {
            if(Buffer[i] >= 'A' && Buffer[i] <= 'Z')
            {
                cnt++;
            }
        }
    }
    printf("Cap cnt : %d\n",cnt);
    pthread_exit(NULL);
}
void * ThreadProc2(void *ptr)
{
    int ret = 0,cnt = 0, i = 0;
    for(i = 0;i < sizeof(Buffer) ; i++)
    {
        if(Buffer[i] >= 'a' && Buffer[i] <= 'z')
        {
            cnt++;
        }
    }
    printf("sm cnt : %d\n",cnt);
    pthread_exit(NULL);
}
int main()
{
    pthread_t TID[2];
    int ret = 0;
    void *(*fptr[2])(void *) = {ThreadProc1,ThreadProc2};
    int i = 0,fd = 0;
    
    fd = open("Demo.txt",O_RDONLY);

    if(fd == -1)
    {
        printf("Unable to create file\n");
        return -1;
    }
    

    for(i = 0; i< 2; i++)
    {
        ret = pthread_create(&TID[i],NULL,fptr[i],&fd);

        if(ret != 0)
        {
            printf("Unable to create thread\n");
            return -1;
        }
    }

    for(i = 0; i< 2; i++)
    {
        pthread_join(TID[i],NULL);
    }
    return 0;
}