#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>

#ifdef SIMPLES_TEST

int main(){
    printf("Count: 0\n");
    fork();
    printf("Count: 1\n");
    fork();
    printf("Count 2\n");
    fork();
    printf("Count 3 \n");
}

#else

int main() {
    int value = 0;
    pid_t pid;
    pid = fork();
    if (pid == 0){ //Executando no filho
        printf("No filho");
        //execlp("/bin/ls", "ls", "-la", NULL);
        return 1;
    }
    wait(&value);
    printf("No pai %d\n", pid);
    printf("No pai %d\n", WEXITSTATUS(value));
    return 0;
}

    // DOLAR MENOR INDICA DEPENDENCIA OU SEJA  O QUE VAI SER COMPILADO   E DOLAR ARROBA INDICA O ALVO QUE VAI SER CRIADO 

#endif