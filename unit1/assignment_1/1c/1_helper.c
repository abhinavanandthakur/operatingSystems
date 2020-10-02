//CSB18057
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc, char **argv){

    printf("I'm a user defined program with name %s and PID %d.I've occupied the process space of child process.\n",argv[0],getpid());
    exit(0);
}