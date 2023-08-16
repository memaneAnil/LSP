#include<stdio.h>
#include<unistd.h>

int main(int argc,char *argv[])
{

    printf("INside child process\n");
    printf("param : %d\n",atoi(argv[0]));

    write(atoi(argv[0]),"Marvellous Infosystem",21);

    return 0;

}