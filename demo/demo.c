#define _GNU_SOURCE
#include <sys/wait.h>
#include <sys/utsname.h>
#include <sched.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define STACK_SIZE (1024*1024)

static char child_stack[STACK_SIZE];
char* const child_args[] = {
    "/bin/bash",
    NULL
};

int child_main(void* args) {
    printf("In child process!\n");
    sethostname("newhostname", 11);
    execv(child_args[0], child_args);
    return 1;
}

int main() {
    printf("Program start: \n");
    //int child_pid = clone(child_main, child_stack + STACK_SIZE, SIGCHLD, NULL);
    //int child_pid = clone(child_main, child_stack + STACK_SIZE, CLONE_NEWUTS | SIGCHLD, NULL);
    int child_pid = clone(child_main, child_stack + STACK_SIZE, CLONE_NEWUTS | CLONE_NEWPID | SIGCHLD, NULL);
    waitpid(child_pid, NULL, 0);
    printf("Program exit\n");
    return 0;
}
