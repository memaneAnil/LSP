#include<stdio.h>
#include<sys/stat.h>

void displayInfo(char *fname)
{
    struct stat sobj;

    stat(fname,&sobj);

    printf("File name : %s\n",fname);
    printf("Inode number : %ld\n",sobj.st_ino);
    printf("File size : %ld bytes\n",sobj.st_size);
    printf("Block size : %ld\n",sobj.st_blksize);
    printf("Number of links : %d\n",sobj.st_nlink);
    printf("Block count : %d\n",sobj.st_blocks);

}