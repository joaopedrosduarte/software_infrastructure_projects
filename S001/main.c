#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (){
    pid_t pid;
    pid = fork();

    if (pid == 0){
        exit(0);
    } else {
        printf("Pid of zombie process is : %d \n", pid);
    }
    
    while (1){
        sleep(11);
        return(0);
    }
}