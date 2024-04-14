#include <stdio.h>
#include <stdlib.h>

/*)
    Elaborar um programa que leia uma matriz A do tipo vetor com 15 elementos inteiros. Construir
    uma matriz 8 de mesmo tipo, e cada elemento da matriz 8 deve ser o resultado da fatorial
    correspondente de cada elemento da matriz A. Apresentar as matrizes A e 8.
*/

int main()
{

    int A[15], B[15];
    int i, num, j, fatorial;


    for (i = 0; i < 15;i++){
        printf("\nDigite o %d numero: ", i);
        scanf("%d", &num);
        A[i] = num;

        fatorial = 0;
        for(j = 0; j <= num; j++){
            fatorial += j;
        }
        B[i] = fatorial;
    }

    for (i = 0; i < 15; i++){
        printf("\nSoma da fatorial de %d = %d", A[i], B[i]);
    }


    return 0;
}
