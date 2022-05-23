#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
//#include <semaphore.h>
#include <dispatch/dispatch.h>

#define EATING 0
#define HUNGRY 1
#define THINKING 2

int state[5] = {THINKING};
dispatch_semaphore_t s[5];
dispatch_semaphore_t mutex;

/*
    DISPATCH PARA MAC
    SEM PARA LINUX
*/

//sem_t s[5];
//sem_t mutex;

void *filosofo(void*);
void take_fork(int);
void put_fork(int);
void eat(int);

int main() {
    pthread_t threads[5];
    int filosofos_id[5] = {0, 1, 2, 3, 4};

    //sem_init(&mutex,0 ,1);

    mutex = dispatch_semaphore_create(1);
    for (int i = 0;i < 5;i++){
        //sem_init(&s[i],0 ,0);
        s[i] = dispatch_semaphore_create(0);
    }

    for (int i = 0;i < 5;i++){
        pthread_create(&(threads[i]), NULL, filosofo, &filosofos_id[i]);
    }

    for (int i = 0;i < 5;i++){
        pthread_join(threads[i],NULL);
    }

    return 0;
}

void *filosofo(void* id){
    int *i = id;

    while(1) {
        sleep(1);
        take_fork(*i);
        sleep(1);
        put_fork(*i);
    }

}

void take_fork(int id) {
    //sem_wait(&mutex);
    dispatch_semaphore_wait(mutex, DISPATCH_TIME_FOREVER);
    state[id] = HUNGRY;
    printf("Filosofo %d esta com fome\n",id);

    if (state[(id+4)%5] != EATING && state[(id+1)%5] != EATING){
        state[id] = EATING;
        printf("Filosofo %d esta comendo\n",id);
    }
    //sem_post(&mutex);
    dispatch_semaphore_signal(mutex);

    if(state[id] == HUNGRY){
        //sem_wait(&s[id]);
        dispatch_semaphore_wait(s[id], DISPATCH_TIME_FOREVER);
    }
}

void put_fork(int id) {
    //sem_wait(&mutex);
    dispatch_semaphore_wait(mutex, DISPATCH_TIME_FOREVER);
    state[id] = THINKING;
    printf("Filosofo %d devolvel os garfos e voltou a pensar\n",id);

    eat((id+4)%5);
    eat((id+1)%5);
    //sem_post(&mutex);
    dispatch_semaphore_signal(mutex);
}

void eat(int id){

    if(state[id] == HUNGRY && state[(id+4)%5] != EATING && state[(id+1)%5] != EATING){
        state[id] == EATING;
        printf("Filosofo %d começou a comer\n",id);
        //sem_post(&s[id]);
        dispatch_semaphore_signal(s[id]);
    }

}
