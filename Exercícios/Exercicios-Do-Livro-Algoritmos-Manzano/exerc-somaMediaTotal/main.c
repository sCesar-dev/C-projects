#include <stdio.h>
#include <stdlib.h>

int main()
{
    //variables
    int number, soma, cont;
    float media;

    //program start
    printf("Soma + media + Total\n");

    while(number >= 0){
        printf("Digite o %d n�mero: ", cont+1);
        scanf("%d", &number);
        if (number >= 0){
            soma += number;
            cont++;
        }
    }

    media = soma / cont;
    printf("\nSoma = %d \nM�dia = %f \nTotal de valores = %d", soma, media, cont);


    return 0;
}
