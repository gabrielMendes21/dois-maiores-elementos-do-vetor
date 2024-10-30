#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "interface.h"

int main(void)
{
    // Criação do vetor
    int size = QTD_ELEM - 1;
    int vetor[QTD_ELEM];

    // Gerar números aleatórios para o vetor
    gerarValoresAleatorios(vetor);

    // Imprimir o vetor
    // imprimirVetor(vetor);

    // Criar o heap a partir do vetor
    buildHeap(vetor, QTD_ELEM);

    // Imprimir o vetor
    imprimirVetor(vetor);

    // Mostra os dois maiores elementos do vetor
    determinarDoisMaioresElementos(vetor);
}

void gerarValoresAleatorios(int vetor[])
{
    srand(time(0));

    for (int i = 0; i < QTD_ELEM; i++)
    {
        vetor[i] = rand() / 100;
    }
}

void imprimirVetor(int vetor[])
{
    printf("=========================================\n");
    for (int i = 0; i < QTD_ELEM; i++)
    {
        printf("%i\n", vetor[i]);
    }
    printf("=========================================\n");
}

void sift(int i, int n, int vetor[])
{
    int indiceFilhoEsquerdo = 2 * i + 1;
    int indiceFilhoDireito = 2 * i + 2;
    int indiceMaior = i;

    if (indiceFilhoEsquerdo <= n && vetor[indiceFilhoEsquerdo] > vetor[indiceMaior])
        indiceMaior = indiceFilhoEsquerdo;

    if (indiceFilhoDireito <= n && vetor[indiceFilhoDireito] > vetor[indiceMaior])
        indiceMaior = indiceFilhoDireito;

    if (indiceMaior != i)
    {
        int aux = vetor[i];
        vetor[i] = vetor[indiceMaior];
        vetor[indiceMaior] = aux;
        sift(indiceMaior, n, vetor);
    }
}

void buildHeap(int vetor[], int n)
{
    for (int i = n / 2; i >= 0; i--)
    {
        sift(i, n - 1, vetor);
    }
}

void determinarDoisMaioresElementos(int vetor[])
{
    // O segundo maior elemento pode ser um dos filhos do elemento raíz do heap
    int maior2 = vetor[1] > vetor[2] ? vetor[1] : vetor[2];

    printf("Os dois maiores elementos do vetor são:\n%i\n%i", vetor[0], maior2);
}