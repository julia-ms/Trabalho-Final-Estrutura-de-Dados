#include "contador_caloriasABP.h"

/*------------------------INSERE OS ELEMENTOS NA ARVORE------------------------*/
// base retirada dos exemplos no Moodle da disciplina
/*-----------------------------------------------------------------------------*/
abp *insereArvoreABP(abp *arvore, str_alimento comida)
{
    if (arvore == NULL)
    {
        arvore = (abp *)malloc(sizeof(abp));
        arvore->info = comida;
        arvore->esquerda = NULL;
        arvore->direita = NULL;
        return arvore;
    }
    else if (strcmp(comida.alimentos, arvore->info.alimentos) < 0) // compara string da arvore com a ultima string inserida
        arvore->esquerda = insereArvoreABP(arvore->esquerda, comida);
    else if (strcmp(comida.alimentos, arvore->info.alimentos))
        arvore->direita = insereArvoreABP(arvore->direita, comida);
    return arvore;
}

/*------------------------CONSULTA OS ELEMENTOS NA ARVORE------------------------*/
// base retirada dos exemplos no Moodle da disciplina
/*-------------------------------------------------------------------------------*/
abp *consultaABP(abp *arvore, char alimentos_dia[50], int *comp)
{
    if (arvore == NULL)
        return NULL;
    else
    {
        (*comp)++;
        if (strcmp(arvore->info.alimentos, alimentos_dia) == 0)
        {
            return arvore;
        }
        else
        {
            if (strcmp(arvore->info.alimentos, alimentos_dia) > 0)
                return consultaABP(arvore->esquerda, alimentos_dia, comp);
            else
                return consultaABP(arvore->direita, alimentos_dia, comp);
        }
    }
}

// CALCULA QUANTOS NODOS TEM NA ARVORE
int qtd_nodosABP(abp *arvore)
{
    if (arvore == NULL)
        return 0;
    else
        return 1 + qtd_nodosABP(arvore->esquerda) + qtd_nodosABP(arvore->direita);
}

// CALCULA ALTURA DA ARVORE
int alturaABP(abp *arvore)
{
    if (arvore == NULL)
    {
        return -1;
    }
    else
    {
        int esquerda = alturaABP(arvore->esquerda);
        int direita = alturaABP(arvore->direita);
        if (esquerda > direita)
            return esquerda + 1;
        else
            return direita + 1;
    }
}