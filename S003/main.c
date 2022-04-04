#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>

#define NUM_THREADS 3

int SOMA = 0;
int MAX = 0;
int MIN = 2147483647;
int TAM;
int INDEX = 0;

void *Soma(void *number) {
    int *newNumber = (int *)number;
    int *backup = malloc(sizeof(int));
    INDEX++;

    SOMA += *newNumber;

    if (INDEX == TAM){
        *backup = SOMA / TAM;
    }

    return backup;
}

void *Max(void *number) {
    int *newNumber = (int *)number;
    int *backup = malloc(sizeof(int));

    if (*newNumber > MAX) {
        MAX = *newNumber;
    }

    *backup = MAX;

    return backup;
}

void *Min(void *number) {
    int *newNumber = (int *)number;
    int *backup = malloc(sizeof(int));

    if (*newNumber < MIN) {
        MIN = *newNumber;
    }

    *backup = MIN;

    return backup;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int *resMedia;
    int *resMenor;
    int *resMaior;

    scanf("%d",&TAM);
    
    int array[TAM];

    for (int i = 0;i<TAM;i++) {
        scanf("%d",&array[i]);
    }
    
    for (int i = 0;i<TAM;i++) {
        pthread_create(&(threads[0]), NULL, Soma,(void *)&(array[i]));
    }
    pthread_join(threads[0], (void *)&resMedia);
    printf("The average value is %d\n", *resMedia);
    
    for (int i = 0;i <TAM;i++){
        pthread_create(&(threads[1]), NULL, Max, &(array[i]));
    }
    pthread_join(threads[1], (void *)&resMaior);
    printf("The minimum value is %d\n", *resMaior);

    for (int i = 0;i <TAM;i++){
        pthread_create(&(threads[2]), NULL, Min, &(array[i]));
    }
    pthread_join(threads[2], (void *)&resMenor);
    printf("The maximum value is %d\n", *resMenor);
    
    return 0;
}