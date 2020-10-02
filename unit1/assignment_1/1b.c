//csb18057
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <utmp.h>
#include <sys/utsname.h>

void logs()
{
    struct utmp *login;
    setutent();
    login = getutent();
    printf("The logged in users are:");
    
    while (login)
    {
        if (login->ut_type == USER_PROCESS)
        {
            printf("\n%s", login->ut_user);
        }
        login = getutent();
    }
    printf("\n");
}


int main(int argc, char **argv){ 
char *name=argv[0];
char *name1;
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
logs(); 
exit(0);

}
else{
wait(NULL);
printf("From the child:");
printf("Child of %s has PID %d  and PPId %d\n", name,getpid(),getppid());
exit(0);

}


}
else{
wait(NULL);
printf("From the parent:");
printf("The parent is  %s and has PID %d\n",name,getpid());
exit(0);

}


}
