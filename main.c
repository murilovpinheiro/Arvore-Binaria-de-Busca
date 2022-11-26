#include <stdio.h>
#include <stdlib.h>
#include "abb.h"


int main(){

    ArvoreBB* raiz;
    inicializar(&raiz);
    int i = 0;
    while(i<100){
        // Código simples de uma arvore binária de busca não balanceada em C
        if(inserir_interativo(&raiz, rand(), (float)rand()/(float)(RAND_MAX/10000))) i++;
    }
    listar_elementos(raiz);
    printf("%f",buscar_interativo(raiz, 27644));
}