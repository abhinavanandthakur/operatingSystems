//This is a program to terminate the running process.
#include <sys/signal.h>
#include <stdio.h>
int main()
{
    int x;
    printf("Enter pid: ");
    scanf("%d", &x);
    printf("return_id %d\n", kill(x, SIGKILL)); // This will lead to a system call to terminate the process with the user given PID
    return 0;
}