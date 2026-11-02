# Experiment 10: Parent and Child Process Using `fork()` and `wait()`

## Aim
To create a child process using `fork()` and make the parent process wait until the child process terminates.

## Source Code

```c
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
```

## How to Compile and Run

Open a terminal in this folder and run:

```bash
gcc main.c -o experiment10
./experiment10
```

## Functions Used

- `fork()` – Creates a new child process.
- `getpid()` – Returns the process ID of the calling process.
- `sleep(2)` – Pauses the child process for 2 seconds.
- `wait(NULL)` – Makes the parent process wait for a child process to finish.
- `exit(0)` – Terminates the child process successfully.

## Note
The order of the first messages may vary because parent and child processes run independently. The parent continues after the child terminates.
