#include "types.h"
#include "stat.h"
#include "user.h"

#define PAGESIZE 4096

int thread_creator(void (*fn) (void *), void *arg) {
    // Alocate a memory with size (2 * PAGESIZE) to 
    // the new process from the parent's heap
    void *fptr = malloc(2 * PAGESIZE);
    void *stack;

    // failed to allocate memory
    if (fptr == 0)
        return -1;

    // page-align the memory
    int mod = (uint) fptr % PAGESIZE;
    stack = (!mod) ? fptr : fptr + (PAGESIZE - mod);

    // create the new thread using thread_create system call
    int tread_id = thread_create((void *) stack);

    if (thread_id < 0) // failed to create the new thread
        printf(1, "Thread creation failed.\n");
    else if (thread_id == 0) { // we are in the child process
        // call the function passed as argument
        (fn)(arg);
        // free the allocated memory and exit
        free(stack);
        exit();
    }

    return thread_id;
}