#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int timeTo;
    int timeIn;
    struct node *next;
} node;

typedef struct fila {
    node *head;
    node *tail;
}fila;

int empty_fila(fila *f){
    return f->head == NULL;
}

int *new_node(int info,int info2) {
    node *ptr = (node *)malloc(sizeof(node));
    ptr->timeTo = info;
    ptr->timeIn = info2;
    ptr->next = NULL;
    return ptr;
}

void push_fila(fila *f,int info,int info2, int index) {
    node *ptr = new_node(info,info2);
    if (index == 0){
        f->head = ptr;
        f->tail = ptr;
    } else {
        f->tail->next = ptr;
        f->tail = ptr;
    }
}

int remove_fila(fila *f) {
    node *ptr = f->head;
    int aux;

    aux = ptr->timeTo;
    f->head = ptr->next; 

    if (f->head == NULL) {
        f->tail = NULL;
    }

    free(ptr);

    return aux;
}

void print_fila(fila *f,int num){
    node *ptr = f->head;

    if (empty_fila(f)){
        printf("Processos finalizados");
    } else {
        for (int i = 0;i<num;i++) {
            printf("Tempo do processo : %d | Tempo de entrada %d \n",ptr->timeTo,ptr->timeIn);
            ptr = ptr->next;
        }
    }
        
}

void round_robin_process(fila *f, int q, int contador){
    node *ptr = f->head;

    if (ptr->timeTo > 0 && ptr->timeIn <= contador) {
        int newinfo = ptr->timeTo - q;
        printf("PROCESSO ATUAL ESTA EM : %d\n", ptr->timeTo);
        push_fila(f,newinfo,0,1);
        remove_fila(f);
    } else if (ptr->timeTo > 0 && ptr->timeIn > contador) {
        push_fila(f,ptr->timeTo,0,1);
        remove_fila(f);
    } else {
        remove_fila(f);
    }

}

int main() {
    fila *f1 =(fila *)malloc(sizeof(f1));
    f1->head = NULL;
    f1->tail = NULL;
    
    int num, q, time_in;
    int contador = 0;

    scanf("%d %d", &num, &q);

    int process[num];

    for (int i = 0;i < num;i++){
        scanf("%d %d",&time_in,&process[i]);
        push_fila(f1,process[i],time_in,i);
    }
    printf("\n");

    print_fila(f1,num);

    printf("comeco do round robin\n\n");

    while (!empty_fila(f1)) {
        round_robin_process(f1,q,contador);
        contador += q;
    }

    print_fila(f1,num);
}