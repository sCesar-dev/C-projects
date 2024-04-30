#include <stdio.h>

//09 – Faça um programa que imprima os números inteiros entre um dado intervalo A e B.

int main()
{

    int A, B, cont;

    printf("\nDigite o numero A: ");
    scanf("%d", &A);

    cont = A;

    printf("\nDigite o numero B: ");
    scanf("%d", &B);


    while(cont != B){

        if (B < cont){
            cont--;

            if(cont != B){
                printf("\n%d", cont);

            }else{
                printf("\nOs numeros sao sequenciais, por isso nao existe elementos no meio.");
            }

        }else{
            cont++;
            if(cont != B){
                printf("\n%d", cont);
            }else{
                printf("\nOs numeros sao sequenciais, por isso nao existe elementos no meio.");
            }
        }
    }

    if (A == B){
            printf("\nOs numeros sao iguais, por isso nao existe elementos no meio.");
    }

}
