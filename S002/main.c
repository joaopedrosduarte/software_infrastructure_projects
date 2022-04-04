#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main() {
    pid_t pid;
    int pipeFileDescriptor[2];
    int menssageInt = 9;
    int readMenssageInt;
    int returnPipe = pipe(pipeFileDescriptor);
    if (returnPipe == -1){
        printf("Erro to create pipe");
        return 1;
    }
    printf("Writing message Int on father process : \"%d\"\n", menssageInt);
    write(pipeFileDescriptor[0], &menssageInt,sizeof(int)*1);
    pid = fork();
    if (pid == 0){
        read(pipeFileDescriptor[1], &readMenssageInt,sizeof(int)*1);
        printf("Write menssage Int on child process : \"%d\"\n", menssageInt);
        return 1;
    }
    return 0;
}