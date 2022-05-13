#include "types.h"
#include "stat.h"
#include "user.h"

int stack[4096] __attribute__ ((aligned (4096)));
int x = 0;
int limit = 5;

int main(int argc, char *argv[]) {
    int tid = thread_create(stack);
    if (tid < 0)
        printf(2, "error while creating the thread");
    else if (tid == 0)
        while (x < limit) {
            x++;
            sleep(100);
        }
    else 
        while (x < limit) {
            printf(2, "x = %d", x);
            sleep(100);
        }
    exit();
}