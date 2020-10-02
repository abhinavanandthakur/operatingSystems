//CSB18057
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <utmp.h>
#include <sys/utsname.h>
#include <signal.h>
//signal handler
void my_handler(int signal)
{
    int child_pid = fork();// a child process is created by calling the system as user mode cannot do it
    if (child_pid < 0)
    {
        printf("Fork error\n");
        exit(1);
    }

    if (child_pid == 0)
    {
        //child process
        printf("\nI am the child process with PID %d and Parent's PID %d.\n", getpid(), getppid());
        exit(0);
    }

    else
    {
        //parent process
        wait(NULL);
        printf("I'm the parent process with PID %d and child's PID %d.\n", getpid(), child_pid);
        exit(0);
    }
}

int main()
{
    int val;
    printf("Enter 1 to print the PPID(Part A) and Enter 2 to kill the process(PartB):"); //press 1 for part A and 2 for part B
    scanf("%d", &val);
    // if the signal has to behave according to part A
    if (val == 1)
    {
        (void)signal(SIGINT, my_handler); /*upon pressing ctrl+c my_handler function will handle the signal accordingly.
        Again the system call will take place.
        */
        printf("\nPress CTRL+C to generate signal\n");
        while (1)
        {
            // nothing happens, just keeps the program running
        }
    }
    // if the signal has to behave according to part B
    else
    {
        printf("\nThe PID of Parent is %d.Kill it in another terminal by executing 2c.c\n", getpid());
        while (1)
        {
            //nothing happens, keeps the program running
        }
    }
}
