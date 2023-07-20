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

    fd = open("Demo.txt",O_RDONLY);
    if(fd == -1)
    {
        printf("Unable to create file\n");
        return -1;
    }
    read(fd,&sobj,sizeof(sobj));

    printf("Rollno = %d\n",sobj.rollno);
    printf("Sname = %s\n",sobj.sname);
    printf("Marks = %f\n",sobj.marks);
    printf("Age = %d\n",sobj.age);

    close(fd);

    return 0;
}