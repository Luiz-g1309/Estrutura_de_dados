#include <stdio.h>
#include <stdlib.h>     
#define TRUE 1
#define FALSE 0

typedef struct no{
    int info;
    struct no* prox;
}no;

typedef struct StackInt {
    no* topo;
} StackInt;

void exibirOpcoes () {
    printf ("Opções \n");
    printf ("1 - Empilhar \n");
    printf ("2 - Desempilhar \n");
    printf ("3 - Ver o topo \n");
    printf ("0 - Encerrar programa \n");
    printf ("Digite a opção desejada: ");
}

void push (StackInt *p, int v) { // empilhar
    no* novo;
    novo = (no*) malloc (sizeof(no));
    novo->info = v;
    novo->prox = NULL;
    if(p->topo == NULL){
        p->topo = novo;
    }
    else{
        novo->prox = p->topo;
        p->topo = novo;
    }
}

int pop (StackInt *p) { // desempilhar
    no* temp = p->topo;
    int valor = temp->info;
    p->topo = temp->prox;
    free(temp);
    return valor;
}

int top (StackInt p) {
    return p.topo->info;
}// ver topo
   

int isEmpty (StackInt p) {
    if(p.topo == NULL){
        return TRUE;
    }
    else{
        return FALSE;
    }
}// testar se está vazia
    

int isFull (StackInt p) {
    return FALSE;
}// testar se está cheia
   

void initialize (StackInt *p) {
    p->topo = NULL;                  
}

int main (){
    StackInt minhaPilha;
    int op, num;
    initialize (&minhaPilha);
    do {
        exibirOpcoes();
        scanf ("%d",&op);
        switch (op) {
            case 1: if (isFull(minhaPilha) == FALSE) {
                        printf ("Informe o valor que deseja empilhar: ");
                        scanf ("%d",&num);
                        push(&minhaPilha, num);
                    }
                    else {
                        printf ("Stack is full!!!! \n");
                    }
                    break;
            case 2: if (isEmpty(minhaPilha) == TRUE) {
                        printf ("Stack is empty!!!! \n");
                    }
                    else {
                        num = pop (&minhaPilha);
                        printf ("Valor desempilhado: %d \n", num);
                    } 
                    break;     
            case 3: if (isEmpty(minhaPilha) == TRUE) {
                        printf ("Stack is empty!!!! \n");
                    }
                    else {
                        printf ("O valor no topo da pilha é: %d \n", top (minhaPilha));
                    } 
                    break;
            case 0: printf ("Bye bye \n");
                    break;
            default: printf ("Opção inválida \n");                  
        }
    } while (op != 0);
    return 0;
}