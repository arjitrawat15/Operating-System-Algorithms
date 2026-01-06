// To create a child process using system call fork()
#include <stdio.h> 
#include <unistd.h> 
 
int main() { 
    int f = fork();   // Create child process 
 
    if (f < 0) 
    { 
        printf("Fork failed!\n"); 
    }  
    else if (f == 0) 
    { 
        // Child process 
        printf("Child process created successfully.\n"); 
    }  
    else  
    { 
        // Parent process 
        printf("Parent process is running.\n"); 
    } 
 
    return 0; 
}
