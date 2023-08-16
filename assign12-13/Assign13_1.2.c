#include<stdio.h>
#include<unistd.h>

#define SIZE 512

int main(int argc,char *argv[])
{
    char Buffer[SIZE];
   
    printf("Enter the text\n");
    fgets(Buffer,80,stdin);

    write(atoi(argv[0]),Buffer,80);

    return 0;
}