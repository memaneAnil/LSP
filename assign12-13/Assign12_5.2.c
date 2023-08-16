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
    long int cnt = 0;
    struct message mobj; 

   msgid = msgget(key,0666|IPC_CREAT);

   printf("%d\n",msgid);

    while(i)
    {
        
        msgrcv(msgid,&mobj,sizeof(Buffer),cnt,0);

        printf("message : %s\n",mobj.some_text);

        if(strncmp(mobj.some_text,"end",3)== 0)
        {
            i = 0;
        }
    }

    exit(EXIT_SUCCESS);

   return 0; 
}
