#include <stdio.h>
#include <stdlib.h>
#include "abb.h"

struct _noh{
    int chave;
    float valor;
    struct _noh* ptr_esq;
    struct _noh* ptr_dir;
};
//Elemento da arvore

void inicializar(ArvoreBB **a){
    (*a) = NULL;
    //apontando a raiz para NULL, iniciando uma Arvore Binaria de Busca Vazia
}
int inserir_interativo(ArvoreBB **a, int chave, float val){
    ArvoreBB** atual = a;
    //guardando o ponteiro que vamos usar
    while((*atual)!=NULL){ 
        if(chave < (*atual)->chave) atual = &((*atual)->ptr_esq);
        else if (chave > (*atual)->chave) atual = &((*atual)->ptr_dir);
        else if (chave == (*atual)->chave) return 0; //retornando caso encontre uma chave igual
    } //loop pra chegar na folha vazia correta

    ArvoreBB* ptr = (ArvoreBB*)malloc(sizeof(ArvoreBB));
    ptr->chave = chave;
    ptr->valor = val;
    ptr->ptr_esq = NULL;
    ptr->ptr_dir = NULL;
    (*atual) = ptr;
    return 1;
    //salvando
}

int inserir_recursivo(ArvoreBB **a, int chave, float val){
    //só inserimos em lugares vazio, sempre que estivermos apontando pra um lugar nulo
    // nos devemos inserir
    if((*a) == NULL){
        ArvoreBB* ptr = (ArvoreBB*)malloc(sizeof(ArvoreBB));
        ptr->chave = chave;
        ptr->valor = val;
        ptr->ptr_esq = NULL;
        ptr->ptr_dir = NULL;
        (*a) = ptr;
    }
    //basicamente os else são para mudar para qual lugar da arvore estamos apontando
    // caso a chave q desejamos inserir for menor que a chave que apontamos
    // repetimos esta função apontando para a esquerda, basicamente o mesmo no prox else if
    // mas para a direita
    else if( chave <(*a)->chave) inserir_recursivo(&((*a)->ptr_esq), chave, val);
    else if( chave >(*a)->chave) inserir_recursivo(&((*a)->ptr_dir), chave, val);
    else if( chave == (*a)->chave) return 0;
      //caso a chave que desejamos inserir for igual a alguma existente, não inserimos
    // pois chaves iguais não devem ser inseridas e retornamos 0, para erro 

    return 1;
}

float buscar_interativo(ArvoreBB *a, int chave){
    ArvoreBB* atual;
    int contador = 0;
    atual = a;
    //percorrendo a arvore da mesma maneira que antes utilizando um laço, para caso chave
    // seja encontrada retornamos o valor, caso não, e cheguemos em uma folha nula,
    //sai do laço e retorna erro

    while(atual!=NULL){
        contador++;
        if(chave < atual->chave) atual = atual->ptr_esq;
        else if (chave > atual->chave) atual = atual->ptr_dir;
        else if (chave == atual->chave){ printf("%d\n", contador);return atual->valor;}
    }
    
    printf("\nErro. Valor Inexistente.\n");
    return -99999.99;
}

float buscar_recursivo(ArvoreBB *a, int chave){
    ArvoreBB ab;
    //percorrendo a arvore recursivamente
    if (a!=NULL){
    if(chave < a->chave) return buscar_recursivo(a->ptr_esq, chave);

    else if(chave > a->chave) return buscar_recursivo(a->ptr_dir, chave);

    else if(chave == a->chave) return a->valor;
    }
    else {
        printf("\nErro. Valor Inexistente.\n");
        return -99999.99;
    }
}

void listar_elementos(ArvoreBB* a){
    if(a!=NULL){
    //listando elementos em ordem crescente, basicamente vamos para esquerda o maximo que der
    // até chegarmos no final, quando chegamos mostramos o elemento e vamos para direita, 
    // isso repete em todo Nó, quando terminamos um Nó voltamos para o anterior e repetimos
    listar_elementos(a->ptr_esq);

    printf("%d\n", a->chave);

    listar_elementos(a->ptr_dir);
    }
}
/*
int contar_elementos(ArvoreBB* a){
    if(a!=NULL){
    int conte = contar_elementos(a->ptr_esq);
    
    int contd = contar_elementos(a->ptr_dir);
    return conte + contd + 1;
    }
    return 0;
}
Função que fiz só para teste*/