#include <stdio.h>
#include <stdlib.h>

/*
    Elaborar um programa que leia oito elementos inteiros em uma matriz A do tipo vetor. Construir
    uma matriz 8 de mesma dimensão com os elementos da matriz A multiplicados por 3.
    O elemento 8[1] deve ser implicado pelo elemento A[1] * 3, o elemento 8[2] implicado pelo
    elemento A[2] * 3 e assim por diante, até 8. Apresentar a matriz 8.
*/

int main()
{
    int i;

    int A[8], B[8];






    for (i = 0; i < 8; i++){
        printf("\nDigite o %d numero: ", i);
        scanf("%d", &A[i]);

        B[i] = A[i] * 3;
    }

    for (i = 0; i < 8; i++){
        printf("\nValor %d * 3 = %d", i, B[i]);
    }

    return 0;
}
