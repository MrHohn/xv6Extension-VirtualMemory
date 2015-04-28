#include "types.h"
#include "user.h"

#define NUM_FORKS 500
// #define NUM_FORKS 10

int main(void)
{
    int *temp;
    int i, t1, t2;
    
    temp=malloc(40960); //required to allocate more pages to get better results
    *temp=0;

    printf(1,"Please wait!.....\n");
    t1 = uptime();
    t2 = 0;
    for(i = 0; i < NUM_FORKS; i++)
    {
        t1 = uptime();
        if(fork() == 0)
        {
            // printf(1, "I'm a child(fork), pid: %d\n", getpid());
            exit();
        }
        else
        {
           t2 += uptime() - t1;
           // printf(1, "wait for a child...\n");
           wait();
        }
    }
    printf(1, "Total uptime for %d forks is %d, average is %d...\n", NUM_FORKS, t2, t2 / 500);

    printf(1,"Please wait some more!.....\n");
    t1 = uptime();
    t2 = 0;
    for(i = 0; i < NUM_FORKS; i++)
    {
        t1 = uptime();
        if(cowfork() == 0)
        {
            // printf(1, "I'm a child(cowfork), pid: %d\n", getpid());
            exit();
        }
        else
        {
            t2 += uptime() - t1;
            // printf(1, "wait for a child...\n");
            wait();
        }
    }
    printf(1, "Total uptime for %d cowforks is %d, average is %d...\n", NUM_FORKS, t2, t2 / 500);

    exit();
}
