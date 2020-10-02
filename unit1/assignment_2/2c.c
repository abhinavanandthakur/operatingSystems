#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *print_from_thread(void *arg)
{
	printf("Printing from thread\n");
	printf("HELLO WORLD\n");
	pthread_exit(NULL);
}
int main()
{
	pthread_t tid;
	pthread_create(&tid, NULL, print_from_thread, NULL); //new thread is created by the system call, user mode cannot create thread
	pthread_join(tid, NULL);							 // the calling function has been halted until the thread execution takes pkace
	return 0;
}