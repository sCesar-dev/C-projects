#include <stdio.h>

//09 – Faça um programa que imprima os números inteiros entre um dado intervalo A e B.

int main()
{

    int A, B, cont;

    printf("Digite o numero A: ");
    scanf("%d", &A);

    cont = A;

    printf("Digite o numero B: ");
    scanf("%d", &B);


    while(cont != B){

        if (B < cont){
            cont--;

            if(cont != B){
                printf("%d", cont);

            }else{
                printf("Os numeros sao sequenciais, por isso nao existe elementos no meio.");
            }

        }else{
            cont++;
            if(cont != B){
                printf("%d", cont);
            }else{
                printf("Os numeros sao sequenciais, por isso nao existe elementos no meio.");
            }
        }
    }

    if (A == B){
            printf("Os numeros sao iguais, por isso nao existe elementos no meio.");
    }

}
