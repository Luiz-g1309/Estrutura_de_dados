
#include <stdio.h>
#define TAM 10
#define TRUE 1
#define FALSE 0

typedef struct QueueInt {
    int valores [TAM];
    int frente; 
    int tras;
} QueueInt;

void exibirOpcoes () {
    printf ("Opções \n");
    printf ("1 - Enfileirar \n");
    printf ("2 - Desenfileirar \n");
    printf ("3 - Ver o inicio \n");
    printf ("0 - Encerrar programa \n");
    printf ("Digite a opção desejada: ");
}

void enqueue (QueueInt *p, int v){
    p->tras = p->tras + 1;
    p->valores[p->tras] = v;
}

int dequeue (QueueInt *p){
    int valor = p->valores[p->frente];
    p->valores[p->frente] = 0;
    (p->frente)++;
    return valor;
}

int front (QueueInt p){
    return p.valores[p.frente];
}

int isEmpty (QueueInt p) { 
    if (p.frente > p.tras) {
        return TRUE;
    }
    else {
        return FALSE;
    }
}

int isFull (QueueInt p) {  
    if (p.tras == TAM -1) {
        return TRUE;
    }
    else {
        return FALSE;
    }
}

void initialize (QueueInt *p) {
    int i;
    p->frente = 0;
    p->tras = -1;
    for (i = 0; i < TAM; i++) {
        p->valores[i] = 0;
    }
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
                        printf ("O valor do inicio da fila é: %d \n", front (minhaFila));
                    } 
                    break;
            case 0: printf ("Bye bye \n");
                    break;
            default: printf ("Opção inválida \n");                  
        }
    } while (op != 0);
    return 0;
}
