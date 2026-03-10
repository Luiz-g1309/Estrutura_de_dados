#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct no{
    int info;
    struct no* prox;
} no;

typedef struct QueueInt{
    no* fim;
    no* inicio;
} QueueInt;

void exibirOpcoes () {  
    printf ("Opções \n");
    printf ("1 - Enfileirar \n");
    printf ("2 - Desenfileirar \n");
    printf ("3 - Ver o inicio \n");
    printf ("0 - Encerrar programa \n");
    printf ("Digite a opção desejada: ");
}

void enqueue (QueueInt *f, int v){
    no* novo;
    novo = (no*) malloc (sizeof(no));
    novo->info = v;
    novo->prox = NULL;
    if(f->fim == NULL){
        f->inicio = novo;
        f->fim = novo;
    }
    else{
        f->fim->prox = novo;
        f->fim = novo;
    }
}

int dequeue (QueueInt *f){
    no* temp = f->inicio;
    int valor = temp->info;
    f->inicio = temp->prox;
    if(f->inicio == NULL){
    f->fim = NULL;
}
    free(temp);
    return valor;
}

int inicial (QueueInt f){
    return f.inicio->info;
}

int isEmpty (QueueInt f) {
    if(f.inicio == NULL){
        return TRUE;
    }
    else{
        return FALSE;
    }
}

int isFull (QueueInt f) {
    return FALSE;
}

void initialize(QueueInt *f){
    f->fim = NULL;
    f->inicio = NULL;
}

int main (){
    QueueInt minhaFila;
    int op, num;
    initialize (&minhaFila);
    do {
        exibirOpcoes();
        scanf ("%d",&op);
        switch (op) {
            case 1: if (isFull(minhaFila) == FALSE) {
                        printf ("Informe o valor que deseja enfileirar: ");
                        scanf ("%d",&num);
                        enqueue(&minhaFila, num);
                    }
                    else {
                        printf ("Queue is full!!!! \n");
                    }
                    break;
            case 2: if (isEmpty(minhaFila) == TRUE) {
                        printf ("Queue is empty!!!! \n");
                    }
                    else {
                        num = dequeue (&minhaFila);
                        printf ("Valor desenfileirado: %d \n", num);
                    } 
                    break;     
            case 3: if (isEmpty(minhaFila) == TRUE) {
                        printf ("Queue is empty!!!! \n");
                    }
                    else {
                        printf ("O valor do inicio da fila é: %d \n", inicial (minhaFila));
                    } 
                    break;
            case 0: printf ("Bye bye \n");
                    break;
            default: printf ("Opção inválida \n");                  
        }
    } while (op != 0);
    return 0;
}

