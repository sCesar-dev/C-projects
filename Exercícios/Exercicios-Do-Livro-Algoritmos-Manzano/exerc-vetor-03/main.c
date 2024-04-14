#include <stdio.h>
#include <stdlib.h>

/*
Elaborar um programa que leia duas matrizes do tipo vetor para o armazenamento de nomes de
pessoas, sendo a matriz A com 20 elementos e a matriz 8 com 30 elementos. Construir uma
matriz C, sendo esta a junção das matrizes A e 8. Desta forma, a matriz C deve ter a
capacidade de armazenar 50 elementos. Apresentar os elementos da matriz C.
*/

int main()
{
    int i;
    char A[20], B[30], C[50];

    printf("\nDigite o nome do vetor A: ", i);
    scanf("%s", A);

    printf("\nDigite o nome do vetor B: ");
    scanf("%s", B);

    strcat(A,B);

    printf("%s", A);



    return 0;
}

//Não deu certo pois para inserir várias strings com espaços somente com struct ou usando
//o strcat, mas não iria atribuir esses caracteres nos 2 vetores ao vetor C. Também nao
//esta errado pois a questão é de um livro de algoritmos e estou somente adaptando para C
