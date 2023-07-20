#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#pragma pack(1)

struct student
{
    int rollno;
    char sname[20];
    float marks;
    int age;
};

int main(int argc,char * argv[])
{
    int fd = 0;
    struct student sobj;

    sobj.rollno = 11;
    strcpy(sobj.sname,"Atharv");
    sobj.marks = 95.95;
    sobj.age = 21;

    fd = creat("Demo.txt",0777);
    if(fd == -1)
    {
        printf("Unable to create file\n");
        return -1;
    }
    write(fd,&sobj,sizeof(sobj));

    close(fd);

    return 0;
}