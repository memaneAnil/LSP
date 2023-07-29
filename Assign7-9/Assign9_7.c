#include<stdio.h>
#include<unistd.h>
#include<string.h>

extern char **environ;
int main(int argc,char *argv[],char *envp[])
{
    // int i = 0;

    // for(i=0 ; envp[i]!=NULL;i++)
    // {
    //     if(strstr(envp[i],"HOME")||strstr(envp[i],"USERNAME"))
    //     printf("%s\n",envp[i]);
    // }

    char **env = environ;

    for(;*env!=NULL;env++)
    {
        if(strstr(*env,"HOME")||strstr(*env,"USERNAME"))
        printf("%s\n",*env);
    }
    return 0;
}