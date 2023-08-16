#include<stdio.h>
#include<sys/msg.h>
#include<string.h>
#include<stdlib.h>

struct message
{
    long int type;
    char some_text[100];
};

int main()
{
    int key = 999;
    int msgid = 0;
    int i = 1;
    char Buffer[80];
    int cnt = 1;
    struct message mobj; 

   msgid = msgget(key,0666|IPC_CREAT);

   printf("%d\n",msgid);

    while(i)
    {
        printf("Enter the message\n");
        fgets(Buffer,80,stdin);
        mobj.type = cnt;
        strcpy(mobj.some_text,Buffer);
        if(msgsnd(msgid,&mobj,sizeof(Buffer),0))
        {
            fprintf(stderr, "msgsnd failed\n");
            exit(EXIT_FAILURE); 
        }

        if(strncmp(Buffer,"end",3)== 0)
        {
            i = 0;
        }
        cnt++;
    }

    exit(EXIT_SUCCESS);
   return 0; 
}
