#include "types.h"
#include "user.h"
#include "signal.h"

int *p;

void handler(int signum, siginfo_t info)
{
	printf(1,"Handler called, error address is 0x%x\n", info.addr);
	printf(1, "info.type: %d\n", info.type);
	if(info.type == PROT_READ)
	{
		printf(1,"ERROR: Writing to a page with insufficient permission.\n");
		mprotect((void *) info.addr, sizeof(int), PROT_READ | PROT_WRITE);
	}
	else
	{
		printf(1, "ERROR: Didn't get proper exception, this should not happen.\n");
		exit();
	}
	printf(1, "exit handler\n");
}

int main(void)
{
	// signal(SIGSEGV, handler);
	signal(SIGSEGV, (sighandler_t)handler);
 	p = (int *) malloc(sizeof(int));
 	mprotect((void *)p, sizeof(int), PROT_READ);
 	printf(1, "back from mprotect in main\n");
 	*p=100;
 	printf(1, "after writing\n");
 	printf(1, "COMPLETED: value is %d, expecting 100!\n", *p);
 	
 	exit();
}
