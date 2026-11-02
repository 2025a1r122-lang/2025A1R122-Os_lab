#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t p = fork();

    if (p == 0) {
        // Child Process
        printf("Child Running with PID: %d\n", getpid());
        sleep(2);
        printf("Child exiting...\n");
        exit(0);
    }
    else {
        // Parent Process
        printf("Parent waiting for child to terminate....\n");
        pid_t terminal_pid = wait(NULL);
        printf("Parent terminated child PID: %d\n", terminal_pid);
    }

    return 0;
}
