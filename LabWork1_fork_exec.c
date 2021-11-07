//
// Created by amartya on 20/09/21.
//

#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t processID, p;
    printf("------------------------\n");
    printf("Same Program, Same Code\n");
    printf("------------------------\n");
    // fork a child process
    p = fork();
    processID = getpid();

    printf("Output of fork: %d\n", p);
    printf("Process ID: %d\n", processID);

    if (p < 0) {
        // error occurred
        fprintf(stderr, "Fork Failed");
        return 1;
    }
    else if (p == 0) {
        // child process
        printf("-----------------------------\n");
        printf("Same Program, Different Code\n");
        printf("-----------------------------\n");
        execlp("/bin/ls","ls",NULL);
    }
    else {
        // parent process
        // parent will wait for the child to complete
        wait(NULL);
        printf("----------------------------------------------------------------------\n");
        printf("Before Terminating, the Parent waits for the child to finish its task\n");
        printf("----------------------------------------------------------------------\n");
        printf("Child Complete");
    }

    return 0;
}