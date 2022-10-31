#ifndef CONTADOR_CALORIASAVL_H
#define CONTADOR_CALORIASAVL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// estrutura dos dados
/************************************/
typedef struct dados
{
    int calorias;
    char alimentos[50];
} dados;
/************************************/

// estrutura da árvore
/************************************/
struct ARVORE_AVL
{
    int fb;
    dados dados;
    int altura;
    struct ARVORE_AVL *esquerda;
    struct ARVORE_AVL *direita;
};
typedef struct ARVORE_AVL avl;
/************************************/

/*--------------TRATA ARVORE--------------*/
void desenha(avl *arvore, int nivel);
int qtd_nodosAVL(avl *arvore);
avl *insereArvoreAVL(avl *arvore, dados info, int *ok, int *rotacao);
avl *Caso1(avl *arvore, int *ok, int *rotacao);
avl *Caso2(avl *arvore, int *ok, int *rotacao);
int fatorBalanceamento(avl *arvore);
avl *consultaAVL(avl *arvore, char alimentosDia[50], int *comparacoes);
int alturaAVL(avl *arvore);
/*--------------TRATA ARVORE--------------*/

/*--------------ROTAÇÕES--------------*/
avl *rotacaoEsquerda(avl *arvore);
avl *rotacaoDireita(avl *arvore);
avl *rotacaoDuplaEsquerda(avl *arvore);
avl *rotacaoDuplaDireita(avl *arvore);
/*--------------ROTAÇÕES--------------*/

#endif