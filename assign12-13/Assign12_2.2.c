#include<stdio.h>
#include<unistd.h>
#include<sys/shm.h>


int main()
{
    key_t shmid;
    int key = 1234;
    char *ptr = NULL;
    int i = 0;
    
    shmid = shmget(key,100,0666);

    printf("key = %d\n",shmid);

    ptr = shmat(shmid,NULL,0);

    if(ptr != NULL)
    {
        printf("shared memory attach at Add : %p\n",ptr);
    }

    while(i < 10)
    {
        printf("%d\n",*ptr);
        ptr++;
        i++;
    }
    
    return 0;
}