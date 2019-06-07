// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    // Your code here 
    FILE *f = fopen("text.txt", "r+");
    int child = fork();

    if (child < 0){
        fprintf(stderr, "Error\n");
        exit(1);
    } else if (child == 0){
        printf("Forked\n");
        fprintf(f, "Reading from child\n");
    } else{
        printf("Parent \n");
        fprintf(f, "Reading from parent\n");
    }

    fclose(f);
    return 0;
}