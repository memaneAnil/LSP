#include<stdio.h>
#include<dirent.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<string.h>

int main(int argc,char *argv[])
{
    DIR *dp = NULL,*dp1 = NULL,*dp2 = NULL;
    struct dirent *entry = NULL,*entry1 = NULL,*entry2 = NULL;
    struct stat sobj,sobj1;
    int fd = 0;
    char dpath[30],dpath1[50],dpath2[200];
    int cnt = 1;

    sprintf(dpath,"/%s/%s/%s",argv[0],argv[1],argv[2]);
    //printf("%s",dpath);
    // /home/anil/Desktop
    dp = opendir(dpath);

    if(dp == NULL)
    {
        printf("Unable to open directory\n");
        return -1;
    }
    fd = creat("demo.txt",0777);

    if(fd == -1)
    {
        printf("Unable to create file\n");
        return -1;
    }

    while((entry = readdir(dp))!= NULL)
    {
        if(strcmp(entry->d_name,".")!=0 && strcmp(entry->d_name,"..")!=0)
        sprintf(dpath1,"%s/%s",dpath,entry->d_name);

        stat(dpath1,&sobj);
        if(S_ISDIR(sobj.st_mode))
        {
            //printf("%s\n",dpath1);
            dp1 = opendir(dpath1);
            
            if(dp1 == NULL)
            {
                printf("Unable to open directory\n");
                return -1;
            }

            while((entry1 = readdir(dp1))!= NULL)
            {
                if(strcmp(entry->d_name,".")!=0 && strcmp(entry->d_name,"..")!=0)
                sprintf(dpath2,"%s/%s",dpath1,entry1->d_name);
                //printf("%s\t%s\n",dpath1,entry1->d_name);
                printf("%s\n",dpath2);
                stat(dpath2,&sobj1);
                if(S_ISDIR(sobj1.st_mode))
                {
                    dp2 = opendir(dpath2);
            
                    if(dp2 == NULL)
                    {
                        printf("Unable to open directory\n");
                        return -1;
                    }

                    while((entry2 = readdir(dp2))!= NULL)
                    {
                        //printf("%s\n",entry2->d_name);
                        write(fd,entry1->d_name,sizeof(entry1->d_name));
                    }
           
                }
            }
        
        }
       
    }
    closedir(dp);
    closedir(dp1);
    close(fd); 
    return 0;
}