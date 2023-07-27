#include<stdio.h>
#include<unistd.h>

int main(int argc,char *argv[],char *envp[])
{
    int i = 0;

    for(i=0 ;envp[i]!=NULL;i++)
    {
        printf("%s\n",envp[i]);
    }

    return 0;
}