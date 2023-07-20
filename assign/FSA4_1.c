#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>


int main(int argc,char * argv[])
{
    int no1 = 0, no2 = 0 ,res = 0;
    int fd = 0 ,fd1 =0;

    fd = open("Input.txt",O_RDONLY);
    dup2(fd,0);
    
    printf("Enter first number\n");
    scanf("%d",&no1);
    printf("Enter second number\n");
    scanf("%d",&no2);

    res = no1 + no2;

    fd1 = open("Output.txt",O_WRONLY);

    dup2(fd1,1);
    
    printf("Addition is : %d\n",res);
    
    
    return 0;
}