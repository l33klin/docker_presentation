#define _GNU_SOURCE
#include <sys/wait.h>
#include <sys/utsname.h>
#include <sched.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mount.h>

#define STACK_SIZE (1024*1024)

static char child_stack[STACK_SIZE];
char* const child_args[] = {
    "/bin/bash",
    NULL
};

int child_main(void* args) {
    printf("In child process!\n");
    int mr = mount("none", "/proc", "proc", 0, NULL);
    if (mr != 0) {
	    exit(mr);
    }
    execv(child_args[0], child_args);
    return 1;
}

int main() {
    printf("Program start: \n");
    int child_pid = clone(child_main, child_stack + STACK_SIZE, CLONE_NEWPID | CLONE_NEWNS | SIGCHLD, NULL);
    
    waitpid(child_pid, NULL, 0);
    printf("Program exit, %d\n", child_pid);
    return 0;
}
