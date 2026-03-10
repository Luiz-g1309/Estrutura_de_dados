#include <stdio.h>
#include <stdlib.h>

void display(int var, int *ptr){

    printf("\n\n");
    printf("O conteudo da variavel é: %d\n", var);
    printf("O conteudo do endereço da variavel é: %p\n", &var);
    printf("O conteudo apontado pelo ponteiro(ptr) é:  %d\n", *ptr);
    printf("O conteudo do endereço apontado pelo ponteiro(ptr) é: %p\n", ptr);
    printf("O conteudo do endereço do ponteiro é: %p\n", &ptr);
}
void update(int *p){
    *p = *p +1;
}

int main(){
    int var = 25;
    int *ptr;
    ptr = &var;

    display(var,ptr);

    update(&var);

    display(var, ptr);

    printf("\n\nEnd.");
    while (1);
    return 0;
}
