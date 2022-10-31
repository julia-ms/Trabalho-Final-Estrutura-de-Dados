// Trabalho final de estrutura de dados **contador de calorias**

// João Pedro Licks Corso - 00337569
// Júlia Mombach Silva - 00281023

/*Essa aplicação recebe um arquivo texto contendo os
alimentos ingeridos por um paciente e uma tabela de alimentos e suas calorias. A
tabela de calorias deverá ficar armazenada em uma árvore. */

// insere biblioteca
#include "biblioteca.h"

int main(int argc, char *argv[])
{
    //******declarações******//

    // ponteiros arvore
    avl *arvore = NULL;
    abp *arvoreABP = NULL;
    avl *auxiliar = NULL;
    abp *auxiliar1 = NULL;

    // dados
    dados info;
    str_alimento comida;
    char alimentosDia[50];
    int gramas;
    int ok;
    int caloriasConsumidas;
    int caloriasDiarias;
    char alimento_dia[50];
    int gramas_dia;
    int comparacoes = 0;
    int rotacao = 0;
    int comp = 0;

    // arquivos
    FILE *arqCalorias;
    FILE *arqConsumo;
    FILE *arqSaida;

    // arquivo para colocar na arvore
    arqCalorias = fopen(argv[1], "r");

    if (arqCalorias != NULL)
    {
        printf("Arquivo lido com sucesso!\n");
    }
    else
    {
        printf("Erro ao carregar o arquivo!\n");
    }
    // le arquivo e coloca os dados na arvore AVL
    while (fscanf(arqCalorias, "%[^;];%d\n", info.alimentos, &info.calorias) == 2)
    {
        for (int i = 0; i < sizeof(info.alimentos); i++)
        {
            info.alimentos[i] = tolower(info.alimentos[i]); // letras minusculas e maisculas sao tratadas iguais
            comida.alimentos[i] = tolower(comida.alimentos[i]);
        }
        arvore = insereArvoreAVL(arvore, info, &ok, &rotacao);
        arvoreABP = insereArvoreABP(arvoreABP, comida);
    }

    fclose(arqCalorias);

    int quantosAVL = qtd_nodosAVL(arvore);    // calculo do numero de nodos AVL
    int quantosABP = qtd_nodosABP(arvoreABP); // calculo do numero de nodos AVL
    int altura_ABP = alturaABP(arvoreABP);    // calculo da altura da ABP

    // aquivo do consumo diario para consulta
    arqConsumo = fopen(argv[2], "r");

    if (arqConsumo != NULL)
    {
        printf("Arquivo lido com sucesso!\n");
    }
    else
    {
        printf("Erro ao carregar o arquivo!\n");
    }

    // arquivo que escreve na saida
    arqSaida = fopen(argv[3], "w");

    // confere se os alimentos diarios estão na arvore AVL
    while (fscanf(arqConsumo, "%[^;];%d\n", alimentosDia, &gramas) == 2)
    {

        for (int i = 0; i < sizeof(alimentosDia); i++)
        {
            alimento_dia[i] = tolower(alimento_dia[i]);
            alimentosDia[i] = tolower(alimentosDia[i]); // letras minusculas e maisculas sao tratadas iguais
        }
        auxiliar1 = consultaABP(arvoreABP, alimentosDia, &comp);
        auxiliar = consultaAVL(arvore, alimentosDia, &comparacoes);
        caloriasConsumidas = ((auxiliar->dados.calorias * gramas) / 100); // calcula calorias consumidas de determinado alimento
        caloriasDiarias += caloriasConsumidas;                            // soma calorias no total do dia

        fprintf(arqSaida, "%dg de %s (%d calorias por 100g) = %d calorias\n", gramas, alimentosDia, auxiliar->dados.calorias, caloriasConsumidas);
    }

    fprintf(arqSaida, "\nTotal de %d calorias consumidas no dia.\n", caloriasDiarias);

    //****************************************************//
    //--------------------ESTATISTICAS--------------------//
    //****************************************************//

    fprintf(arqSaida, "\n\n======== ESTATISTICAS ABP ============\n");

    fprintf(arqSaida, "Numero de nodos: %d\n", quantosABP);

    fprintf(arqSaida, "Altura: %d\n", altura_ABP);

    fprintf(arqSaida, "Rotacoes: 0\n");

    fprintf(arqSaida, "Comparacoes: %d\n", comp);

    fprintf(arqSaida, "\n\n======== ESTATISTICAS AVL ============\n");

    fprintf(arqSaida, "Numero de nodos: %d\n", quantosAVL);

    fprintf(arqSaida, "Altura: %d\n", arvore->altura);

    fprintf(arqSaida, "Rotacoes: %d\n", rotacao);

    fprintf(arqSaida, "Comparacoes: %d\n", comparacoes);

    fclose(arqConsumo);
    fclose(arqSaida);

    return 0;
}
