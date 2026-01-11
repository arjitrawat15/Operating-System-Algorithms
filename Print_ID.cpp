//Write a program to print process Id's of parent and child process i.e. parent should print its own and its child process id.
#include <stdio.h>  
#include <stdlib.h>  
#include <sys/types.h>  
#include <unistd.h> 
 
int main(){ 
    int p = fork(); 
    if (p < 0)
    { 
        printf("Error\n"); 
        exit(0); 
    }
    else if (p == 0)
    { 
        printf("Child: My PID = %d, My Parent's PID = %d\n", getpid(), getppid()); 
    }  
    else
    { 
        printf("Parent: My PID = %d, My Child's PID = %d\n", getpid(), p); 
    } 
    return 0; 
}
