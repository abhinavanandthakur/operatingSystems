//CSB18057
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <utmp.h>
#include <sys/utsname.h>

int main(int argc, char **argv)
{
    int child_pid = fork();
    if (child_pid < 0)
    {
        printf("Fork error\n");
        exit(1);
    }

    if (child_pid == 0)
    {
        printf("\nI am the child process with PID %d and my process space is going to be occupied by another program.\n", getpid());
        printf("The current program name using argument vecror argv[0] is %s.\n",argv[0]);
        char **args[] = {"./partc_helper", NULL};
        execv(args[0], args);
        exit(0);
    }
    else
    {

        int status_child;
        waitpid(child_pid, &status_child, 0);
        printf("I'm the parent process with PID %d.I will print the exit status of my child.\n", getpid());
        if (WIFEXITED(status_child))
        {
            int exit_status = WEXITSTATUS(status_child);
            printf("Exit status of the child with pid %d was %d.\n\n", child_pid, exit_status);
        }

        exit(0);
    }
}
