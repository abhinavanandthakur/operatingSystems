//CSB18057
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <utmp.h>
#include <sys/utsname.h>

int main(int argc, char **argv){
char *name=argv[0];
int child=0;
int grandchild=0;
int status1,status2;
int child_pid=fork();
if (child_pid<0){
printf("Fork error\n");
sleep(30);
exit(1);
}

if (child_pid==0){
child++;
printf("From the clild:");
printf("Child of %s has PID %d  and PPId %d\n", name,getpid(),getppid());
int grandchild_pid=fork();
if(grandchild_pid<0){
printf("Fork error\n");
sleep(30);
exit(1);

}
if(grandchild_pid==0){
grandchild++;
printf("From the grandchild:");
printf("grandChild of %s has PID %d  and PPId %d\n", name,getpid(),getppid());
printf("The number of child is %d\nThe number of grandchild is %d\n",child,grandchild);
sleep(30);
exit(0);

}
else{
    wait(NULL);
printf("From the child:");
printf("I'm the child of %s,My child(grandchild) is %d\n",name,grandchild_pid);
sleep(30);
exit(0);

}



}
else{
wait(NULL);
printf("From the parent:");
printf("The parent is  %s. The child is %d\n",name,child_pid);

exit(0);


}


}
