#ifndef CONTADOR_CALORIASABP_H
#define CONTADOR_CALORIASABP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// estrutura dos dados
/************************************/
typedef struct str_alimento
{
    int calorias;
    char alimentos[50];
} str_alimento;
/************************************/

// estrutura da árvore
/************************************/
struct ARVORE_ABP
{
    str_alimento info;
    struct ARVORE_ABP *esquerda;
    struct ARVORE_ABP *direita;
};
typedef struct ARVORE_ABP abp;
/************************************/

/*--------------TRATA ARVORE--------------*/
abp *insereArvoreABP(abp *arvore, str_alimento comida);
abp *consultaABP(abp *arvore, char alimentosDia[50], int *comp);
int qtd_nodosABP(abp *arvore);
int alturaABP(abp *arvore);
/*--------------TRATA ARVORE--------------*/

#endif