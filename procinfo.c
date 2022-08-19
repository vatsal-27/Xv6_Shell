#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main(int argc, char *argv[])
{
    int loop=0;
    for(int i=0;i<strlen(argv[1]);i++)
    {
        if(argv[1][i]>='1' && argv[1][i]<='9')
        {
            continue;
        }
        else
        {
            loop=1;
        }

    }
    if(loop==0)
    {

    
    int pid=atoi(argv[1]);
    int openfile=numOpenFiles(pid);
    printf(2,"Numbers of files opened =%d \n",openfile);
    int memory=memAlloc(pid);
    printf(2,"Memory Allocated =%d\n",memory);
    getprocesstimedetails(pid);
    exit(0);
    }
    else{
        printf(2,"Illegal arguement\n");
        exit(-1);

    }
}

