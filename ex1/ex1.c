// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    // Your code here
    int x = 10;
    int child = fork();

    if (child < 0){
        printf("Forked %d\n", x);
        x = 20;
        printf("Forked reassignment %d\n", x);
    } else {
        printf("Parent %d\n", x);
        x = 30;
        printf("Parent reassignment %d\n", x);
    }

    return 0;
}
