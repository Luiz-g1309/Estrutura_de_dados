#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct dequeNode{
    int info;
    struct dequeNode* prox;
} DequeNode;

typedef struct deque{
    DequeNode *inicio;
    DequeNode *fim;
} Deque;

void exibirOpcoes(){
    printf(" Opções: \n");
    printf(" 1 - Push\n");
    printf(" 2 - Pop\n");
    printf(" 3 - Inject\n");
    printf(" 4 - Eject\n");
    printf(" 0 - Encerrar Programa\n");
    printf(" Informe a opção desejada\n");
}

void push (Deque *d, int A){
    DequeNode *novo;
    novo = (DequeNode*) malloc (sizeof(DequeNode));
    novo->info = A;
    novo->prox = d->inicio;
    if (d->inicio == NULL){
        d->inicio = novo;
        d->fim = novo; 
    }
    else{
        d->fim->prox = novo;
        d->fim = novo;
    }
}
int pop (Deque *d){
    DequeNode *temp = d->inicio;
    int valor = temp->info;
    d->inicio = temp->prox;
    if(d->inicio == NULL){
        d->fim = NULL;
    }
    free(temp);
    return valor;
}

void inject (Deque *d, int A){
    DequeNode *novo = (DequeNode*) malloc(sizeof(DequeNode));
    novo->info = A;
    novo->prox = NULL;

    if (d->fim == NULL) {    
        d->inicio = novo;
        d->fim = novo;
    } else {
        d->fim->prox = novo;  
        d->fim = novo;        
    }
}

int eject (Deque *d){
     DequeNode *temp = d->fim;
    int valor = temp->info;
    if (d->inicio == d->fim) {
        d->inicio = NULL;
        d->fim = NULL;
    } else {
        DequeNode *atual = d->inicio;
        while (atual->prox != d->fim)
            atual = atual->prox;
        atual->prox = NULL;
        d->fim = atual;
    }
    free(temp);
    return valor;
}

int isEmpty (Deque d) {
    if(d.inicio == NULL){
        return TRUE;
    }
    else{
        return FALSE;
    }
}

int isFull (Deque d) {
    return FALSE;
}

void initialize (Deque *d){
    d->inicio = NULL;
    d->fim = NULL;
}

void destroy(Deque *d) {
    DequeNode *atual = d->inicio;
    while (atual != NULL) {
        DequeNode *temp = atual->prox;
        free(atual);    
        atual = temp;
    }
    d->inicio = NULL;
    d->fim = NULL;
}

int main(){
    Deque minhaDeque;
    int op, num, retorno;
    initialize (&minhaDeque);
    do {
        exibirOpcoes();
        scanf("%d", &op);
        switch (op){
            case 1: if (isFull (minhaDeque) == FALSE){
                printf("Informe o valor: \n");
                scanf("%d", &num);
                push (&minhaDeque, num);
            }
            else{
                printf("Deque Cheia!\n");
            }
            break;
            case 2: if (isEmpty (minhaDeque) == FALSE){
                retorno = pop (&minhaDeque);
                printf("Valor retirado: %d\n", retorno);
            }
            else{
                printf("Deque Vazia!!\n");
            }
            break;
            case 3: if (isFull (minhaDeque) == FALSE){
                printf("Informe o valor: \n");
                scanf("%d", &num);
                inject (&minhaDeque, num);
            }
            else{
                printf("Deque cheia!! \n");
            }
            break;
            case 4: if (isEmpty (minhaDeque) == FALSE){
                retorno = eject(&minhaDeque);
                printf("Valor retirado: %d", retorno);
            }
            else{
                printf("Deque vazia!! \n");
            }
            break;
            case 0: destroy (&minhaDeque);
            printf("Bye Bye \n");
            break;
            default: printf("Opção Inválida \n");
        }
    }while (op != 0);
    return 0;
}
