#include<stdio.h>
#include<fcntl.h>
#include<string.h>

int main(int argc,char * argv[])
{
    int fd = 0;
    char Buffer[20]={'\0'};
    if(argc !=2)
    {
        printf("Insufficient arguments\n");
        return -1;
    }

    fd = open(argv[1],O_WRONLY);

    if(fd == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }

    printf("Enter the string\n");

    scanf("%[^\n]s",Buffer);
   
    printf("%d",strlen(Buffer));
    

    write(fd,Buffer,strlen(Buffer));

    close(fd);

    return 0;
}