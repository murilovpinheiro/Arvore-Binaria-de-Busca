#ifndef FILE_H
#define FILE_H

    #include <stdio.h>
    #include <stdlib.h>

    typedef struct _noh ArvoreBB;

    void inicializar(ArvoreBB **a);
    int inserir_interativo(ArvoreBB **a, int chave, float val);
    int inserir_recursivo(ArvoreBB **a, int chave, float val);
    float buscar_interativo(ArvoreBB *a, int chave);
    float buscar_recursivo(ArvoreBB *a, int chave);
    void listar_elementos(ArvoreBB* a);


#endif
