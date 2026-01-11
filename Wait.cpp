//Write a program to create child process. Make sure that parent process waits until child has not completed its execution. 
#include <stdio.h> 
#include <unistd.h> 
#include <sys/types.h> 
#include <sys/wait.h> 
#include <stdlib.h> 
int main() { 
    int arr[10] = {1,2,3,4,5,6,7,8,9,10}; 
    int sum1 = 0, sum2 = 0;  
    int f1 = fork();     
    if (f1 < 0) 
    { 
        printf("Fork failed!\n"); 
        return 1; 
    }    
    else if (f1 == 0) 
    {  
        printf("Child 1 created (PID: %d)\n", getpid()); 
        for (int i = 0; i < 10; i++) 
        { 
            if (arr[i] % 2 == 0) 
            { 
                sum1 += arr[i]; 
            } 
        } 
        printf("Child 1 -> Sum of Even numbers: %d\n", sum1); 
        exit(0);   
    }    
    else 
    {   
        wait(NULL);  
        printf("Parent waited until Child 1 finished execution.\n"); 
        int f2 = fork();   
        if (f2 == 0) 
        { 
            printf("Child 2 created (PID: %d)\n", getpid()); 
            printf("Child 2 running even if parent exits.\n"); 
            sleep(3);  
            printf("Child 2 completed execution.\n"); 
            exit(0); 
        }        
        else 
        { 
            printf("Parent process is now exiting before Child 2 finishes.\n"); 
            exit(0);   
        } 
    } 
    return 0; 
} 
