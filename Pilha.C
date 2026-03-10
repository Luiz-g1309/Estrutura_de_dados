// TAD Stack de inteiros implementada utilizando um vetor para armazenar os dados empilhados
// Código desenvolvido durante a aula do dia 02-03-2026

#include <stdio.h>
#define TAM 10
#define TRUE 1
#define FALSE 0

typedef struct StackInt {
    int valores [TAM];
    int topo; 
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
    p->topo = p->topo + 1;
    p->valores[p->topo] = v;
}

int pop (StackInt *p) { // desempilhar
    int valor = p->valores[p->topo];
    p->valores[p->topo] = 0;
    (p->topo)--;
    return valor;
}

int top (StackInt p) {  // ver topo
    return p.valores[p.topo];
}

int isEmpty (StackInt p) { // testar se está vazia
    if (p.topo == -1) {
        return TRUE;
    }
    else {
        return FALSE;
    }
}

int isFull (StackInt p) {  // testar se está cheia
    if (p.topo == TAM -1) {
        return TRUE;
    }
    else {
        return FALSE;
    }
}

void initialize (StackInt *p) {
    int i;
    p->topo = -1;
    for (i = 0; i < TAM; i++) {
        p->valores[i] = 0;
    }
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