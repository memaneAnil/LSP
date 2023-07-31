#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<fcntl.h>
char Buffer[512];
void * CountCap(void * ptr)
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
    //printf("cap = %d\n",cnt);
    pthread_exit(cnt);
}
void * CountSm(void * ptr)
{
    int ret = 0,cnt = 0, i = 0;
    //char Buffer[512];
    

    // while((ret = read(*(int *)ptr,Buffer,sizeof(Buffer))))
    // {
        
        for(i = 0;i < sizeof(Buffer) ; i++)
        {
            
            if(Buffer[i] >= 'a' && Buffer[i] <= 'z')
            {
                cnt++;
            }
        }
    // }
    
    pthread_exit(cnt);

}
int main()
{
    pthread_t TID[2];
    void (*fname[2]) ={CountCap,CountSm};
    char *name[2] = {"CountCap","CountSm"};
    int ret = 0;
    int ret1[2];
    int i = 0;
    int fd = 0;

    fd = open("Demo.txt",O_RDONLY);

    if(fd == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }


    for(i= 0;i<2;i++)
    {
        ret = pthread_create(&TID[i],NULL,fname[i],&fd);
        //printf("%ld\n",TID[i]);
        if(ret != 0)
        {
            printf("Unable to create thread\n");
            return -1;
        }
    }

    for(i = 0; i < 2; i++)
    {
        pthread_join(TID[i],&ret1[i]);
        printf("%s is : %d\n",name[i],ret1[i]);
    }
    
    return 0;

}