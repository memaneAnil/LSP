#include<stdio.h>
#include<unistd.h>

extern char **environ;

int main(int argc,char *argv[],char *envp[])
{
    // int i = 0;

    // for(i=0 ;envp[i]!=NULL;i++)
    // {
    //     printf("%s\n",envp[i]);
    // }
    char **env = environ;

    for(;*env!=NULL;env++)
    {
        printf("%s\n",*env);
    }

    return 0;
}