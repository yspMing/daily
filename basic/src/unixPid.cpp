#ifdef __linux__

#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

namespace basic{

static void unix_error(const char* msg)
{
    fprintf(stderr, "%s : %s\n", msg, strerror(errno));
    exit(0);
}

static pid_t Fork(void)
{
    pid_t pid;

    if((pid = fork()) < 0)
        unix_error("Fork error");

    return pid;
}

void runFork()
{
    pid_t pid;
    int x = 1;
    pid = Fork();

    if(0 == pid){ // child
        pid_t cpid = getpid();
        pid_t ppid = getppid();
        printf("child pid-> cpid: %d, ppid: %d, child:  x = %d\n",cpid, ppid, ++x);
        //exit current process in advance
        //exit(0);
    }
    else{
        //parent
        pid_t cpid = getpid();
        pid_t ppid = getppid();
        printf("parent pid-> cpid: %d, ppid: %d, child:  x = %d\n",cpid, ppid, --x);
        //exit(0);
    }

    //parent
    //printf("parent: x = %d\n", --x);
    //exit(0);
}

}

#endif